//
//  CoinsAddEvent.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__CoinsAddEvent__
#define __sg__CoinsAddEvent__

#include "cocos2d.h"
#include "genius-x.h"

/** 给玩家添加金币 */
class CoinsAddEvent:public cocos2d::EventCustom
{
public:
    int count;
    
public:
    static const char* _TYPE;
    
    CoinsAddEvent(int nCount);
};

#endif /* defined(__sg__CoinsAddEvent__) */
