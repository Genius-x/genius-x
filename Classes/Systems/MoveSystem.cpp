//
//  MoveSystem.cpp
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#include "MoveSystem.h"

MoveSystem::MoveSystem():GX::System("MoveSystem",MoveCom::_TYPE)
{
    
}

GX::System* MoveSystem::cloneEmpty() const
{
    return new MoveSystem();
}

void MoveSystem::onAttached()
{
    _move=(MoveCom*)getComByType(MoveCom::_TYPE);
    float distance=getNode()->getPosition().getDistance(_move->to);
    float durence=distance/_move->speed;
    auto to=cocos2d::MoveTo::create(durence, _move->to);
    
    auto call=cocos2d::CallFunc::create(CC_CALLBACK_0(MoveSystem::onMoveCompleted,this));
    getNode()->runAction(cocos2d::Sequence::create(to,call,NULL));
}

void MoveSystem::onMoveCompleted()
{
    getNode()->removeFromParent();
    getECSManager()->removeEntity(getEntity());
}