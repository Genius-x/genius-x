//
//  ShopItemEvent.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__ShopItemEvent__
#define __sg__ShopItemEvent__

#include "cocos2d.h"
#include "../Coms/ShopCom.h"

class ShopItemEvent:public cocos2d::EventCustom
{
public:
    ShopData data;
    static std::string _TYPE;
    
    ShopItemEvent(const ShopData& aData):cocos2d::EventCustom(_TYPE),data(aData)
    {
        
    }
};

#endif /* defined(__sg__ShopItemEvent__) */
