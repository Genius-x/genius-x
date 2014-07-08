//
//  BattleScene.cpp
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#include "BattleScene.h"

USING_NS_CC;

Scene* BattleScene::scene(const std::string& level)
{
    Scene *scene = Scene::createWithPhysics();
    Size size=Director::getInstance()->getVisibleSize();
    
    //通过ECS创建场景
    auto layer=new BattleScene();
    if( layer && layer->initWithColor(Color4B(255*0.91,255*0.91,255*0.91,255),size.width,size.height))
    {
        layer->autorelease();
        
        scene->getPhysicsWorld()->setGravity(Vect(0,0));

        GX::Entity* welcome=GX::GameSystem::getInstance()->getECS()->createEntity("Battle.json");
        layer->addChild(welcome->getNode());
        scene->addChild(layer);
    }
    
    return scene;
}