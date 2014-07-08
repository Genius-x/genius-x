//
//  MonsterAddEvent.cpp
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#include "MonsterAddEvent.h"

const char* MonsterAddEvent::_TYPE="MonsterAddEvent";
MonsterAddEvent::MonsterAddEvent(const MonsterData& d)
:cocos2d::EventCustom(_TYPE)
,data(d)
{
    
}