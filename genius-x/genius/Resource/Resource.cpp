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

#include "Resource.h"
#include "ComData.h"

USING_NS_GX;

static Resource* _resourceInstance=nullptr;

Resource* Resource::getInstance()
{
    if (_resourceInstance==nullptr) {
        _resourceInstance=new Resource();
    }
    
    return _resourceInstance;
}

Resource::Resource()
:_resourceCache(nullptr)
,_updateHandler(0)
,_addHandler(0)
,_isLoading(false)
{
    if (_resourceCache==nullptr) {
        _resourceCache= new ResourceCache();
        _resourceCache->addResourceDataDelegate(new GX::ComData(),ComData::_TYPE);
    }
}

Resource::~Resource()
{
    unaddResourceAsyncHandler();
    CCLOG("~Resource");
    unupdateResourceReferenceAsyncHandler();
}

void Resource::removeAllResources()
{
    Director::getInstance()->getTextureCache()->removeAllTextures();
    _resourceCache->removeAllData();
    
    _resourceReferences.clear();
}

void Resource::removeAllUnusedResources()
{
    Director::getInstance()->getTextureCache()->removeUnusedTextures();
    _resourceCache->removeUnusedData();
    
    //真实的运行时引用总是多于资源的引用计数，例如直接通过TextureCahce添加的纹理没有纳入到reference中
    //unusedresource一定是引用计数为0的资源
    __removeUnusedReference();
}

void Resource::removeResource(void* data)
{
    auto tex=static_cast<Texture2D*>(data);
    if (tex) {
        Director::getInstance()->getTextureCache()->removeTexture(tex);
    }
    else {
        _resourceCache->removeData((ResourceDataDelegate*)data);
    }
}

void Resource::removeResourceForKey(const std::string& filename)
{
    std::string fullpath=FileUtils::getInstance()->fullPathForFilename(filename);
    if (!_resourceCache->removeDataForKey(filename)) {
        Director::getInstance()->getTextureCache()->removeTextureForKey(filename);
    }
    
    //移除引用计数
    auto iter=_resourceReferences.find(fullpath);
    if (iter!=_resourceReferences.end()) {
        _resourceReferences.erase(iter);
    }
}

ResourceCache* Resource::getResourceCache()
{
    if (_resourceCache==nullptr) {
        _resourceCache= new ResourceCache();
        _resourceCache->addResourceDataDelegate(new GX::ComData(),ComData::_TYPE);
    }
    
    return _resourceCache;
}

void Resource::addResourceReference(const cocos2d::ValueMap& files)
{
    if (files.size()<1)
        return;
    
    for (auto iter=files.begin(); iter!=files.end(); iter++) {
        auto fullpath=cocos2d::FileUtils::getInstance()->fullPathForFilename(iter->first);
        if (!fullpath.empty()) {
            auto find=_resourceReferences.find(fullpath);
            if (find!=_resourceReferences.end()) {
                find->second++;
            }
            else {
                _resourceReferences.insert(std::make_pair(fullpath, 1));
                _resourceNotLoadded.push_back(fullpath);
                _resourceTypes.insert(std::make_pair(fullpath, iter->second.asString()));
            }
        }
    }
}

int Resource::getResourceReference(const std::string& file)
{
    auto fullpath=cocos2d::FileUtils::getInstance()->fullPathForFilename(file);
    
    auto find=_resourceReferences.find(fullpath);
    if (find!=_resourceReferences.end()) {
        return find->second;
    }

    return 0;
}

void Resource::removeResourceReference(const std::vector<std::string>& files)
{
    for (auto iter=files.begin(); iter!=files.end(); iter++) {
        auto fullpath=cocos2d::FileUtils::getInstance()->fullPathForFilename(*iter);
        if (!fullpath.empty()) {
            auto find=_resourceReferences.find(fullpath);
            if (find!=_resourceReferences.end()) {
                find->second--;
            }
        }
    }
}

void Resource::stopUpdateResource()
{
    
}


void Resource::addResourceAsyncHandler(const std::string& filename, int handler,const std::string& type)
{
    CCASSERT(!_isLoading, "some files is loading..");
    _isLoading=true;
    
    unaddResourceAsyncHandler();
    _addHandler=handler;
    
    auto callback=[this](void* v){
#if CC_ENABLE_SCRIPT_BINDING
        Ref* luaData=(Ref*)v;
        CommonScriptData data(_addHandler,"",luaData);
        ScriptEvent event(kCommonEvent,(void*)&data);
        ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
        
        unaddResourceAsyncHandler();
        return ;
#endif
    };
    
    addResourceAsync(filename, callback,type);
}

void Resource::unaddResourceAsyncHandler()
{
    if (0!=_addHandler) {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(_addHandler);
        _addHandler=0;
    }
}

void Resource::unupdateResourceReferenceAsyncHandler()
{
    if (0!=_updateHandler) {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(_updateHandler);
        _updateHandler=0;
    }
}


void Resource::updateResourceReferenceAsyncHandler(int handler)
{
    unupdateResourceReferenceAsyncHandler();
    _updateHandler=handler;
    
    auto callback=[this]{
#if CC_ENABLE_SCRIPT_BINDING
        CommonScriptData data(_updateHandler,"",this);
        ScriptEvent event(kCommonEvent,(void*)&data);
        CCLOG("updateResourceReferenceAsyncHandler callback lua.");
        ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
        return ;
#endif
    };
    
    updateResourceReferenceAsync(callback);
}

void Resource::updateResourceReferenceAsync(const std::function<void()>& callback)
{
    std::vector<std::string> _toAdd;
    
    //1,移除所有引用计数为0的
    for (auto iter=_resourceReferences.begin(); iter!=_resourceReferences.end(); iter++) {
        if (iter->second==0) {
            if (!_resourceCache->removeDataForKey(iter->first)) {
                Director::getInstance()->getTextureCache()->removeTextureForKey(iter->first);
            }
        }
        else {
            _toAdd.push_back(iter->first);
        }
    }
    
    //2,移除引用计数
    __removeUnusedReference();
    
    //3，异步加载新的资源（引用计数为1的）
    int* reference = new int();
    *reference= _resourceNotLoadded.size();
    
#if COCOS2D_DEBUG
    time_t* t=new time_t();
    time(t);
    int count=_resourceNotLoadded.size();
#endif
    
    //资源全部加载完毕
    auto completed=[reference,callback,this
#if COCOS2D_DEBUG 
                    ,t,count
#endif
                    ](){
        if ((*reference)==0) {
            delete reference;
#if COCOS2D_DEBUG
            time_t now;
            time(&now);
            
            CCLOG("we spend %f seconds to load {%d} files.",(float)difftime(now, *t),count);
            delete t;
#endif
            
            _resourceNotLoadded.clear();
            _isLoading=true;
            callback();
        }
    };
    
    CCLOG("we need to load %d files",(int)_resourceNotLoadded.size());
    
    if (_resourceNotLoadded.size()==0) {
        completed();
        return;
    }
    
    for (auto iter=_resourceNotLoadded.begin(); iter!=_resourceNotLoadded.end(); iter++) {
        auto type=_resourceTypes.find(*iter);
        if (type!=_resourceTypes.end()) {
            if (type->second=="Texture2D") {
                auto func=[reference,completed](Texture2D* tex){
                    (*reference)--;
                    if(*reference<1) {
                        completed();
                    }
                };
                Director::getInstance()->getTextureCache()->addImageAsync(*iter, func);
            }
            else {
                auto func=[reference,completed](void* data){
                    (*reference)--;
                    if(*reference<1){
                        completed();
                    }
                };
                _resourceCache->addResourceAsync(*iter,func,type->second);
            }
        }
    }
}

void Resource::__removeUnusedReference()
{
    for (auto iter=_resourceReferences.begin(); iter!=_resourceReferences.end();) {
        if (iter->second==0) {
            std::string key=iter->first;
            iter=_resourceReferences.erase(iter);
            
            //移除类型信息
            auto iter1=_resourceTypes.find(key);
            _resourceTypes.erase(iter1);
        }
        else {
            iter++;
        }
    }
}

void Resource::__addReference(const std::string& filename,const std::string& type)
{
    auto fullpath=FileUtils::getInstance()->fullPathForFilename(filename);
    auto iter=_resourceReferences.find(fullpath);
    if (iter==_resourceReferences.end()) {
        _resourceReferences.insert(std::make_pair(fullpath, 1));
        
        //添加类型信息
        _resourceTypes.insert(std::make_pair(fullpath,type));
    }
}

void Resource::__removeReference(const std::string& filename)
{
    auto fullpath=FileUtils::getInstance()->fullPathForFilename(filename);
    auto iter=_resourceReferences.find(fullpath);
    if (iter!=_resourceReferences.end()) {
        _resourceReferences.erase(fullpath);
    }
    
    //移除类型信息
    auto iter1=_resourceTypes.find(fullpath);
    if (iter1!=_resourceTypes.end()) {
        _resourceTypes.erase(iter1);
    }
}

