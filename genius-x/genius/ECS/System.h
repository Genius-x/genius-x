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

#ifndef __GX__System__
#define __GX__System__

#include "Com.h"
#include <future>

NS_GX_BEGIN

class ECSManager;
class Entity;
class ButtonCom;

/**
 * System表示一个行为的逻辑，它唯一对应一个Com
 * System被ECSManager根据Entity是否具有某个Com自动附加System，ECSManager在Com变动的时候通知System
 *
 * @note
 * 1, onInit()
 * 2, onAttached()
 * 3, onComsChanged()
 * 4, onDeattached()
 */
class System :public cocos2d::Ref
{
public:
    const static std::string DEFAULT_FIRST_TYPE;
    
    /**
     * 仅在脚本中使用
     */
    static System* create(const std::string& type,const std::string& firstType,int priority=0);
    
#if CC_ENABLE_SCRIPT_BINDING
    void registerScriptHandler(int handler);
    void unregisterScriptHandler(void);
    int  getScriptHandler(void){ return _scriptHandler ;}
#endif
    
    bool isTouchEnabled() const;
    void setTouchEnabled(bool value);
    
    Com* getComByType(const std::string&);
    
    inline ECSManager* getECSManager(){return _entityManager;}
    inline Entity* getEntity(){return _ownEntity;}
    
    /**
     * 获取被附加的Entity对应的Node(如果存在的话)
     */
    cocos2d::Node* getNode();
    
    virtual void registerWithTouchDispatcher() final {};

    virtual void setTouchMode(cocos2d::Touch::DispatchMode mode);
    virtual cocos2d::Touch::DispatchMode getTouchMode() const;
    virtual void setSwallowsTouches(bool swallowsTouches);
    virtual bool isSwallowsTouches() const;

protected:

    /**
     * NA lua,js
     */
    inline const std::string& getType() const{return _type;}
    
    /**
     * 响应Com的类型
     * ECSManager以此来决定当Com被添加或移除的时候要附加或移除哪些System
     *
     * 这是面向类型的基础
     * 每个System只能响应一个组件类型
     *
     * NA lua，js
     */
    inline const std::string& firstType(){return _firstType;}
    
    /**
     * 每个Entity中System被执行的顺序,它保证一些逻辑按正确的顺序被执行，尤其对同一Com读取数据
     *
     * NA lua,js
     */
    inline int getPriority(){return _priority;}
    
    /** 
     * 重要!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     *
     * 出于性能，Entity会自己缓存System
     * 所以，这里只需要return new MySystem(),不要复制任何数据，除非是对所有Entity有效的
     *
     * NA lua ,js
     */
    virtual System* cloneEmpty() const;
    
    /**
     * 模拟初始化,System实际上是被复制的，所以该方法不一定是在对象被构造之后
     * 该方法在每次被attach之前总会执行
     */
    virtual void onInit();
    
    /**
     * 被附加到一个Entity时触发
     * 这里可以执行事件订阅等事情，这里可以调用getNode，如果存在的话(NodeCom会始终被第一个附加)
     */
    virtual void onAttached();
    virtual void onDeattached();
    
    /**
     * 当attach到一个Entity之后，每帧被调用
     */
    virtual void update(float dt);
    
    /**
     * Entity有组件发生变动时触发
     *
     * System应该始终在这个时候获取需要使用的Com的引用，以减少每帧查找Com
     */
    virtual void onComsChanged();


    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);

    virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event){}
    virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event){}
    virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event){}
    virtual void onTouchesCancelled(const std::vector<cocos2d::Touch*>&touches, cocos2d::Event *unused_event){}

    //GUI
    //virtual void onClicked(ButtonCom*);

    bool _isCustom;
    std::string _type;
    std::string _firstType;
    int _priority;

protected:
    System(const std::string& type,const std::string&,int priority=0);
    virtual ~System();

private:

    int executeScriptTouchHandler(EventTouch::EventCode eventType, Touch* touch, Event* event);
    int executeScriptTouchesHandler(EventTouch::EventCode eventType, const std::vector<Touch*>& touches, Event* event);
    
    bool _isFree;
    int _scriptHandler;
    ccScriptType _scriptType;
    ECSManager* _entityManager;
    Entity* _ownEntity;
    
private:
    bool _touchEnabled;
    bool _accelerometerEnabled;
    bool _keyboardEnabled;
    cocos2d::EventListener* _touchListener;
    cocos2d::EventListenerKeyboard* _keyboardListener;
    cocos2d::EventListenerAcceleration* _accelerationListener;
    
    cocos2d::Touch::DispatchMode _touchMode;
    bool _swallowsTouches;
    
    friend ECSManager;
    friend Entity;
};


class SystemScriptData:public Ref
{
public:
    SystemScriptData(float delta=0.0)
    :_delta(delta)
    {
        
    }
    
    float getDelta(){return _delta;}
    
    void setSystem(System* sys){_clone=sys;}
    System* getSystem(){return _clone;}
    
private:
    float _delta;
    System* _clone;
};

NS_GX_END

#endif /* defined(__GX__System__) */
