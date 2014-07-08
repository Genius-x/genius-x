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

#include "DragCom.h"
USING_NS_GX;

std::string GX::DragCom::_TYPE="DragCom";

GX::DragCom::DragCom()
:GX::Com(_TYPE)
,_localZOrder(0)
,_globalZOrder(0)
,_localZOrderChanged(false)
,_globalZOrderChanged(false)
,_dragable(true)
,_clickable(true)
{
    
}

void DragCom::setLocalZOrder(int order)
{
    _localZOrderChanged=true;
    _globalZOrderChanged=false;
    _localZOrder=order;
}

void DragCom::setGlobalZOrder(int order)
{
    _globalZOrderChanged=true;
    _localZOrderChanged=false;
    _globalZOrder=order;
}

void DragCom::setTouchBehavior(bool draggable,bool clickable)
{
    _dragable=draggable;
    _clickable=clickable;
}

void GX::DragCom::initWithMap(rapidjson::Value& value)
{

}

GX::Com* GX::DragCom::cloneEmpty() const
{
    return new GX::DragCom();
}

bool DragCom::onBeginMove(Node* node,const Vec2 v)
{
#if CC_ENABLE_SCRIPT_BINDING
    ComScriptData* custom=new ComScriptData();
    custom->setNode(node);
    custom->setVec2(v);
    
    CommonScriptData data(_scriptHandler,"beginMove",custom);
    ScriptEvent event(kCommonEvent,(void*)&data);
    ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
    
    auto result=custom->getBool();
    custom->release();
    return result;
#else
    if (beginMove!=nullptr) {
        return beginMove()
    }
    
    return false;
#endif
}

void DragCom::onMoving(Node* node,const Vec2 v)
{
#if CC_ENABLE_SCRIPT_BINDING
    ComScriptData* custom=new ComScriptData();
    custom->setNode(node);
    custom->setVec2(v);
    
    CommonScriptData data(_scriptHandler,"moving",custom);
    ScriptEvent event(kCommonEvent,(void*)&data);
    ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
    
    custom->release();
#else
    if (moving!=nullptr) {
        beginMove()
    }
#endif
}

bool DragCom::onMoved(Node* node,const Vec2 v)
{
#if CC_ENABLE_SCRIPT_BINDING
    ComScriptData* custom=new ComScriptData();
    custom->setNode(node);
    custom->setVec2(v);
    
    CommonScriptData data(_scriptHandler,"moved",custom);
    ScriptEvent event(kCommonEvent,(void*)&data);
    ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
    
    auto result=custom->getBool();
    custom->release();
    return result;
#else
    if (moved!=nullptr) {
        return moved()
    }
    
    return false;
#endif
}

void DragCom::onMovebacked()
{
#if CC_ENABLE_SCRIPT_BINDING
    ComScriptData* custom=new ComScriptData();
    
    CommonScriptData data(_scriptHandler,"movebacked",custom);
    ScriptEvent event(kCommonEvent,(void*)&data);
    ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
    custom->release();
#else
    if (movebacked!=nullptr) {
        movebacked();
    }
#endif
}

void DragCom::onNodeClicked(Node* node)
{
#if CC_ENABLE_SCRIPT_BINDING
    ComScriptData* custom=new ComScriptData();
    custom->setNode(node);
    
    CommonScriptData data(_scriptHandler,"nodeClicked",custom);
    ScriptEvent event(kCommonEvent,(void*)&data);
    ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
    
    custom->release();
#else
    if (nodeClicked!=nullptr) {
        nodeClicked();
    }
#endif
}
