//
//  CoinSystem.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "CoinSystem.h"
#include "../Events/CoinsAddEvent.h"

CoinSystem::CoinSystem():GX::System("CoinSystem",CoinCom::_TYPE)
,_currentTime(0)
{
    
}

GX::System* CoinSystem::cloneEmpty() const
{
    return new CoinSystem();
}

void CoinSystem::onAttached()
{
    _coin=(CoinCom*)getComByType(CoinCom::_TYPE);
}

void CoinSystem::update(float dt)
{
    if (_currentTime<_coin->coin_rate) {
        _currentTime+=dt;
        return;
    }
    else {
        _currentTime=0;
        CoinsAddEvent* event=new CoinsAddEvent(_coin->coin);
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(event);
        
        auto coins=cocos2d::Sprite::create("images/ghost4.png");
        getNode()->addChild(coins);
        coins->setPosition(cocos2d::Point(getNode()->getContentSize().width/2,getNode()->getContentSize().height/2));
        
        auto move=cocos2d::MoveBy::create(0.3, cocos2d::Point(0,50));
        auto fade=cocos2d::FadeOut::create(0.3);
        coins->runAction(cocos2d::Sequence::create(cocos2d::Spawn::create(move,fade, NULL),cocos2d::RemoveSelf::create(),NULL));
    }
}