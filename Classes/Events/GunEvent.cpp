//
//  GunEvent.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "GunEvent.h"
std::string GunEvent::_TYPE="GunEvent";

GunEvent::GunEvent(BulletData bulletData)
:EventCustom(_TYPE)
,data(bulletData)
{
    
}