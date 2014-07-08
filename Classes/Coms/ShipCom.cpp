//
//  ShipCom.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "ShipCom.h"

std::string ShipCom::_TYPE="ShipCom";
ShipCom::ShipCom()
:GX::Com(_TYPE)
{
    
}

GX::Com* ShipCom::cloneEmpty() const
{
    return new  ShipCom();
}