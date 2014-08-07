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

#ifndef __GX__Resource__
#define __GX__Resource__

#include "../GXMacros.h"
#include "ResourceCache.h"

NS_GX_BEGIN
USING_NS_CC;

/**
 * 统一的资源管理和加载的入口，包括Texture2D,ComData等
 *
 * 场景，关卡之间的资源贡献管理
 */
class Resource:public cocos2d::Ref
{
public:
    static Resource* getInstance();
    ResourceCache* getResourceCache();
    
    Resource();
    
    /*****资源管理***************************************************/
    
    void* addResource(const std::string& filename,const std::string& type="Texture2D")
    {
        CCASSERT(!filename.empty(),"filename cann't be nil.");
        
        void* t=nullptr;
        //Cocos2d-x Cache
        if (type=="Texture2D") {
             t=cocos2d::Director::getInstance()->getTextureCache()->addImage(filename);
        }
        else {
            t= getResourceCache()->addResource(filename,type);
        }
        
        //将直接加载的资源加入引用计数
        if (t!=nullptr) {
            __addReference(filename,type);
        }
        
        return t;
    }
    

    void addResourceAsyncHandler(const std::string& filename, int handler,const std::string& type="Texture2D");
    void unaddResourceAsyncHandler();

    void addResourceAsync(const std::string& filename, std::function<void(void*)> callback,const std::string& type="Texture2D")
    {
        CCASSERT(!filename.empty(),"filename cann't be nil.");
        
        //Cocos2d-x Cache
        if (type=="Texture2D") {
            auto func=[this,filename,callback,type](cocos2d::Texture2D* tex) {
                this->__addReference(filename,type);
                callback(tex);
            };
            
            Director::getInstance()->getTextureCache()->addImageAsync(filename,func);
        }
        else {
            auto func=[this, filename,callback,type](ResourceDataDelegate* data) {
                this->__addReference(filename,type);
                callback(data);
            };
            
            return getResourceCache()->addResourceAsync(filename,func,type);
        }
    }
    
    void removeAllResources();
    
    /**
     * 注意这里的判断以引用计数为准
     * 所有通过Resource加载和管理的资源都会加入引用计数管理
     */
    void removeAllUnusedResources();
    
    /**
     * 移除数据
     * 
     * @note 请尽量避免直接调用此方法，此方法对于移除Texture2D，没有找到对应的文件，因此不能移除引用计数
     */
    void removeResource(void* data);
    void removeResourceForKey(const std::string& filanem);

    
    
    /*****引用计数管理*************************************************/
    
    /**
     * 告知资源管理器将要使用哪些资源(对应资源引用计数加1)
     * 新增加的资源将在下一次调用updateResourceAsync的时候异步载入
     */
    
    void addResourceReference(const cocos2d::ValueMap& files);
    
    /**
     * 告知资源管理器哪些资源不再被使用(对应资源引用技术减1)
     * 当资源引用计数为0时将在下次调用updateResourceAsync的时候从内存中释放
     */
    void removeResourceReference(const std::vector<std::string>&);
    
    /** 查询某个资源的引用计数 */
    int getResourceReference(const std::string& file);
    
    /**
     * 如果之前通过addWillUseResource和removeUsedResource修改了资源，才会变得引用计数
     * 只有其引用计数为0，才会被移除
     * 资源还没有被加载，则加载资源
     */
    void updateResourceReferenceAsync(const std::function<void()>& callback);
    void updateResourceReferenceAsyncHandler(int handler);
    void unupdateResourceReferenceAsyncHandler();
    
    void stopUpdateResource();
    
protected:
    ~Resource();
    
    ResourceCache* _resourceCache;
    
    
    std::unordered_map<std::string,int> _resourceReferences;    //资源引用计数表
    std::unordered_map<std::string,std::string> _resourceTypes; //资源类型
    std::vector<std::string> _resourceNotLoadded;
    
private:
    /**
     * 没有通过addWillUseResource建立引用计数的资源，直接同步或异步加载资源时，仍然添加到引用计数表
     * 此方法仅共addResource之类的方法调用
     */
    void __addReference(const std::string& filename,const std::string& type);
    
    /**
     * 没有通过removeUsedResource去掉索引，直接释放资源时，去除引用计数
     * 此方法仅共removeResource之类的方法调用
     */
    void __removeReference(const std::string& filename);
    void __removeUnusedReference();
    
    int _addHandler;
    int _updateHandler;
    bool _isLoading;
};

NS_GX_END

#endif /* defined(__GX__Resource__) */
