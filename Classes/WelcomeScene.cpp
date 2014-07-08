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

        
        Sprite* sppp=Sprite::create("test/1.png");
        layer->addChild(sppp, 0, 10);
        
        
        //异步加载Texture2D
        Resource::getInstance()->addResourceAsync("a_cardUI_big_1_2.png",[&,sppp](void* data){
            CCLOG("load texture %d success.",((Texture2D*)data)->getName());
            
            sppp->removeFromParent();
        });
        
        auto size1=Director::getInstance()->getWinSize();
        CCLOG("Winsize: w: %f, h:%f",size1.width,size1.height);
        
        auto size2=Director::getInstance()->getWinSizeInPixels();
        CCLOG("getWinSizeInPixels: w: %f, h:%f",size2.width,size2.height);
        
        auto size3=Director::getInstance()->getVisibleSize();
        CCLOG("getVisibleSize: w: %f, h:%f",size3.width,size3.height);
        
        auto point=Director::getInstance()->getVisibleOrigin();
        CCLOG("getVisibleOrigin: w: %f, h:%f",point.x,point.y);

        
        //异步加载自定义文件
        Resource::getInstance()->addResourceAsync("hero.json",[&](void* data){
            CCLOG("load resource: %s success.",typeid(data).name());
        },ComData::_TYPE);
        
        std::unordered_map<std::string,std::string> files;
        //files.insert(std::make_pair("Level.json", ComData::_TYPE));
        //files.insert(std::make_pair("LevelCell.json", ComData::_TYPE));
        files.insert(std::make_pair("test/1.png", "Texture2D"));
        files.insert(std::make_pair("test/2.png", "Texture2D"));
        files.insert(std::make_pair("test/3.png", "Texture2D"));
        files.insert(std::make_pair("test/4.png", "Texture2D"));
        files.insert(std::make_pair("test/5.png", "Texture2D"));
        files.insert(std::make_pair("test/6.png", "Texture2D"));
        files.insert(std::make_pair("test/7.png", "Texture2D"));
        files.insert(std::make_pair("test/8.png", "Texture2D"));
        files.insert(std::make_pair("test/9.png", "Texture2D"));
        files.insert(std::make_pair("test/10.png", "Texture2D"));
        files.insert(std::make_pair("test/11.png", "Texture2D"));
        files.insert(std::make_pair("test/12.png", "Texture2D"));
        files.insert(std::make_pair("test/13.png", "Texture2D"));
        files.insert(std::make_pair("test/14.png", "Texture2D"));
        files.insert(std::make_pair("test/15.png", "Texture2D"));
        files.insert(std::make_pair("test/16.png", "Texture2D"));
        files.insert(std::make_pair("test/17.png", "Texture2D"));
        files.insert(std::make_pair("test/18.png", "Texture2D"));
        files.insert(std::make_pair("test/19.png", "Texture2D"));
        files.insert(std::make_pair("test/20.png", "Texture2D"));
        files.insert(std::make_pair("test/21.png", "Texture2D"));
        files.insert(std::make_pair("test/22.png", "Texture2D"));
        files.insert(std::make_pair("test/23.png", "Texture2D"));
        files.insert(std::make_pair("test/24.png", "Texture2D"));
        files.insert(std::make_pair("test/25.png", "Texture2D"));
        files.insert(std::make_pair("test/26.png", "Texture2D"));
        files.insert(std::make_pair("test/27.png", "Texture2D"));
        files.insert(std::make_pair("test/28.png", "Texture2D"));
        files.insert(std::make_pair("test/29.png", "Texture2D"));
        files.insert(std::make_pair("test/30.png", "Texture2D"));
        files.insert(std::make_pair("test/31.png", "Texture2D"));
        files.insert(std::make_pair("test/32.png", "Texture2D"));
        files.insert(std::make_pair("test/33.png", "Texture2D"));
        files.insert(std::make_pair("test/34.png", "Texture2D"));
        files.insert(std::make_pair("test/35.png", "Texture2D"));
        files.insert(std::make_pair("test/36.png", "Texture2D"));

        Resource::getInstance()->addResourceReference(files);
        Resource::getInstance()->updateResourceReferenceAsync([files](){
            auto r=(ResourceDataDelegate*)Resource::getInstance()->addResource("Level.json",ComData::_TYPE);
            CCLOG("%s,",r->getType().c_str());
            
            CCLOG("reference: %d",Resource::getInstance()->getResourceReference("Level.json"));
            CCLOG("reference: %d",Resource::getInstance()->getResourceReference("LevelCell.json"));
            
            std::vector<std::string> strs;
            strs.push_back("test/1.png");
            strs.push_back("test/2.png");
            strs.push_back("test/3.png");
            strs.push_back("test/4.png");
            strs.push_back("test/5.png");
            strs.push_back("test/6.png");
            strs.push_back("test/7.png");
            strs.push_back("test/8.png");
            strs.push_back("test/9.png");
            strs.push_back("test/10.png");
            strs.push_back("test/11.png");
            strs.push_back("test/12.png");
            strs.push_back("test/13.png");
            strs.push_back("test/14.png");
            strs.push_back("test/15.png");
            strs.push_back("test/16.png");
            strs.push_back("test/17.png");
            strs.push_back("test/18.png");
            strs.push_back("test/19.png");
            strs.push_back("test/20.png");
            
            Resource::getInstance()->removeResourceReference(strs);
            Resource::getInstance()->updateResourceReferenceAsync([](){
                CCLOG("reference test/1.png: %d",Resource::getInstance()->getResourceReference("test/1.png"));
            });
        });
        
        return layer;
    }
    
    return nullptr;
}