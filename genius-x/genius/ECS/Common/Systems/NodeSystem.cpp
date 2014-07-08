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

#include "NodeSystem.h"
#include "../Components/NodeCom.h"

GX::NodeSystem::NodeSystem()
:GX::System("NodeSystem",GX::NodeCom::_TYPE)
{
    
}

GX::System* GX::NodeSystem::cloneEmpty() const
{
    return new GX::NodeSystem();
}

void GX::NodeSystem::onInit()
{
    
}

//ToDo: 向Statistics统计纹理使用
void GX::NodeSystem::onAttached()
{
    _node=(NodeCom*)getComByType(NodeCom::_TYPE);
    _node->node->setUserData(getEntity());
}

void GX::NodeSystem::onDeattached()
{
    //_node->node->removeFromParent();
}

void GX::NodeSystem::update(float dt)
{
    
}

void GX::NodeSystem::onComsChanged()
{
    
}