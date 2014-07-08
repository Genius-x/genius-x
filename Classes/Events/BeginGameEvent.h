//
//  BeginGameEvent.h
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#ifndef __sg__BeginGameEvent__
#define __sg__BeginGameEvent__


#include "cocos2d.h"
#include "genius-x.h"

class BeginGameEvent:public cocos2d::EventCustom
{
public:
    static const char* _TYPE;
 
    int totalSeconds;
    
    BeginGameEvent(int seconds);
};

#endif /* defined(__sg__BeginGameEvent__) */
