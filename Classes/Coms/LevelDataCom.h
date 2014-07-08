//
//  LevelDataCom.h
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#ifndef __sg__LevelDataCom__
#define __sg__LevelDataCom__

#include "genius-x.h"

//怪物数据
struct MonsterData
{
    MonsterData()
    :image("")
    ,hp(0)
    ,speed(0)
    ,coins(0)
    ,bullet_image("")
    ,bullet_hp(0)
    ,bullet_rate(0)
    ,bullet_speed(0)
    {}
    
    std::string image;     //
    int hp;                //撞击血量
    int coins;             //资源怪物
    float speed;           //每s移动多少像素
    
    std::string bullet_image;  //可发射子弹的怪物
    int bullet_hp;
    int bullet_rate;
    float bullet_speed;
};

struct PhaseData
{
    enum class PhaseType
    {
        PhaseNonde,       //空白区
        PhaseMonster      //怪物区
    };
    
    PhaseType type;
    int durence;          //阶段持续时间
    std::vector<MonsterData> data;   //怪物区包含怪物
};

class LevelDataCom :public GX::Com
{
public:
    static std::string _TYPE;
    LevelDataCom();
    
    std::string ship_image;         //船图片
    int ship_hp;                    //船血量
    int ship_coin;                  //船每次产生资源数量
    float ship_coin_rate;           //船产生资源的间隔
    
    int durence;                    //持续时间
    std::vector<PhaseData> data;    //阶段数据
    
protected:
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
};

#endif /* defined(__sg__LevelDataCom__) */
