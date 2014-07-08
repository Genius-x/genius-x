//
//  ProgressSystem.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "genius-x.h"
#include "ProgressSystem.h"
#include "../Coms/ProgressCom.h"

#include "../Events/BeginGameEvent.h"

ProgressSystem::ProgressSystem():GX::System("ProgressSystem",ProgressCom::_TYPE)
{
    
}

GX::System* ProgressSystem::cloneEmpty() const
{
    return new ProgressSystem();
}

void ProgressSystem::onInit()
{
    
}

void ProgressSystem::onBegin(cocos2d::EventCustom* event)
{
    _begin=true;
    _progress->durence=((BeginGameEvent*)event)->totalSeconds;
    _progress->currentProgress=0;
}

void ProgressSystem::onAttached()
{
    _begin=false;
    _progress=(ProgressCom*)getComByType(ProgressCom::_TYPE);
    _progress->paused=true;
    
    auto node=(GX::NodeCom*)getComByType(GX::NodeCom::_TYPE);
    _progressTimer=(cocos2d::ProgressTimer*)node->getNodeByName("progress");
    _labelTimer=(cocos2d::Label*)node->getNodeByName("timer");
}

void ProgressSystem::onDeattached()
{
    
}

void ProgressSystem::update(float dt)
{
    if (_progress->paused) {
        return;
    }
    
    _progressTimer->setPercentage(_progress->currentProgress/_progress->durence*100.0f);
    _labelTimer->setString(cocos2d::StringUtils::format("%d / %d",(int)_progress->currentProgress,(int)_progress->durence));
    _progress->currentProgress+=dt;
}

void ProgressSystem::onComsChanged()
{
    
}