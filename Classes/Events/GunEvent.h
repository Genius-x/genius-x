//
//  GunEvent.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__GunEvent__
#define __sg__GunEvent__

/** 发射一颗子弹 */
#include "cocos2d.h"
#include "genius-x.h"
#include "../Coms/GunCom.h"

/** 给玩家添加金币 */
class GunEvent:public cocos2d::EventCustom
{
public:
    BulletData data;                  //子弹数据
    cocos2d::Point position;          //发射位置
    cocos2d::Point targetPosition;    //目标位置
    
public:
    static std::string _TYPE;
    
    GunEvent(BulletData bulletData);
};


#endif /* defined(__sg__GunEvent__) */
