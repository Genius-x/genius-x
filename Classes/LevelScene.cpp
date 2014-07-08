//
//  LevelScene.cpp
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#include "LevelScene.h"
#include "genius-x.h"

USING_NS_CC;

LevelScene::~LevelScene()
{
    //GX::GameSystem::getInstance()->getECS()->removeEntity(_entity);
}


Scene* LevelScene::scene()
{
    Scene *scene = CCScene::create();
    Size size=Director::getInstance()->getVisibleSize();
    
    //通过ECS创建场景
    auto layer=new LevelScene();
    if( layer && layer->initWithColor(Color4B(255*0.91,255*0.91,255*0.91,255),size.width,size.height))
    {
        layer->autorelease();
        
        layer->_entity=GX::GameSystem::getInstance()->getECS()->createEntity("Level.json");
        layer->addChild(layer->_entity->getNode());
        scene->addChild(layer);
    }
    
    return scene;
}