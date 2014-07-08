//
//  ProgressCom.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "ProgressCom.h"

std::string ProgressCom::_TYPE="ProgressCom";
ProgressCom::ProgressCom():GX::Com(_TYPE)
{
    
}

void ProgressCom::initWithMap(rapidjson::Value& value)
{
    
}

GX::Com* ProgressCom::cloneEmpty() const
{
    return new  ProgressCom();
}