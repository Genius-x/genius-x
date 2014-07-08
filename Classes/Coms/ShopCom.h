//
//  ShopCom.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__ShopCom__
#define __sg__ShopCom__

#include "genius-x.h"

USING_NS_CC;

struct ShopData{
    ShopData()
    :name("")
    ,image("")
    ,bullet_image("")
    ,bullet_hp(0)
    ,bullet_rate(0)
    ,bullet_speed(0)
    ,price(0)
    ,hp(0)
    ,coin(0)
    ,coin_rate(0)
    {}
    
    std::string name;
    std::string image;
    std::string bullet_image;
    int bullet_hp;
    float bullet_rate;
    float bullet_speed;
    float price;
    int hp;
    int coin;
    float coin_rate;
};

class ShopCom :public GX::Com
{
public:
    static std::string _TYPE;
    ShopCom();
    
    Size viewSize;
    Size cellSize;
    Point position;
    Point anchorPoint;
    Point anchor;
    
    std::vector<ShopData> data;
    
protected:
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
};


#endif /* defined(__sg__ShopCom__) */
