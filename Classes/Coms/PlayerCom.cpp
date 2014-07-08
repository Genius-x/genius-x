//
//  PlayerCom.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "PlayerCom.h"

std::string PlayerCom::_TYPE="PlayerCom";
PlayerCom::PlayerCom():GX::Com(_TYPE)
{
    
}

void PlayerCom::initWithMap(rapidjson::Value&)
{
    
}

GX::Com* PlayerCom::cloneEmpty() const
{
    return new PlayerCom();
}

void PlayerCom::saveData()
{
    cocos2d::UserDefault::getInstance()->setIntegerForKey("coins", coins);
    cocos2d::UserDefault::getInstance()->setIntegerForKey("lockLevel", lockLevel);
    cocos2d::UserDefault::getInstance()->setIntegerForKey("winCount", winCount);
    cocos2d::UserDefault::getInstance()->setIntegerForKey("lostCount", lostCount);
}
