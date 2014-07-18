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

#ifndef sg_ResourceDataDelegate_h
#define sg_ResourceDataDelegate_h

#include "../GXMacros.h"

NS_GX_BEGIN

/**
 * 一种自定义的数据类型，定义该种格式数据在内存中的存储格式以及提供解析方法
 *
 * 继承于Ref，需要记录每个数据对象被引用的情况
 * @refer: Texture2D
 * ResourceDataDelegate数据被存储在ResourceCache中
 */
class ResourceDataDelegate:public cocos2d::Ref
{
public:
    ResourceDataDelegate(const std::string& type)
    :_type(type)
    {
        
    }
    
    inline const std::string& getType() const{return _type;}
    
    virtual ResourceDataDelegate* cloneEmpty() const = 0;
    virtual bool initWithFile(const std::string& filename)=0;
    
private:
    std::string _type;
};

NS_GX_END

#endif
