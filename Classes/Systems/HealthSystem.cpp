//
//  HealthSystem.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "HealthSystem.h"
#include "../Coms/HealthCom.h"
#include "../Events/DeadEvent.h"

HealthSystem::HealthSystem()
:GX::System("HealthSystem",HealthCom::_TYPE)
,_timer(nullptr)
,_health(nullptr)
{
    
}

GX::System* HealthSystem::cloneEmpty() const
{
    return new HealthSystem();
}

void HealthSystem::onAttached()
{
    if (getNode()) {
        _health=(HealthCom*)getComByType(HealthCom::_TYPE);
        _health->total=_health->hp;
        
        auto sprite=cocos2d::Sprite::create("images/hp.png");
        sprite->setScaleX(getNode()->getContentSize().width/sprite->getContentSize().width);
        
        _timer=cocos2d::ProgressTimer::create(sprite);
        _timer->setType(cocos2d::ProgressTimer::Type::BAR);
        _timer->setMidpoint(cocos2d::Point(0,0));
        _timer->setBarChangeRate(cocos2d::Point(1, 0));
        _timer->setPercentage(100.0f);
        
        //放在最下
        _timer->setAnchorPoint(cocos2d::Point(0,0));
        _timer->setScaleX(getNode()->getContentSize().width/_timer->getContentSize().width);
        getNode()->addChild(_timer);
    }
    
    _dead=false;
}

void HealthSystem::update(float dt)
{
    if (_dead) {
        return;
    }
    
    if (_health->hp<=0) {
        _dead=true;
        DeadEvent* event=new DeadEvent(getEntity());
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(event);
        return;
    }
    
    if (_timer) {
        _timer->setPercentage((float)_health->hp/(float)_health->total*100.0f);
    }
}
