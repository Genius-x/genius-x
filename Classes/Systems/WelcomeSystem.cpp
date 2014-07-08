//
//  WelcomeSystem.cpp
//  sg
//
//  Created by Elvis on 3/20/14.
//
//

#include "WelcomeSystem.h"
#include "genius-x.h"
#include "../Coms/WelcomeCom.h"
#include "../LevelScene.h"

using namespace cocos2d::ui;

WelcomeSystem::WelcomeSystem():GX::System("WelcomeSystem",WelcomeCom::_TYPE)
{
    
}

GX::System* WelcomeSystem::cloneEmpty() const
{
    return new WelcomeSystem();
}

void WelcomeSystem::onInit()
{
    
}

void WelcomeSystem::onAttached()
{
    auto node=(GX::NodeCom*)getComByType(GX::NodeCom::_TYPE);
    if (node) {
        auto play=(cocos2d::ui::Button*)node->getNodeByName("play");
        if (play) {
            play->setTouchEnabled(true);
            play->addTouchEventListener(this, toucheventselector(WelcomeSystem::onPlayClicked));
        }
        
        auto shop=(cocos2d::ui::Button*)node->getNodeByName("shop");
        if (shop) {
            shop->setTouchEnabled(true);
            shop->addTouchEventListener(this, toucheventselector(WelcomeSystem::onShopClicked));
        }
    }
}

void WelcomeSystem::onDeattached()
{
    
}

void WelcomeSystem::update(float dt)
{
    
}

void WelcomeSystem::onComsChanged()
{
    
}

void WelcomeSystem::onPlayClicked(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type)
{
    cocos2d::Director::getInstance()->replaceScene(LevelScene::scene());
}

void WelcomeSystem::onShopClicked(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type)
{
    //cocos2d::Director::getInstance()->replaceScene(ShopScene::scene());
}
