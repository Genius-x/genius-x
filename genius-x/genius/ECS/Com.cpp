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

#include "Com.h"
#include "Entity.h"

USING_NS_GX;
USING_NS_CC;

GX::Com::Com(const std::string& type)
:_type(type)
,_isCustom(false)
#if CC_ENABLE_SCRIPT_BINDING
, _scriptHandler(0)
#endif
{
    _type=type;
}

GX::Com* GX::Com::create(const std::string type)
{
    auto com=new Com(type);
    com->_isCustom=true;
    
    return com;
}

GX::Com::~Com()
{
#if CC_ENABLE_SCRIPT_BINDING
    unregisterScriptHandler();
#endif
}

GX::Com* Com::getComByType(const std::string& type)
{
    if (_ownEntity) {
        return _ownEntity->getComByType(type);
    }
    
    return nullptr;
}



#if CC_ENABLE_SCRIPT_BINDING

void GX::Com::registerScriptHandler(int handler)
{
    unregisterScriptHandler();
    _scriptHandler=handler;
}

void GX::Com::unregisterScriptHandler(void)
{
    if (0!=_scriptHandler) {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(_scriptHandler);
        _scriptHandler=0;
    }
}

#endif

GX::Com* GX::Com::cloneEmpty() const
{
#if CC_ENABLE_SCRIPT_BINDING
    ComScriptData* custom=new ComScriptData();
    CommonScriptData data(_scriptHandler,"clone",custom);
    ScriptEvent event(kCommonEvent,(void*)&data);
    ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
    
    auto result=custom->getCom();
    custom->release();
    return result;
#endif
    
    return nullptr;
}

void GX::Com::initWithJson(const std::string& json)
{
#if CC_ENABLE_SCRIPT_BINDING
    ComScriptData* custom=new ComScriptData();
    //将json字符串传递给lua
    custom->setString(json);
    CommonScriptData data(_scriptHandler,"json",custom);
    ScriptEvent event(kCommonEvent,(void*)&data);
    ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&event);
    custom->release();
#endif
}