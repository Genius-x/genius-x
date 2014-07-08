//
//  MoveCom.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "MoveCom.h"

std::string MoveCom::_TYPE="MoveCom";

MoveCom::MoveCom()
:GX::Com(_TYPE)
{
    
}

GX::Com* MoveCom::cloneEmpty() const
{
    return new MoveCom();
}