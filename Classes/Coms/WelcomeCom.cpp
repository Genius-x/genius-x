//
//  WelcomeCom.cpp
//  sg
//
//  Created by Elvis on 3/20/14.
//
//

#include "WelcomeCom.h"

std::string WelcomeCom::_TYPE="WelcomeCom";

WelcomeCom::WelcomeCom()
:GX::Com(_TYPE)
{
    
}

void WelcomeCom::initWithMap(rapidjson::Value&)
{
    
}

GX::Com* WelcomeCom::cloneEmpty() const
{
    return new WelcomeCom();
}