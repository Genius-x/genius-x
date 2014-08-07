//
//  BeginGameEvent.cpp
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#include "BeginGameEvent.h"

const char* BeginGameEvent::_TYPE="BeginGameEvent";

BeginGameEvent::BeginGameEvent(int seconds)
:cocos2d::EventCustom(_TYPE)
,totalSeconds(seconds)
{
    
}