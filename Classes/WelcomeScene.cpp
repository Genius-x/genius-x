//
//  WelcomeScene.cpp
//  sg
//
//  Created by Elvis on 3/24/14.
//
//

#include "WelcomeScene.h"
#include "genius-x.h"
#include <vector>

USING_NS_CC;
USING_NS_GX;

WelcomeScene::~WelcomeScene()
{
    GameSystem::getInstance()->getECS()->removeEntity(_welcomeEntity);
}

Scene* WelcomeScene::scene()
{
    Scene *scene = CCScene::create();

    //通过ECS创建场景
    auto layer=WelcomeScene::create();
    scene->addChild(layer);

    return scene;
}

WelcomeScene* WelcomeScene::create()
{
    Size size=Director::getInstance()->getVisibleSize();
    
    WelcomeScene* layer=new WelcomeScene();
    if( layer && layer->initWithColor(Color4B(255*0.91,255*0.91,255*0.91,255),size.width,size.height))
    {
        layer->autorelease();
        layer->_welcomeEntity=GX::GameSystem::getInstance()->getECS()->createEntity("welcome.json");
        layer->addChild(layer->_welcomeEntity->getNode());
        
        return layer;
    }
    
    return nullptr;
}