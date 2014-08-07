//
//  GameSystemDelegate.cpp
//  SG
//
//  Created by Elvis on 14-1-27.
//
//

#include "GameSystemDelegate.h"
#include "Coms/WelcomeCom.h"
#include "Systems/WelcomeSystem.h"

#include "Coms/LevelCom.h"
#include "Coms/LevelDataCom.h"
#include "Systems/LevelSystem.h"

#include "Coms/BattleCom.h"
#include "Systems/BattleSystem.h"

#include "Coms/ProgressCom.h"
#include "Systems/ProgressSystem.h"

#include "Coms/ShopCom.h"
#include "Systems/ShopSystem.h"

#include "Coms/HealthCom.h"
#include "Systems/HealthSystem.h"

#include "Coms/CoinCom.h"
#include "Systems/CoinSystem.h"
#include "Systems/LevelDataSystem.h"

#include "Coms/MoveCom.h"
#include "Systems/MoveSystem.h"

#include "Coms/ShipCom.h"
#include "Coms/MonsterCom.h"

#include "Coms/GunCom.h"
#include "Systems/GunSystem.h"

bool GameSystemDelegate::showFTUEUI(FTUEData* data)
{
    return false;
}

void GameSystemDelegate::init()
{
    GameSystem::init();
    
    getECS()->registerSystem(new WelcomeSystem());
    getECS()->registerCom(new WelcomeCom());
    
    getECS()->registerSystem(new LevelSystem());
    getECS()->registerSystem(new LevelDataSystem());
    getECS()->registerCom(new LevelCom());
    getECS()->registerCom(new LevelDataCom());
    
    getECS()->registerSystem(new BattleSystem());
    getECS()->registerCom(new BattleCom());
    
    getECS()->registerSystem(new ProgressSystem());
    getECS()->registerCom(new ProgressCom());
    
    getECS()->registerSystem(new ShopSystem());
    getECS()->registerCom(new ShopCom());
    
    getECS()->registerSystem(new HealthSystem());
    getECS()->registerCom(new HealthCom());
    
    getECS()->registerSystem(new CoinSystem());
    getECS()->registerCom(new CoinCom());
    
    getECS()->registerSystem(new MoveSystem());
    getECS()->registerCom(new MoveCom());
    
    getECS()->registerCom(new MonsterCom());
    getECS()->registerCom(new ShipCom());
    
    getECS()->registerSystem(new GunSystem());
    getECS()->registerCom(new GunCom());
    
    initPlayerInfo();
}

GameSystemDelegate::GameSystemDelegate()
{
    
}

GameSystemDelegate::~GameSystemDelegate()
{
    getECS()->removeEntity(_player);
}

//玩家数值: 金币，当前关卡进度，船的装备
void GameSystemDelegate::initPlayerInfo()
{
    _player=getECS()->createEntity();
    PlayerCom* player=new PlayerCom();
    player->coins=cocos2d::UserDefault::getInstance()->getIntegerForKey("coins", 100);
    player->lockLevel=cocos2d::UserDefault::getInstance()->getIntegerForKey("lockLevel", 1);
    player->winCount=cocos2d::UserDefault::getInstance()->getIntegerForKey("winCount", 1);
    player->lostCount=cocos2d::UserDefault::getInstance()->getIntegerForKey("lostCount", 1);
    
    getECS()->addComToEntity(player, _player);
}
