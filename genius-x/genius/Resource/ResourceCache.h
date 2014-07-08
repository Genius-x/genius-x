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

#ifndef __GX__ResourceCache__
#define __GX__ResourceCache__

#include "../GXMacros.h"
#include <unordered_map>
#include "ResourceDataDelegate.h"
#include <thread>

NS_GX_BEGIN

USING_NS_GX;
USING_NS_CC;

class Resource;

class ResourceCache : public Ref
{
public:
    /**
     * 一般被Resource构造和持有
     */
    ResourceCache();
    virtual ~ResourceCache();
    
    /**
     * 同步加载某一类资源，如果之前已经加载，则直接返回前者
     */
    ResourceDataDelegate* addResource(const std::string& filename,const std::string& type);
    
    /**
     * 异步加载资源，如果已经存在则直接回调
     */
    void addResourceAsync(const std::string& filename,std::function<void(ResourceDataDelegate*)> callback,const std::string& type);

    void removeAllData();
    void removeUnusedData();
    
    bool removeData(ResourceDataDelegate* data);
    bool removeDataForKey(const std::string& key);
    
    /**
     * 注册一个自定义数据类型及解析器
     */
    void addResourceDataDelegate(ResourceDataDelegate* data,const std::string& type);
public:
    struct AsyncStruct
    {
    public:
        AsyncStruct(const std::string& fn,std::function<void(ResourceDataDelegate*)> cb,const std::string& type)
        :filename(fn)
        ,callback(cb)
        ,resourceType(type){
            
        }
        
        std::string filename;
        std::string resourceType;
        std::function<void(ResourceDataDelegate*)> callback;
    };
    
protected:
    typedef struct _DataInfo
    {
        AsyncStruct* asyncStruct;
        ResourceDataDelegate* data;
    } DataInfo;
    
    std::thread* _loadingThread;
    
    std::queue<AsyncStruct*>* _asyncStructQueue;
    std::deque<DataInfo*>* _dataInfoQueue;
    
    std::mutex _asyncStructMutex;
    std::mutex _dataInfoMutex;
    
    std::mutex _sleepMutex;
    std::condition_variable _sleepCondition;
    
    bool _needQuit;
    int _asyncRefCount;
    
    /** 所有缓存数据 */
    std::unordered_map<std::string,ResourceDataDelegate*> _resourceDatas;
    
private:
    void addResourceAsyncCallback(float dt);
    void loadData();
    
    /**
     * 数据存储和解析类的模版
     * key：typeid(T).name()
     */
    std::map<std::string,ResourceDataDelegate*> __unusedDataTemplate;
    
    friend Resource;
};

NS_GX_END

#endif /* defined(__GX__ResourceCache__) */
