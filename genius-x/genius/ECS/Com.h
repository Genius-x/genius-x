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

#ifndef __GX__Com__
#define __GX__Com__

#include <iostream>
#include "../GXMacros.h"

NS_GX_BEGIN
USING_NS_CC;

class ECSManager;
class Entity;

/**
 * Com表示一个行为“类型”，所有行为逻辑都以此类型为准
 * Com只能包含纯数据
 *
 */
class Com:public cocos2d::Ref
{
public:
    inline const std::string& getType() const{return _type;}
    
    /**
     * 仅在脚本中使用，在cpp中应该始终继承Com类
     */
    static Com* create(const std::string type);
    
    Com* getComByType(const std::string&);
    inline Entity* getEntity(){return _ownEntity;}
    
    
#if CC_ENABLE_SCRIPT_BINDING
    void registerScriptHandler(int handler);
    void unregisterScriptHandler(void);
    int  getScriptHandler(void){ return _scriptHandler ;}
#endif
    
protected:
    Com(const std::string& type);
    virtual ~Com();
    
    /**
     * NA lua,js
     */
    virtual Com* cloneEmpty() const;
    
    /**
     * 根据配置文件设置属性值
     * 应该读取字典中的每一个值，key为属性名称
     * 
     * NA lua,js
     */
    virtual void initWithMap(rapidjson::Value&){};
    void initWithJson(const std::string&);

    int _scriptHandler;
    std::string _type;
    bool _isCustom;
    
private:
    Entity* _ownEntity;
    friend ECSManager;
};

#if CC_ENABLE_SCRIPT_BINDING

/**
 * 用于cpp回调lua时传递的参数，会被包装到CommonScriptData中
 */
class ComScriptData:public Ref
{
public:
    ComScriptData()
    :_clone(nullptr)
    ,_ref(nullptr)
    ,_bool(false)
    ,_float(0)
    ,_node(nullptr)
    ,_vec2(Vec2::ZERO)
    {
        
    }
    
    //lua 中cloneEmpty()
    void setCom(Com* data){_clone=data;}
    Com* getCom(){return _clone;}
    
    void setBool(bool b){_bool=b;}
    bool getBool(){return _bool;}
    
    void setFloat(float f){_float=f;}
    float getFloat(){return _float;}
    
    void setRef(Ref* r){_ref=r;}
    Ref* getRef(){return _ref;}
    
    void setNode(Node* n){_node=n;}
    Node* getNode(){return _node;}
    
    void setVec2(const Vec2& v){_vec2=v;}
    Vec2 getVec2(){return _vec2;}
    
    std::string getString(){return _str;}
    void setString(const std::string str){_str=str;}
    
private:
    Com* _clone;
    std::string _str;
    bool _bool;
    float _float;
    Ref* _ref;
    Node* _node;
    Vec2 _vec2;
};

#endif

NS_GX_END

#endif /* defined(__GX__Com__) */
