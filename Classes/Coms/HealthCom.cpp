//
//  HealthCom.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "HealthCom.h"

std::string HealthCom::_TYPE="HealthCom";
HealthCom::HealthCom():GX::Com(_TYPE)
{
    
}

void HealthCom::initWithMap(rapidjson::Value&)
{
    
}

GX::Com* HealthCom::cloneEmpty() const
{
    return new HealthCom();
}