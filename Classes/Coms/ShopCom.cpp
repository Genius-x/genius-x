//
//  ShopCom.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "ShopCom.h"

std::string ShopCom::_TYPE="ShopCom";
ShopCom::ShopCom():GX::Com(_TYPE)
{
    
}

void ShopCom::initWithMap(rapidjson::Value& value)
{
    viewSize=cocos2d::SizeFromString(value["viewSize"].GetString());
    cellSize=cocos2d::SizeFromString(value["cellSize"].GetString());
    position=cocos2d::PointFromString(value["position"].GetString());
    anchorPoint=cocos2d::PointFromString(value["anchorPoint"].GetString());
    //anchor=cocos2d::PointFromString(value["anchor"].GetString());
    
    if (value.HasMember("data")) {
        int count=value["data"].Size();
        
        for (int i=0; i<count; i++) {
            ShopData sData;
            sData.name=value["data"][i]["name"].GetString();
            sData.image=value["data"][i]["filename"].GetString();
            if (value["data"][i].HasMember("bullet_image")) {
                sData.bullet_image=value["data"][i]["bullet_image"].GetString();
                sData.bullet_hp=value["data"][i]["bullet_hp"].GetInt();
                sData.bullet_rate=value["data"][i]["bullet_rate"].GetDouble();
                sData.bullet_speed=value["data"][i]["bullet_speed"].GetDouble();
            }
            sData.price=value["data"][i]["price"].GetDouble();
            sData.hp=value["data"][i]["hp"].GetInt();
            sData.coin=value["data"][i]["coin"].GetInt();
            sData.coin_rate=value["data"][i]["coin_rate"].GetDouble();
            
            data.push_back(sData);
        }
    }
}

GX::Com* ShopCom::cloneEmpty() const
{
    return new ShopCom();
}