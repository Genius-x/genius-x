//
//  MonsterAddEvent.h
//  sg
//
//  Created by Elvis on 3/26/14.
//
//

#ifndef __sg__MonsterAddEvent__
#define __sg__MonsterAddEvent__

#include "cocos2d.h"
#include "genius-x.h"
#include "../Coms/LevelDataCom.h"

class MonsterAddEvent:public cocos2d::EventCustom
{
public:
    static const char* _TYPE;
    
    MonsterData data;
    
    MonsterAddEvent(const MonsterData&);
};

#endif /* defined(__sg__MonsterAddEvent__) */
