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

#include "FTUE.h"
#include "GameSystem.h"

USING_NS_GX;

FTUEManager* m_pFTUEInstance=NULL;
FTUEManager* FTUEManager::getInstance()
{
    if (!m_pFTUEInstance)
        m_pFTUEInstance=new FTUEManager();
    
    return m_pFTUEInstance;
}

FTUEManager::FTUEManager()
:_currentData(nullptr)
,_stillInFTUE(false)
{
    _FTUEData=new std::map<int, FTUEData*>();
    
    parserFTUEData();
    loadLocalFTUEData();
}

FTUEManager::~FTUEManager()
{
    for (std::map<int, FTUEData*>::iterator iter=_FTUEData->begin(); iter!=_FTUEData->end(); iter++) {
        delete iter->second;
    }
    
    delete _FTUEData;
}

bool FTUEManager::willDoFTUEInside(int ftueId)
{
    int index=ftueId;
    bool willDo=false;
    
    std::map<int, FTUEData*>::iterator iter=_FTUEData->find(index);
    if (iter!=_FTUEData->end()) {
        //1, 与等级无关，或者当前等级与所需要的等级相等
            //2,找到该FTUE对应分支的进度
            int progress=0;
            std::map<int,int>::iterator iter1=_progress.find(iter->second->rootId);
            if (iter1!=_progress.end()) {
                progress=iter1->second;
            }
            
            //该分支还没有进行
            if (iter->second->parentId==0)
            {
                //开始顶级分支
                return progress==0;
            }
            else
            {
                std::map<int, FTUEData*>::iterator iter3=_FTUEData->find(iter->second->parentId);
                if (iter!=_FTUEData->end()) {
                    //同一分支,其父级一定是当前进度
                    if (iter->second->rootId==iter3->second->rootId) {
                        return iter->second->parentId==progress;
                    }
                    else {
                        //分叉口，需要检查parent是否以执行,并且进度为0
                        return isftueFinished(iter3->second->ftueId)&&progress==0;
                    }
                }
            }
    }
    
    return willDo;
}

bool FTUEManager::willDoFTUE(int n,...)
{
    //1, find current ftueId
    va_list arguments;
    int type1=0;
    
    va_start(arguments, n);
    for (int i=0; i<n; i++) {
        type1=va_arg(arguments, int);
        if (willDoFTUEInside(type1))
            return true;
    }
    va_end(arguments);
    
    return false;
}

bool FTUEManager::isDoingFTUE(int type) const
{
    return _currentData&&_currentData->ftueId==type;
}

bool FTUEManager::isDoingFTUE() const
{
    return _currentData!=nullptr;
}

bool FTUEManager::showFTUE(int type,std::function<void(FTUEData*)> callback)
{
    
    int index=(int)type;
    
    //1, the next ftue
    if (!willDoFTUE(type))
        return false;
    
    _callback=callback;
    _stillInFTUE=false;
    
    //2. the right ftue
    std::map<int, FTUEData*>::iterator iter=_FTUEData->find(index);
    if (iter!=_FTUEData->end()) {
        _currentData=iter->second;
    
        if (_delegate) {
            _delegate->showFTUEUI(_currentData);
        }
        
        return true;
    }
    
    return false;
}

bool FTUEManager::showFTUE(std::function<void(FTUEData*)> callback,int n,...)
{
    //1, find current ftueId
    va_list arguments;
    int type1=0;
    
    va_start(arguments, n);
    for (int i=0; i<n; i++) {
        type1=va_arg(arguments, int);
        if (showFTUE(type1, callback)){
            return true;
        }
    }
    va_end(arguments);
    
    return false;
}

void FTUEManager::finishFTUE(int type,bool needKeepInFTUE/*=false*/)
{
    if (!_currentData) {
        return;
    }
    
    int index=(int)type;
    if (_currentData->ftueId!=index)
        return;
    
    _progress[_currentData->rootId]=index;
    
    //save to server
    GameSystem::getInstance()->saveFTUEToServer(_currentData);
    

    //保存到本地以容错
    //CCUserDefault::sharedUserDefault()->setIntegerForKey(CCString::createWithFormat("FTUE_KEY_%d",m_pCurrentData->rootId)->getCString(), index);
    
    //callback
    if (_callback) {
        std::function<void(FTUEData*)> tempCallback=_callback;
        FTUEData* temp=_currentData;
        _callback=nullptr;
        _currentData=NULL;
        _stillInFTUE=needKeepInFTUE;
        tempCallback(temp);
    }
    else
    {
        _currentData=NULL;
        _stillInFTUE=needKeepInFTUE;
    }
}

void FTUEManager::setStillInFTUE(bool inFTUE)
{
    if(!_currentData)
        _stillInFTUE=inFTUE;
}

void FTUEManager::parserFTUEData()
{

}

void FTUEManager::loadLocalFTUEData()
{
    std::map<int,bool> handledRoot;
    for (std::map<int, FTUEData*>::iterator iter=_FTUEData->begin(); iter!=_FTUEData->end(); iter++) {
        //找不到，没有处理
        if (iter->second->islocal&&handledRoot.find(iter->second->rootId)==handledRoot.end()){
            //int progress=CCUserDefault::sharedUserDefault()->getIntegerForKey(CCString::createWithFormat("FTUE_KEY_%d",iter->second->rootId)->getCString(),0);
            //setCurrentGroupIndex(progress, iter->second->rootId);
        }
    }
}

bool FTUEManager::canHandle(int n,...)
{
    //处于保持FTUE状态,只有新的FTUE才会改写此状态
    if (!_currentData&&_stillInFTUE) {
        return false;
    }
    
    bool result=true;
    
    if (_currentData) {
        result=false;
        
        va_list arguments;
        int type1;
        
        va_start(arguments, n);
        for (int i=0; i<n; i++) {
            type1=va_arg(arguments, int);
            
            //只有包含一个kFTUEMAX，则不能处理
            if (type1==FTUEManager::kFTUENone)
                return false;
            
            //只要包含一个即可处理
            if (type1==_currentData->ftueId)
                result=true;
        }
        va_end(arguments);
    }
    
    return result;
}

bool FTUEManager::isftueFinished(int ftueId)
{
    std::map<int, FTUEData*>::iterator iter=_FTUEData->find(ftueId);
    if (iter!=_FTUEData->end()) {
        int progress=0;
        std::map<int, int>::iterator iter1=_progress.find(iter->second->rootId);
        if (iter1!=_progress.end()) {
            progress=iter1->second;
        }
        
        if (progress==0) {
            return false;
        }
        
        if (ftueId==progress) {
            return true;
        }
        
        //ftueid对应的分支上必须能够找到progress，否则没有被执行
        iter=_FTUEData->find(iter->second->parentId);
        while (iter!=_FTUEData->end()) {
            if (progress==iter->first) {
                return true;
            }
            
            iter=_FTUEData->find(iter->second->parentId);
        }
    }
    
    return false;
}

void FTUEManager::setCurrentGroupIndex(int index,int root,bool force)
{
    if (force) {
        _lastProgress[root]=index;
        _progress[root]=index;
        return;
    }
    
    int local = 0;//=CCUserDefault::sharedUserDefault()->getIntegerForKey(CCString::createWithFormat("FTUE_KEY_%d",root)->getCString());
    //本地进度更新，使用本地数据
    if (local!=0&&index==0) {
        index=local;
    }
    
    _lastProgress[root]=index;
    
    std::map<int, FTUEData*>::iterator iter=_FTUEData->find(index);
    if (iter!=_FTUEData->end())
    {
        //跳跃或者恢复
        if (iter->second->groupId>=0)
        {
            std::map<int, FTUEData*>::iterator group=_FTUEData->find(iter->second->groupId);
            if (group!=_FTUEData->end())
            {
                //跳跃的步骤不在同一分支,表示起点
                if (iter->second->rootId!=group->second->rootId)
                    _progress[root]=0;
                else
                    _progress[root]=iter->second->groupId;
            }
            else
            {
                _progress[root]=0;
            }
        }
        else
        {
            _progress[root]=iter->second->ftueId;
        }
    }
    else
    {
        _progress[root]=index;
    }
}

void FTUEManager::resetAllLocalProgress()
{
    std::map<int,bool> handledRoot;
    for (std::map<int, FTUEData*>::iterator iter=_FTUEData->begin(); iter!=_FTUEData->end(); iter++) {
        //找不到，没有处理
        if (handledRoot.find(iter->second->rootId)==handledRoot.end()){
            handledRoot[iter->second->rootId]=true;
            //CCUserDefault::sharedUserDefault()->setIntegerForKey(CCString::createWithFormat("FTUE_KEY_%d",iter->second->rootId)->getCString(),0);
        }
    }
}

FTUEData* FTUEManager::getFTUEData(int id)
{
    std::map<int, FTUEData*>::iterator iter=_FTUEData->find(id);
    
    if (iter!=_FTUEData->end()) {
        return iter->second;
    }
    
    return nullptr;
}