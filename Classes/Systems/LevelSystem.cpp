//
//  LevelSystem.cpp
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#include "LevelSystem.h"
#include "genius-x.h"
#include "../Coms/WelcomeCom.h"
#include "../Coms/PlayerCom.h"
#include "../LevelScene.h"
#include "../BattleScene.h"

using namespace cocos2d::ui;

LevelSystem::LevelSystem()
:GX::System("LevelSystem",LevelCom::_TYPE)
,_level(nullptr)
{
    
}

GX::System* LevelSystem::cloneEmpty() const
{
    return new LevelSystem();
}

void LevelSystem::onInit()
{
    
}

void LevelSystem::onAttached()
{
    _level=(LevelCom*)getComByType(LevelCom::_TYPE);
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

void LevelSystem::onDeattached()
{
    
}

void LevelSystem::update(float dt)
{
    
}

void LevelSystem::onComsChanged()
{
    
}

void LevelSystem::tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)
{
    auto entities= getECSManager()->getAllEntitiesPosessingCom(PlayerCom::_TYPE);
    if (!entities.empty()) {
        auto player=(PlayerCom*)entities.at(0)->getComByType(PlayerCom::_TYPE);
        player->currentLevel=_level->data[cell->getIdx()].entity;
    }
    
    cocos2d::Director::getInstance()->replaceScene(BattleScene::scene(_level->data[cell->getIdx()].entity));
}

Size LevelSystem::cellSizeForTable(cocos2d::extension::TableView *table)
{
    return _level->cellSize;
}

cocos2d::extension::TableViewCell* LevelSystem::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)
{
    auto cell=table->dequeueCell();
    if (cell==nullptr) {
        cell=cocos2d::extension::TableViewCell::create();
    }
    
    cell->removeAllChildren();
    auto entity=GX::GameSystem::getInstance()->getECS()->createEntity("LevelCell.json");
    auto node=(GX::NodeCom*)entity->getComByType(GX::NodeCom::_TYPE);
    cell->addChild(entity->getNode());
    
    ((cocos2d::Label*)node->getNodeByName("title"))->setString(_level->data[idx].title);
    ((cocos2d::Label*)node->getNodeByName("description"))->setString(_level->data[idx].description);
    ((cocos2d::Sprite*)node->getNodeByName("image"))->setTexture(_level->data[idx].image);
    
    return cell;
}

ssize_t LevelSystem::numberOfCellsInTableView(cocos2d::extension::TableView *table)
{
    return _level->data.size();
}