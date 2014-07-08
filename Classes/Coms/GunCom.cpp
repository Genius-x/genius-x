//
//  GunCom.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "GunCom.h"
std::string GunCom::_TYPE="GunCom";
GunCom::GunCom()
:GX::Com(_TYPE)
{
    
}

void GunCom::initWithMap(rapidjson::Value& value)
{
    
}

GX::Com* GunCom::cloneEmpty() const
{
    return new GunCom();
}
