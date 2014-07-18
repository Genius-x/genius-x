//
//  GunCom.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__GunCom__
#define __sg__GunCom__

#include "genius-x.h"

struct BulletData {
    BulletData()
    :target("")
    ,bullet_image("")
    ,bullet_hp(0)
    ,bullet_rate(0)
    ,bullet_speed(0)
    {
    }
    
    BulletData(std::string sTarget,std::string sBullet_image,int sBullet_hp,int sBullet_rate,float sBullet_speed)
    :target(sTarget)
    ,bullet_image(sBullet_image)
    ,bullet_hp(sBullet_hp)
    ,bullet_rate(sBullet_rate)
    ,bullet_speed(sBullet_speed)
    {
        
    }
    
    std::string target;          //目标类型
    std::string bullet_image;    //子弹素材
    int bullet_hp;               //子弹血量
    int bullet_rate;             //子弹发射频率
    float bullet_speed;
};

/**
 * 拥有GunCom的游戏对象会按一定频率发射子弹
 * GunSystem会寻找对应目标发射子弹
 */

class GunCom :public GX::Com
{
public:
    static std::string _TYPE;
    GunCom();
    
    BulletData data;
    
protected:
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__GunCom__) */
