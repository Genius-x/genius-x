//
//  LevelCom.cpp
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#include "LevelCom.h"

std::string LevelCom::_TYPE="LevelCom";

LevelCom::LevelCom()
:GX::Com(_TYPE)
{
    
}

void LevelCom::initWithMap(rapidjson::Value& value)
{
    viewSize=cocos2d::SizeFromString(value["viewSize"].GetString());
    cellSize=cocos2d::SizeFromString(value["cellSize"].GetString());
    position=cocos2d::PointFromString(value["position"].GetString());
    anchorPoint=cocos2d::PointFromString(value["anchorPoint"].GetString());
    anchor=cocos2d::PointFromString(value["anchor"].GetString());
    
    if (value.HasMember("data")) {
        int count=value["data"].Size();
        
        for (int i=0; i<count; i++) {
            LevelData lData;
            lData.image=value["data"][i]["image"].GetString();
            lData.title=value["data"][i]["title"].GetString();
            lData.description=value["data"][i]["description"].GetString();
            lData.entity=value["data"][i]["entity"].GetString();
            
            data.push_back(lData);
        }
    }
}

GX::Com* LevelCom::cloneEmpty() const
{
    return new LevelCom();
}