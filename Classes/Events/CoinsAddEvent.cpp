//
//  CoinsAddEvent.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "CoinsAddEvent.h"
const char* CoinsAddEvent::_TYPE="CoinsAddEvent";

CoinsAddEvent::CoinsAddEvent(int nCount)
:EventCustom(_TYPE)
,count(nCount)
{
    
}