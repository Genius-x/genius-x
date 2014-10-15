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

#include "System.h"
#include "Entity.h"

USING_NS_GX;
USING_NS_CC;

const std::string System::DEFAULT_FIRST_TYPE="DEFAULT_FIRST_TYPE";

System::System(const std::string& type,const std::string& firstType,int priority)
:_type(type)
,_firstType(firstType)
,_priority(priority)
,_isFree(true)
,_entityManager(nullptr)
,_ownEntity(nullptr)
,_isCustom(false)
#if CC_ENABLE_SCRIPT_BINDING
, _scriptHandler(0)
#endif
{
#if CC_ENABLE_SCRIPT_BINDING
    ScriptEngineProtocol* engine = ScriptEngineManager::getInstance()->getScriptEngine();
    _scriptType = engine != nullptr ? engine->getScriptType() : kScriptTypeNone;
#endif
}

System::~System()
{
#if CC_ENABLE_SCRIPT_BINDING
    unregisterScriptHandler();
#endif
}

cocos2d::Node* System::getNode()
{
    if (getEntity()!=nullptr) {
        return getEntity()->getNode();
    }
    
    return nullptr;
}

GX::Com* System::getComByType(const std::string& type)
{
    if (_ownEntity) {
        return _ownEntity->getComByType(type);
    }
    
    return nullptr;
}

/// isTouchEnabled getter
bool System::isTouchEnabled() const
{
    return _touchEnabled;
}

/// isTouchEnabled setter
void System::setTouchEnabled(bool enabled)
{
    if (_touchEnabled != enabled)
    {
        _touchEnabled = enabled;
        if (enabled)
        {
            if (_touchListener != nullptr)
                return;
            
            if( _touchMode == Touch::DispatchMode::ALL_AT_ONCE )
            {
                // Register Touch Event
                auto listener = EventListenerTouchAllAtOnce::create();
                
                listener->onTouchesBegan = std::bind(&System::onTouchesBegan, this,std::placeholders::_1,std::placeholders::_2);
                listener->onTouchesMoved = std::bind(&System::onTouchesMoved, this,std::placeholders::_1,std::placeholders::_2);
                listener->onTouchesEnded = std::bind(&System::onTouchesEnded, this,std::placeholders::_1,std::placeholders::_2);
                listener->onTouchesCancelled = std::bind(&System::onTouchesCancelled, this,std::placeholders::_1,std::placeholders::_2);
                
                Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, getNode());
                _touchListener = listener;
            }
            else
            {
                // Register Touch Event
                auto listener = EventListenerTouchOneByOne::create();
                listener->setSwallowTouches(_swallowsTouches);
                
                listener->onTouchBegan = std::bind(&System::onTouchBegan, this,std::placeholders::_1,std::placeholders::_2);
                listener->onTouchMoved = std::bind(&System::onTouchMoved, this,std::placeholders::_1,std::placeholders::_2);
                listener->onTouchEnded = std::bind(&System::onTouchEnded, this,std::placeholders::_1,std::placeholders::_2);
                listener->onTouchCancelled = std::bind(&System::onTouchCancelled, this,std::placeholders::_1,std::placeholders::_2);
                
                Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, getNode());
                _touchListener = listener;
            }
        }
        else
        {
            Director::getInstance()->getEventDispatcher()->removeEventListener(_touchListener);
            _touchListener = nullptr;
        }
    }
}

void System::setTouchMode(Touch::DispatchMode mode)
{
    if(_touchMode != mode)
    {
        _touchMode = mode;
        
        if( _touchEnabled)
        {
            setTouchEnabled(false);
            setTouchEnabled(true);
        }
    }
}

void System::setSwallowsTouches(bool swallowsTouches)
{
    if (_swallowsTouches != swallowsTouches)
    {
        _swallowsTouches = swallowsTouches;
        
        if( _touchEnabled)
        {
            setTouchEnabled(false);
            setTouchEnabled(true);
        }
    }
}

Touch::DispatchMode System::getTouchMode() const
{
    return _touchMode;
}

bool System::isSwallowsTouches() const
{
    return _swallowsTouches;
}

System* System::create(const std::string& type,const std::string& firstType,int priority)
{
    return new System(type,firstType,priority);
}

#if CC_ENABLE_SCRIPT_BINDING

void System::registerScriptHandler(int handler)
{
    unregisterScriptHandler();
    _scriptHandler=handler;
}

void System::unregisterScriptHandler(void)
{
    if (0!=_scriptHandler) {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(_scriptHandler);
        _scriptHandler=0;
    }
}

#endif

GX::System* System::cloneEmpty() const
{
#if CC_ENABLE_SCRIPT_BINDING
    SystemScriptData* custom=new SystemScriptData();
    CommonScriptData data(_scriptHandler,"clone",custom);
    ScriptEvent event(kCommonEvent,(void*)&data);
    ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
    
    auto result=custom->getSystem();
    custom->release();
    return result;
#endif
    
    return nullptr;
}

void System::onInit()
{
#if CC_ENABLE_SCRIPT_BINDING
    if (_scriptType==kScriptTypeLua) {
        SystemScriptData* custom=new SystemScriptData();
        CommonScriptData data(_scriptHandler,"init",custom);
        ScriptEvent event(kCommonEvent,(void*)&data);
        ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
        custom->release();
    }
#endif
}

void System::onAttached()
{
#if CC_ENABLE_SCRIPT_BINDING
    if (_scriptType==kScriptTypeLua) {
        SystemScriptData* custom=new SystemScriptData();
        CommonScriptData data(_scriptHandler,"attached",custom);
        ScriptEvent event(kCommonEvent,(void*)&data);
        ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
        custom->release();
    }
#endif
}

void System::onDeattached()
{
#if CC_ENABLE_SCRIPT_BINDING
    if (_scriptType==kScriptTypeLua) {
        SystemScriptData* custom=new SystemScriptData();
        CommonScriptData data(_scriptHandler,"deattached",custom);
        ScriptEvent event(kCommonEvent,(void*)&data);
        ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
        custom->release();
    }
#endif
}

void System::update(float dt)
{
#if CC_ENABLE_SCRIPT_BINDING
    if (_scriptType==kScriptTypeLua) {
        SystemScriptData* custom=new SystemScriptData(dt);
        CommonScriptData data(_scriptHandler,"update",custom);
        ScriptEvent event(kCommonEvent,(void*)&data);
        ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
        custom->release();
    }
#endif
}

void System::onComsChanged()
{
#if CC_ENABLE_SCRIPT_BINDING
    if (_scriptType==kScriptTypeLua) {
        SystemScriptData* custom=new SystemScriptData();
        CommonScriptData data(_scriptHandler,"changed",custom);
        ScriptEvent event(kCommonEvent,(void*)&data);
        ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
        custom->release();
    }
#endif
}

void System::onEntityEvent(const std::string& eventName)
{
#if CC_ENABLE_SCRIPT_BINDING
    if (_scriptType==kScriptTypeLua) {
        SystemScriptData* custom=new SystemScriptData();
        CommonScriptData data(_scriptHandler,eventName.c_str(),custom);
        ScriptEvent event(kCommonEvent,(void*)&data);
        ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
        custom->release();
    }
#endif
}

bool System::onTouchBegan(Touch *touch, Event *event)
{
#if CC_ENABLE_SCRIPT_BINDING
    if (kScriptTypeLua == _scriptType)
    {
        return executeScriptTouchHandler(EventTouch::EventCode::BEGAN, touch, event) == 0 ? false : true;
    }
#endif
    CC_UNUSED_PARAM(event);
    CCASSERT(false, "System#ccTouchBegan override me");
    return false;
}

void System::onTouchMoved(Touch *touch, Event *event)
{
#if CC_ENABLE_SCRIPT_BINDING
    if (kScriptTypeLua == _scriptType)
    {
        executeScriptTouchHandler(EventTouch::EventCode::MOVED, touch, event);
        return;
    }
#endif
    
    CC_UNUSED_PARAM(event);
}

void System::onTouchEnded(Touch *touch, Event *event)
{
#if CC_ENABLE_SCRIPT_BINDING
    if (kScriptTypeLua == _scriptType)
    {
        executeScriptTouchHandler(EventTouch::EventCode::ENDED, touch, event);
        return;
    }
#endif
    
    CC_UNUSED_PARAM(event);
}

void System::onTouchCancelled(Touch *touch, Event *event)
{
#if CC_ENABLE_SCRIPT_BINDING
    if (kScriptTypeLua == _scriptType)
    {
        executeScriptTouchHandler(EventTouch::EventCode::CANCELLED, touch, event);
        return;
    }
#endif
    
    CC_UNUSED_PARAM(event);
}

/*
 
 void CustomSystem::onTouchesBegan(const std::vector<Touch*>& touches, Event *event)
 {
 #if CC_ENABLE_SCRIPT_BINDING
 if (kScriptTypeLua == _scriptType)
 {
 executeScriptTouchesHandler(EventTouch::EventCode::BEGAN, touches, event);
 return;
 }
 #endif
 CC_UNUSED_PARAM(event);
 }
 
 void CustomSystem::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
 {
 #if CC_ENABLE_SCRIPT_BINDING
 if (kScriptTypeLua == _scriptType)
 {
 executeScriptTouchesHandler(EventTouch::EventCode::MOVED, touches, event);
 return;
 }
 #endif
 
 CC_UNUSED_PARAM(event);
 }
 
 void CustomSystem::onTouchesEnded(const std::vector<Touch*>& touches, Event *event)
 {
 #if CC_ENABLE_SCRIPT_BINDING
 if (kScriptTypeLua == _scriptType)
 {
 executeScriptTouchesHandler(EventTouch::EventCode::ENDED, touches, event);
 return;
 }
 #endif
 CC_UNUSED_PARAM(event);
 }
 
 void CustomSystem::onTouchesCancelled(const std::vector<Touch*>& touches, Event *event)
 {
 #if CC_ENABLE_SCRIPT_BINDING
 if (kScriptTypeLua == _scriptType)
 {
 executeScriptTouchesHandler(EventTouch::EventCode::CANCELLED, touches, event);
 return;
 }
 #endif
 CC_UNUSED_PARAM(event);
 }
 
 */

int System::executeScriptTouchHandler(EventTouch::EventCode eventType, Touch* touch, Event* event)
{
#if CC_ENABLE_SCRIPT_BINDING
    if (kScriptTypeLua == _scriptType)
    {
        TouchScriptData data(eventType, this, touch, event);
        ScriptEvent scriptEvent(kTouchEvent, &data);
        return ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&scriptEvent);
    }
#endif
    //can not reach it
    return 0;
}

int System::executeScriptTouchesHandler(EventTouch::EventCode eventType, const std::vector<Touch*>& touches, Event* event)
{
#if CC_ENABLE_SCRIPT_BINDING
    if (kScriptTypeLua == _scriptType)
    {
        TouchesScriptData data(eventType, this, touches, event);
        ScriptEvent scriptEvent(kTouchesEvent, &data);
        return ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&scriptEvent);
    }
#endif
    return 0;
}

