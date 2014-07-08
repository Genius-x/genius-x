//
//  DeadEvent.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "DeadEvent.h"

const char* DeadEvent::_TYPE="DeadEventType";

DeadEvent* DeadEvent::create(GX::Entity* e)
{
    DeadEvent* event=new DeadEvent(e);
    if(event){
        return event;
    }
    
    if (event) {
        delete event;
    }
    return NULL;
}

DeadEvent::DeadEvent(GX::Entity* e)
:EventCustom(DeadEvent::_TYPE)
,entity(e)
{
    
}