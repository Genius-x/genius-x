//
//  BattleSystem.cpp
//  sg
//
//  Created by Elvis on 3/25/14.
//
//

#include "BattleSystem.h"
#include "../Coms/BattleCom.h"
#include "genius-x.h"
#include "../Coms/HealthCom.h"
#include "../Coms/CoinCom.h"

#include "../Events/CoinsAddEvent.h"
#include "../Events/GunEvent.h"
#include "../Events/ShopItemEvent.h"
#include "../Events/MonsterAddEvent.h"
#include "../Events/BeginGameEvent.h"
#include "../Events/DeadEvent.h"

#include "../Coms/MoveCom.h"
#include "../Coms/ProgressCom.h"
#include "../Coms/ShipCom.h"
#include "../Coms/MonsterCom.h"

USING_NS_CC;

BattleSystem::BattleSystem()
	:GX::System("BattleSystem",BattleCom::_TYPE),
	_ship(nullptr)
{
	_currentRadius=70;
	_diffRadius=40;
	_currentAngle=-45;
	_diffAngle=45;
}

GX::System* BattleSystem::cloneEmpty() const
{
	return new BattleSystem();
}

void BattleSystem::onInit()
{

}

//加金币
void BattleSystem::addCoin(cocos2d::EventCustom* event)
{
	auto coin=(CoinsAddEvent*)event;
	_player->coins+=coin->count;

	auto node=(NodeCom*)getComByType(NodeCom::_TYPE);
	((Label*)node->getNodeByName("coins_number"))->setString(StringUtils::format("%d",_player->coins));

	if (coin->count>0) {
		ScaleTo* to=ScaleTo::create(0.3, 1.5);
		ScaleTo* back=ScaleTo::create(0.3, 1);
		node->getNodeByName("coin_bg")->runAction(Sequence::create(to,back, NULL));
	}
	else {
		TintTo* to=TintTo::create(0.3, 255, 0, 0);
		TintTo* back=TintTo::create(0.3, 255, 255, 255);
		node->getNodeByName("coin_bg")->runAction(Sequence::create(to,back, NULL));
	}
}

Point BattleSystem::getPosition(Node* node)
{
	Point point;
	_currentAngle+=_diffAngle;

	point.x=cosf(_currentAngle*M_PI / 180.0f)*_currentRadius;
	point.y=sinf(_currentAngle*M_PI / 180.0f)*_currentRadius;

	//向外扩展一圈
	if (_currentAngle>=360) {
		_diffAngle-=10;
		_currentAngle=-_diffAngle;
		_currentRadius+=_diffRadius;
	}

	return point+_shipSprite->getPosition()-Point(0, 10);
}

void BattleSystem::addShopItem(cocos2d::EventCustom* event)
{
	ShopItemEvent* sEvent=(ShopItemEvent*)event;

	auto entity=getECSManager()->createEntity();
	auto sprite=Sprite::create(sEvent->data.image);
	auto body=PhysicsBody::createBox(sprite->getContentSize());
	sprite->setPhysicsBody(body);

	//枪和怪物，子弹发生碰撞
	body->setCollisionBitmask(0);
	body->setCategoryBitmask(gunCategory);
	body->setContactTestBitmask(monsterBulletCategory|monsterCategory);

	sprite->setPosition(getPosition(sprite));
	getNode()->addChild(sprite);
	sprite->setUserData(entity);


	NodeCom* node=new NodeCom();
	node->node=sprite;
	getECSManager()->addComToEntity(node, entity);

	//hp
	auto health=new HealthCom();
	health->hp=sEvent->data.hp;
	getECSManager()->addComToEntity(health, entity);

	if (sEvent->data.coin>0) {
		auto coin=new CoinCom();
		coin->coin=sEvent->data.coin;
		coin->coin_rate=sEvent->data.coin_rate;

		getECSManager()->addComToEntity(coin, entity);
	}

	if (sEvent->data.bullet_hp>0) {
		auto gun=new  GunCom();
		gun->data.bullet_hp=sEvent->data.bullet_hp;
		gun->data.bullet_image=sEvent->data.bullet_image;
		gun->data.bullet_rate=sEvent->data.bullet_rate;
		gun->data.target=MonsterCom::_TYPE;
		gun->data.bullet_speed=sEvent->data.bullet_speed;

		getECSManager()->addComToEntity(gun, entity);
	}

	_shopItems.push_back(entity);
}

Point BattleSystem::getMonsterRandomPosition()
{
	Size size=Director::getInstance()->getVisibleSize();
	Point point;
	int xOry =rand()%2;
	if (xOry==1) {
		point.x=rand()%2*size.width;
		point.y=rand()%(int)size.height;
	}
	else {
		point.x=rand()%(int)size.width;
		point.y=rand()%2*size.height;
	}

	return point;
}

void BattleSystem::addMonster(cocos2d::EventCustom* event)
{
	MonsterData data=((MonsterAddEvent*)event)->data;
	Size size=Director::getInstance()->getVisibleSize();

	auto entity=getECSManager()->createEntity();
	auto sprite=Sprite::create(data.image);
	sprite->setPosition(getMonsterRandomPosition());

	auto body=PhysicsBody::createBox(sprite->getContentSize(),PhysicsMaterial(0.1f, 1, 0.0f));
	sprite->setPhysicsBody(body);

	//怪物和子弹，飞船，枪发生碰撞
	//body->setDynamic(false);
	body->setCollisionBitmask(0);
	body->setCategoryBitmask(monsterCategory);
	body->setContactTestBitmask(shipCategory|gunCategory|gunBulletCategory);
	getNode()->addChild(sprite);

	//node
	auto node=new NodeCom();
	node->node=sprite;
	getECSManager()->addComToEntity(node, entity);
	_monsters.push_back(entity);
	sprite->setUserData(entity);

	//move
	auto move=new MoveCom();
	move->to=Point(size.width-sprite->getPositionX(),size.height-sprite->getPositionY());
	move->speed=data.speed;
	getECSManager()->addComToEntity(move, entity);

	//health
	if (data.hp>0) {
		auto health=new HealthCom();
		health->hp=data.hp;
		getECSManager()->addComToEntity(health, entity);
	}

	//gun
	if (data.bullet_hp>0) {
		auto gun=new  GunCom();
		gun->data.bullet_hp=data.bullet_hp;
		gun->data.bullet_image=data.bullet_image;
		gun->data.bullet_rate=data.bullet_rate;
		gun->data.target=ShipCom::_TYPE;
		gun->data.bullet_speed=data.bullet_speed;

		getECSManager()->addComToEntity(gun, entity);
	}

	auto monster=new MonsterCom();
	if (data.coins>0) {
		monster->type=MonsterType::Coin;
	}
	monster->data=data;
	getECSManager()->addComToEntity(new  MonsterCom(), entity);
}

void BattleSystem::addBullet(cocos2d::EventCustom* event)
{
	auto data=(GunEvent*)event;

	auto entity=getECSManager()->createEntity();

	//node
	auto sprite=cocos2d::Sprite::create(data->data.bullet_image);
	sprite->setPosition(data->position);
	auto body=PhysicsBody::createBox(sprite->getContentSize(),PhysicsMaterial(0.1f, 1, 0.0f));
	sprite->setPhysicsBody(body);

	//怪物子弹


	body->setCollisionBitmask(0);
	if (data->data.target==ShipCom::_TYPE) {
		body->setCategoryBitmask(monsterBulletCategory);
		body->setContactTestBitmask(shipCategory|monsterCategory|gunCategory|gunBulletCategory);

	}else{
		body->setCategoryBitmask(gunBulletCategory);
		body->setContactTestBitmask(shipCategory|monsterCategory|gunCategory|monsterBulletCategory);
	}


	NodeCom* node=new NodeCom();
	node->node=sprite;
	sprite->setUserData(entity);

	getECSManager()->addComToEntity(node, entity);

	getNode()->addChild(node->node);

	//move
	auto move=new MoveCom();
	move->to=data->targetPosition;
	move->speed=data->data.bullet_speed;
	getECSManager()->addComToEntity(move, entity);

	//health
	auto health=new HealthCom();
	health->hp=data->data.bullet_hp;
	getECSManager()->addComToEntity(health, entity);


	_bullets.push_back(entity);
}

bool BattleSystem::onPhysicsContact(cocos2d::PhysicsContact& contact)
{
	auto entityA=(Entity*)contact.getShapeA()->getBody()->getNode()->getUserData();
	auto entityB=(Entity*)contact.getShapeB()->getBody()->getNode()->getUserData();

	if (!dynamic_cast<Entity*>(entityA)||!dynamic_cast<Entity*>(entityB)) {
		return false;
	}

	auto monsterA=(MonsterCom*)entityA->getComByType(MonsterCom::_TYPE);
	auto monsterB=(MonsterCom*)entityB->getComByType(MonsterCom::_TYPE);

	//撞金币
	if ((monsterA&&monsterA->data.coins>0) ||(monsterB&&monsterB->data.coins>0)) {
		CoinsAddEvent* event=new CoinsAddEvent(monsterA?monsterA->data.coins:monsterB->data.coins);
		cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(event);

		auto temp=monsterA?entityA:entityB;
		temp->getNode()->removeFromParent();
		getECSManager()->removeEntity(temp);
	}
	else { //扣血
		auto hA=(HealthCom*)entityA->getComByType(HealthCom::_TYPE);
		auto hB=(HealthCom*)entityB->getComByType(HealthCom::_TYPE);

		if (!hA||!hB) {
			return false;
		}

		int tempA=hA->hp;
		int tempB=hB->hp;

		hA->hp-=tempB;
		hB->hp-=tempA;
	}

	return true;
}

void BattleSystem::onDead(EventCustom* event)
{
	auto dead=(DeadEvent*)event;
	//船,游戏结束
	if (dead->entity->getId()==_ship->getId()) {
		CCLOG("I'm Dead.");
	}
	else {
		auto node=(NodeCom*)dead->entity->getComByType(NodeCom::_TYPE);
		//dead->entity->getNode()->setPhysicsBody(nullptr);
		dead->entity->getNode()->removeFromParent();

		//怪物
		for (auto iter=_monsters.begin(); iter!=_monsters.end(); iter++) {
			if ((*iter)->getId()==dead->entity->getId()) {
				getECSManager()->removeEntity(dead->entity);
				_monsters.erase(iter);
				return;
			}
		}

		//子弹
		for (auto iter=_bullets.begin(); iter!=_bullets.end(); iter++) {
			if ((*iter)->getId()==dead->entity->getId()) {
				getECSManager()->removeEntity(dead->entity);
				_bullets.erase(iter);
				return;
			}
		}

		//武器
		for (auto iter=_bullets.begin(); iter!=_bullets.end(); iter++) {
			if ((*iter)->getId()==dead->entity->getId()) {
				getECSManager()->removeEntity(dead->entity);
				_shopItems.erase(iter);
				return;
			}
		}
	}
}

void BattleSystem::onAttached()
{
	setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	//订阅事件
	auto dispatcher=Director::getInstance()->getEventDispatcher();

	auto listener=cocos2d::EventListenerCustom::create(CoinsAddEvent::_TYPE, std::bind(&BattleSystem::addCoin,this,std::placeholders::_1));
	dispatcher->addEventListenerWithSceneGraphPriority(listener, getNode());

	auto gunListener=cocos2d::EventListenerCustom::create(GunEvent::_TYPE, std::bind(&BattleSystem::addBullet,this,std::placeholders::_1));
	dispatcher->addEventListenerWithSceneGraphPriority(gunListener, getNode());

	auto dead=cocos2d::EventListenerCustom::create(DeadEvent::_TYPE, std::bind(&BattleSystem::onDead,this,std::placeholders::_1));
	dispatcher->addEventListenerWithSceneGraphPriority(dead, getNode());

	auto listener1=cocos2d::EventListenerCustom::create(ShopItemEvent::_TYPE, std::bind(&BattleSystem::addShopItem,this,std::placeholders::_1));
	dispatcher->addEventListenerWithSceneGraphPriority(listener1, getNode());

	auto listener2=cocos2d::EventListenerCustom::create(MonsterAddEvent::_TYPE, std::bind(&BattleSystem::addMonster,this,std::placeholders::_1));
	dispatcher->addEventListenerWithSceneGraphPriority(listener2, getNode());

	auto contactListener=cocos2d::EventListenerPhysicsContact::create();
	contactListener->onContactBegin=CC_CALLBACK_1(BattleSystem::onPhysicsContact, this);
	dispatcher->addEventListenerWithSceneGraphPriority(contactListener, getNode());

	auto entity=(EntityCom*)getComByType(EntityCom::_TYPE);

	//获取商店和进度条对象
	_shop=entity->entities["shop"];
	_progress=entity->entities["progress"];

	auto entities= GameSystem::getInstance()->getECS()->getAllEntitiesPosessingCom(PlayerCom::_TYPE);
	if (!entities.empty()) {
		_player=(PlayerCom*)entities.at(0)->getComByType(PlayerCom::_TYPE);

		//从配置中加载关卡，真实场景是从配置Id动态创建关卡数据对象
		_dataEntity=getECSManager()->createEntity(_player->currentLevel);
		_data=(LevelDataCom*)_dataEntity->getComByType(LevelDataCom::_TYPE);

		//dispatcher->dispatchEvent(new BeginGameEvent(_data->durence));
		auto progress=(ProgressCom*)_progress->getComByType(ProgressCom::_TYPE);
		progress->paused=false;
		progress->durence=_data->durence;
		progress->currentProgress=0;

		//1,从关卡配置中创建船
		Size size=Director::getInstance()->getWinSize();
		_ship=getECSManager()->createEntity();
		GX::NodeCom* node=new GX::NodeCom();
		_shipSprite=cocos2d::Sprite::create(_data->ship_image);
		node->node=_shipSprite;
		_shipSprite->setPosition(Point(size.width/2, size.height/2));
		getECSManager()->addComToEntity(node, _ship);


		//add physics
		auto body=PhysicsBody::createBox(_shipSprite->getContentSize(),PhysicsMaterial(0.1f, 1, 0.0f));
		_shipSprite->setPhysicsBody(body);
		body->setTag(SHIP_DRAG_TAG);


		//body->setDynamic(false);
		body->setCollisionBitmask(0);
		body->setCategoryBitmask(shipCategory);
		body->setContactTestBitmask(monsterCategory|monsterBulletCategory);

		getNode()->addChild(_shipSprite);
		_shipSprite->setUserData(_ship);

		HealthCom* health=new HealthCom();
		health->hp=_data->ship_hp;
		getECSManager()->addComToEntity(health, _ship);

		CoinCom* coin=new CoinCom();
		coin->coin=_data->ship_coin;
		coin->coin_rate=_data->ship_coin_rate;
		getECSManager()->addComToEntity(coin,_ship);

		getECSManager()->addComToEntity(new ShipCom(), _ship);

		//2,初始化倒计时进度条
	}
}

void BattleSystem::onDeattached()
{

}

void BattleSystem::update(float dt)
{

}

void BattleSystem::onComsChanged()
{

}

bool BattleSystem::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	_scene=getNode()->getScene();

	auto location = touch->getLocation();
	auto arr = _scene->getPhysicsWorld()->getShapes(location);

	PhysicsBody* body = nullptr;
	for (auto& obj : arr){
		if ((obj->getBody()->getTag() & SHIP_DRAG_TAG) != 0){
			body = obj->getBody();
			break;
		}
	}

	if (body != nullptr){
		_prevois=touch->getLocation();
		return true;
	}

	return false;
}

void BattleSystem::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	_shipSprite->setPosition(_shipSprite->getPosition()+touch->getLocation()-_prevois);
	for (auto iter=_shopItems.begin(); iter!=_shopItems.end(); iter++) {
		auto node=(*iter)->getNode();
		node->setPosition(node->getPosition()+touch->getLocation()-_prevois);
	}

	_prevois=touch->getLocation();
}

void BattleSystem::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{

}

void BattleSystem::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{

}
