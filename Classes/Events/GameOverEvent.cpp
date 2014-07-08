//
//  GameOverEvent.cpp
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#include "GameOverEvent.h"

const char* GameOverEvent::_TYPE="GameOverEvent";

GameOverEvent::GameOverEvent(bool win)
:cocos2d::EventCustom(_TYPE),
isWin(win)
{
    
}