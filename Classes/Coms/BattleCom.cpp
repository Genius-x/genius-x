//
//  BattleCom.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "BattleCom.h"

std::string BattleCom::_TYPE="BattleCom";

BattleCom::BattleCom()
:GX::Com(_TYPE)
{
    
}

void BattleCom::initWithMap(rapidjson::Value&)
{
    
}

GX::Com* BattleCom::cloneEmpty() const
{
    return new BattleCom();
}