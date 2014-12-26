/****************************************************************************
 Copyright (c) 2014 Elvis Qin
 Copyright (c) 2014 Soulgame Inc.
 
 http://www.genius-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "ResourceCache.h"

USING_NS_GX;

ResourceCache::ResourceCache()
: _loadingThread(nullptr)
, _asyncStructQueue(nullptr)
, _dataInfoQueue(nullptr)
, _needQuit(false)
, _asyncRefCount(0)
{
    
}

ResourceCache::~ResourceCache()
{
    for (auto iter=_resourceDatas.begin(); iter!=_resourceDatas.end(); ++iter) {
        iter->second->release();
    }
    
    for (auto iter=__unusedDataTemplate.begin(); iter!=__unusedDataTemplate.end(); iter++) {
        iter->second->release();
    }
}

ResourceDataDelegate* ResourceCache::addResource(const std::string& filename,const std::string& type)
{
    ResourceDataDelegate* result=nullptr;
    
    //全路径key
    std::string fullpath=cocos2d::FileUtils::getInstance()->fullPathForFilename(filename);
    if (fullpath.size()==0) {
        return nullptr;
    }
    
    //是否已加载
    auto iter=_resourceDatas.find(fullpath);
    if (iter!=_resourceDatas.end()) {
        result=iter->second;;
    }
    
    if (!result) {
        do {
            CCLOG("add resource date type: %s",type.c_str());
            
            auto iter1=__unusedDataTemplate.find(type);
            if (iter1!=__unusedDataTemplate.end()) {
                ResourceDataDelegate* data=iter1->second->cloneEmpty();
                if(!data->initWithFile(filename))
                {
                    CC_SAFE_RELEASE(data);
                    CCLOG("ResouceDataDelegate is error: %s",iter1->first.c_str());
                    break;
                }
                
                _resourceDatas.insert(std::make_pair(fullpath, data));
                result=data;
            }
            
        } while (0);
    }
    
    return result;
}

void ResourceCache::addResourceAsync(const std::string& filename,std::function<void(ResourceDataDelegate*)> callback,const std::string& type)
{
    ResourceDataDelegate* data=nullptr;
    std::string fullpath=FileUtils::getInstance()->fullPathForFilename(filename);
    auto iter=_resourceDatas.find(fullpath);
    if (iter!=_resourceDatas.end()) {
        data=iter->second;
    }
    
    if (data!=nullptr) {
        callback(data);
        return;
    }
    
    //lazy init
    if(_asyncStructQueue==nullptr)
    {
        _asyncStructQueue=new std::queue<AsyncStruct*>();
        _dataInfoQueue=new std::deque<DataInfo*>();
        
        _loadingThread=new std::thread(&ResourceCache::loadData,this);
        _needQuit=false;
    }
    
    if (_asyncRefCount==0) {
        Director::getInstance()->getScheduler()->schedule(schedule_selector(ResourceCache::addResourceAsyncCallback),this,0,false);
    }
    
    ++_asyncRefCount;
    
    AsyncStruct* async=new AsyncStruct(fullpath,callback,type);
    
    _asyncStructMutex.lock();
    _asyncStructQueue->push(async);
    _asyncStructMutex.unlock();
    
    _sleepCondition.notify_one();
}

void ResourceCache::addResourceAsyncCallback(float dt)
{
    std::deque<DataInfo*>* datasQueue=_dataInfoQueue;
    
    _dataInfoMutex.lock();
    if (_dataInfoQueue->empty()) {
        _dataInfoMutex.unlock();
    }
    else {
        DataInfo* dataInfo=datasQueue->front();
        datasQueue->pop_front();
        _dataInfoMutex.unlock();
        
        AsyncStruct* asyncStruct=dataInfo->asyncStruct;
        ResourceDataDelegate* data= dataInfo->data;
        const std::string& filename=asyncStruct->filename;
        if (data) {
            _resourceDatas.insert(std::make_pair(filename, data));
            data->retain();
            data->autorelease();
        }
        else {
            auto iter=_resourceDatas.find(asyncStruct->filename);
            if (iter!=_resourceDatas.end()) {
                data=iter->second;
            }
        }
        
        asyncStruct->callback(data);
        delete asyncStruct;
        delete dataInfo;
        
        --_asyncRefCount;
        if (0==_asyncRefCount) {
            Director::getInstance()->getScheduler()->unschedule(schedule_selector(GX::ResourceCache::addResourceAsyncCallback), this);
        }
    }
}

void ResourceCache::loadData()
{
    AsyncStruct* asyncStruct=nullptr;
    while (true) {
        std::queue<AsyncStruct*>* pQueue=_asyncStructQueue;
        _asyncStructMutex.lock();
        if (pQueue->empty()) {
            _asyncStructMutex.unlock();
            if (_needQuit) {
                break;
            }
            else{
                std::unique_lock<std::mutex> lk(_sleepMutex);
                _sleepCondition.wait(lk);
                continue;
            }
        }
        else
        {
            asyncStruct=pQueue->front();
            pQueue->pop();
            _asyncStructMutex.unlock();
        }
        
        ResourceDataDelegate* data=nullptr;
        bool loaded=false;
        
        auto iter=_resourceDatas.find(asyncStruct->filename);
        if(iter==_resourceDatas.end()){
            _dataInfoMutex.lock();
            DataInfo* dataInfo;
            size_t pos=0;
            size_t infoSize=_dataInfoQueue->size();
            
            for (;pos<infoSize;pos++) {
                dataInfo=(*_dataInfoQueue)[pos];
                if (dataInfo->asyncStruct->filename.compare(asyncStruct->filename)) {
                    break;
                }
            }
            _dataInfoMutex.unlock();
            if (infoSize==0||pos<infoSize) {
                loaded=true;
            }
        }
        
        if (loaded) {
            const std::string & filename=asyncStruct->filename;
            auto cloneData=__unusedDataTemplate.find(asyncStruct->resourceType);
            if (cloneData!=__unusedDataTemplate.end()) {
                data=cloneData->second->cloneEmpty();
                
                if(!data->initWithFile(filename)){
                    delete data;
                    CCLOG("load file: %s fail.",filename.c_str());
                    continue;
                }
                
                CCLOG("load file: %s success.",filename.c_str());
            }
            else {
                CCLOG("load file: %s fail. no parser.",filename.c_str());
                continue;
            }
        }
        
        DataInfo* dataInfo=new DataInfo();
        dataInfo->asyncStruct=asyncStruct;
        dataInfo->data=data;
        
        _dataInfoMutex.lock();
        _dataInfoQueue->push_back(dataInfo);
        _dataInfoMutex.unlock();
    }
}

void ResourceCache::removeAllData()
{
    for( auto it=_resourceDatas.begin(); it!=_resourceDatas.end(); ++it ) {
        (it->second)->release();
    }
    
    _resourceDatas.clear();
}

void ResourceCache::removeUnusedData()
{
    for( auto it=_resourceDatas.cbegin(); it!=_resourceDatas.cend(); /* nothing */) {
        ResourceDataDelegate *tex = it->second;
        if( tex->getReferenceCount() == 1 ) {
            CCLOG("GX: ResourceCache: removing unused data: %s", it->first.c_str());
            
            tex->release();
            _resourceDatas.erase(it++);
        } else {
            ++it;
        }
    }
}

bool ResourceCache::removeData(ResourceDataDelegate* data)
{
    return false;
}

bool ResourceCache::removeDataForKey(const std::string& key)
{
    if (_resourceDatas.size()<1) {
        return false;
    }
    
    auto it = _resourceDatas.find(key);
    
    if( it == _resourceDatas.end() ) {
        std::string fullpath = FileUtils::getInstance()->fullPathForFilename(key);
        it = _resourceDatas.find(fullpath);
    }
    
    if( it != _resourceDatas.end() ) {
        (it->second)->release();
        _resourceDatas.erase(it);
    }

    return false;
}

void ResourceCache::addResourceDataDelegate(ResourceDataDelegate* data,const std::string& type)
{
    if (__unusedDataTemplate.find(type)==__unusedDataTemplate.end()) {
        __unusedDataTemplate.insert(std::make_pair(type, data));
    }
}