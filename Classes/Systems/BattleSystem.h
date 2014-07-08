//
//  BattleSystem.h
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#ifndef __sg__BattleSystem__
#define __sg__BattleSystem__

#include "genius-x.h"
#include "ui/UIWidget.h"
#include "../Coms/BattleCom.h"
#include "../Coms/LevelDataCom.h"
#include "../GameSystemDelegate.h"


static const int shipCategory           = 0x1 << 1;
static const int gunCategory            = 0x1 << 2;
static const int monsterCategory        = 0x1 << 3;
static const int gunBulletCategory      = 0x1 << 4;
static const int monsterBulletCategory  = 0x1 << 5;



/**
 * 1，响应碰撞事件，做碰撞处理
 * 2, 处理游戏结束
 * 3, 根据关卡信息创建怪物，船，宝箱
 */
class BattleSystem : public GX::System
{
public:
    BattleSystem();
    
    static const int SHIP_DRAG_TAG=100;
    
protected:
    virtual System* cloneEmpty() const;
    
    virtual void onInit() override;
    virtual void onAttached() override;
    virtual void onDeattached() override;
    
    virtual void update(float dt) override;
    virtual void onComsChanged() override;
    
    void onDead(EventCustom*);
    void addCoin(cocos2d::EventCustom* event);
    void addShopItem(cocos2d::EventCustom* event);
    void addMonster(cocos2d::EventCustom* event);
    void addBullet(cocos2d::EventCustom* event);
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    Point getPosition(Node*);
    Point getMonsterRandomPosition();
    
    bool onPhysicsContact(cocos2d::PhysicsContact&);
    
private:
    GX::Entity* _ship;
    std::vector<GX::Entity*> _shopItems;
    std::vector<GX::Entity*> _monsters;
    std::vector<GX::Entity*> _bullets;
    
    BattleCom* _battle;
    
    GX::Entity* _dataEntity;
    LevelDataCom* _data;
    cocos2d::Sprite* _shipSprite;
    PlayerCom* _player;
    
    GX::Entity* _progress;
    GX::Entity* _shop;
    
    Scene* _scene;
    
    float _currentRadius=70;
    float _diffRadius=40;
    float _currentAngle=-45;
    float _diffAngle=45;
    Point _prevois;
};

#endif /* defined(__sg__BattleSystem__) */
