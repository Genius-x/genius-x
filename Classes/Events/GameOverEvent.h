//
//  GameOverEvent.h
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#ifndef __sg__GameOverEvent__
#define __sg__GameOverEvent__

#include "cocos2d.h"
#include "genius-x.h"

class GameOverEvent:public cocos2d::EventCustom
{
public:
    static const char* _TYPE;
    bool isWin;
    GameOverEvent(bool win);
};

#endif /* defined(__sg__GameOverEvent__) */
