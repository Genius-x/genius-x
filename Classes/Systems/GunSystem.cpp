//
//  GunSystem.cpp
//  sg
//
//  Created by Elvis on 3/27/14.
//
//

#include "GunSystem.h"
#include "../Events/GunEvent.h"

GunSystem::GunSystem():GX::System("GunSystem",GunCom::_TYPE)
,_currentTime(0)
{
    
}

GX::System* GunSystem::cloneEmpty() const
{
    return new GunSystem();
}

void GunSystem::onAttached()
{
    _gun=(GunCom*)getComByType(GunCom::_TYPE);
}

void GunSystem::update(float dt)
{
    if (_currentTime<_gun->data.bullet_rate) {
        _currentTime+=dt;
        return;
    }
    else {
        _currentTime=0;
        auto entities=getECSManager()->getAllEntitiesPosessingCom(_gun->data.target);
        if (!entities.empty()) {
            GunEvent* event=new GunEvent(_gun->data);
            event->targetPosition=entities.at(0)->getNode()->getPosition();
            event->position=getNode()->convertToWorldSpace(cocos2d::Point::ZERO);
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(event);
        }
    }
}