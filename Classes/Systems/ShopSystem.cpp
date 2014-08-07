//
//  ShopSystem.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "ShopSystem.h"


#include "../Coms/WelcomeCom.h"
#include "../Coms/PlayerCom.h"
#include "../LevelScene.h"
#include "../BattleScene.h"
#include "../Events/ShopItemEvent.h"
#include "../Events/CoinsAddEvent.h"

using namespace cocos2d::ui;

ShopSystem::ShopSystem()
:GX::System("ShopSystem",ShopCom::_TYPE)
,_level(nullptr)
{
    
}

GX::System* ShopSystem::cloneEmpty() const
{
    return new ShopSystem();
}

void ShopSystem::onAttached()
{
    auto entities= GX::GameSystem::getInstance()->getECS()->getAllEntitiesPosessingCom(PlayerCom::_TYPE);
    if (!entities.empty()) {
        _player=(PlayerCom*)entities.at(0)->getComByType(PlayerCom::_TYPE);
    }
    
    _level=(ShopCom*)getComByType(ShopCom::_TYPE);
    if (_level) {
        auto table=cocos2d::extension::TableView::create(this, _level->viewSize);
        table->setPosition(_level->position);
        table->setAnchorPoint(_level->anchor);
        table->setDirection(cocos2d::extension::ScrollView::Direction::HORIZONTAL);
        table->setTouchEnabled(true);
        table->setDelegate(this);
        
        getNode()->addChild(table);
        table->reloadData();
    }
}

void ShopSystem::tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)
{
    ShopData& data=_level->data.at(cell->getIdx());
    
    if (_player->coins>=data.price){
        auto event=new ShopItemEvent(data);
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(event);
        
        CoinsAddEvent* event1=new CoinsAddEvent((int)-data.price);
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(event1);
    }
}

Size ShopSystem::cellSizeForTable(cocos2d::extension::TableView *table)
{
    return _level->cellSize;
}

cocos2d::extension::TableViewCell* ShopSystem::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)
{
    auto cell=table->dequeueCell();
    if (cell==nullptr) {
        cell=cocos2d::extension::TableViewCell::create();
    }
    
    cell->removeAllChildren();
    auto entity=GX::GameSystem::getInstance()->getECS()->createEntity("ShopCell.json");
    auto node=(GX::NodeCom*)entity->getComByType(GX::NodeCom::_TYPE);
    cell->addChild(entity->getNode());
    
    ((cocos2d::Label*)node->getNodeByName("name"))->setString(_level->data[idx].name);
    ((cocos2d::Label*)node->getNodeByName("price"))->setString(cocos2d::StringUtils::format("%f",_level->data[idx].price));
    ((cocos2d::Sprite*)node->getNodeByName("image"))->setTexture(_level->data[idx].image);
    ((cocos2d::Label*)node->getNodeByName("description"))->setString(cocos2d::StringUtils::format("hp:%d,coin:%d",_level->data[idx].hp,_level->data[idx].coin));
    
    if (!_level->data[idx].bullet_image.empty()) {
        auto bullet_image=(cocos2d::Sprite*)node->getNodeByName("bullet_image");
        bullet_image->setTexture(_level->data[idx].bullet_image);
        bullet_image->setVisible(true);
        
        auto bullet_hp=(cocos2d::Label*)node->getNodeByName("bullet_hp");
        bullet_hp->setString(cocos2d::StringUtils::format("%d",_level->data[idx].bullet_hp));
        bullet_hp->setVisible(true);
    }
    
    return cell;
}

ssize_t ShopSystem::numberOfCellsInTableView(cocos2d::extension::TableView *table)
{
    return _level->data.size();
}