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

#include "GameSystem.h"

USING_NS_GX;
USING_NS_CC;

GameSystem* GameSystem::sm_pSharedGameSystem = nullptr;

GameSystem::GameSystem():
	_haveInit(false), _ecs(nullptr)
{
    GX_ASSERT(! sm_pSharedGameSystem);
    sm_pSharedGameSystem = this;
    
    _ecs=new ECSManager();

    cocos2d::Director::getInstance()->getScheduler()->schedule(schedule_selector(GameSystem::update), this, 0.0f,false);
}

GameSystem::~GameSystem()
{
    GX_ASSERT(this == sm_pSharedGameSystem);
    sm_pSharedGameSystem = 0;
    
    cocos2d::Director::getInstance()->getScheduler()->unscheduleAllForTarget(_ecs);
}

void GameSystem::update(float dt)
{
    _ecs->update(dt);
}

GameSystem* GameSystem::getInstance()
{
    if (sm_pSharedGameSystem==nullptr) {
        new GameSystem();
    }
    
    if (!sm_pSharedGameSystem->_haveInit) {
        sm_pSharedGameSystem->init();
        sm_pSharedGameSystem->_haveInit=true;
    }
    
    GX_ASSERT(sm_pSharedGameSystem);
    return sm_pSharedGameSystem;
}

void GameSystem::init()
{
    
}