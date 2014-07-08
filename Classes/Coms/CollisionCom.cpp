//
//  CollisionCom.cpp
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#include "CollisionCom.h"
std::string CollisionCom::_TYPE="CollisionCom";
CollisionCom::CollisionCom()
:GX::Com(_TYPE)
{
}

GX::Com* CollisionCom::cloneEmpty() const
{
    return  new CollisionCom();
}
