//
//  DeadEvent.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__DeadEvent__
#define __sg__DeadEvent__

#include "cocos2d.h"
#include "genius-x.h"


class DeadEvent:public cocos2d::EventCustom
{
public:
    GX::Entity* entity;
    
public:
    static const char* _TYPE;
    static DeadEvent* create(GX::Entity* e);
    
    DeadEvent(GX::Entity* e);
};

#endif /* defined(__sg__DeadEvent__) */
