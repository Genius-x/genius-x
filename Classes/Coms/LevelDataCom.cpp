//
//  LevelDataCom.cpp
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#include "LevelDataCom.h"

std::string LevelDataCom::_TYPE="LevelDataCom";

LevelDataCom::LevelDataCom()
:GX::Com(_TYPE)
{
    
}

void LevelDataCom::initWithMap(rapidjson::Value& node)
{
    ship_image=node["ship_image"].GetString();
    durence=node["durence"].GetInt();
    ship_hp=node["ship_hp"].GetInt();
    ship_coin=node["ship_coin"].GetInt();
    ship_coin_rate=node["ship_coin_rate"].GetInt();
    
    int count=node["data"].Size();
    for (int i=0; i<count; i++) {
        rapidjson::Value& phaseNode=node["data"][i];
        
        PhaseData phaseData;
        phaseData.durence=phaseNode["durence"].GetInt();
        
        if (phaseNode.HasMember("monsters")) {
            int count1=phaseNode["monsters"].Size();
            for (int j=0; j<count1; j++) {
                rapidjson::Value& monsterNode=phaseNode["monsters"][j];
                
                MonsterData monsterData;
                monsterData.image=monsterNode["filename"].GetString();
                
                if (monsterNode.HasMember("hp")) {
                    monsterData.hp=monsterNode["hp"].GetInt();
                }
                
                if (monsterNode.HasMember("coins")) {
                    monsterData.coins=monsterNode["coins"].GetInt();
                }
                
                if (monsterNode.HasMember("speed")) {
                    monsterData.speed=monsterNode["speed"].GetDouble();
                }
                
                if (monsterNode.HasMember("bullet_image")) {
                    monsterData.bullet_image=monsterNode["bullet_image"].GetString();
                    monsterData.bullet_hp=monsterNode["bullet_hp"].GetInt();
                    monsterData.bullet_rate=monsterNode["bullet_rate"].GetInt();
                    monsterData.bullet_speed=monsterNode["bullet_speed"].GetDouble();
                }
                
                phaseData.data.push_back(monsterData);
            }
        }
        
        data.push_back(phaseData);
    }
}

GX::Com* LevelDataCom::cloneEmpty() const
{
    return new LevelDataCom();
}