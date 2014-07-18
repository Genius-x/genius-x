/****************************************************************************
 Copyright (c) 2014 Elvis Qin
 Copyright (c) 2014 Soulgame Inc.
 
 http://www.genius-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __GX__NodeCom__
#define __GX__NodeCom__

#include "cocos2d.h"
#include "../../../GXMacros.h"
#include "../../Com.h"
#include "ui/UIButton.h"
#include "cocos-ext.h"

NS_GX_BEGIN
USING_NS_CC;

/*
 * 用来创建一个扁平的UI结构,NodeCom可以包含一个或者多个(集合)子元素
 *
 * hero.xml:(name要对应Com中的属性名字，设计者是不能修改的)
 * <Node>
 *  <Label name="heroname" size="24" font="arial.ttf" globalOrder="1"></Label>
 *  <Sprite name="avatar" file="avatar.png" order="2"></Sprite>
 *  <Label name="description" order="0"></Label>
 * </Node>
 *
 * 如果只有一个子元素，直接包含该元素，否则创建一个空的Node作为容器
 * 其它Com通过node->getChildByName("heroname")查找元素引用
 *
 * Entity* hero=ECSManager::getInstance()->createEntity("hero.xml");
 * addChild(hero->getNode());
 *
 * 在HeroSystem:
 * if(getNode()) {
 *  Label* lblTitle=getNode()->getChildByName("title");
 *  lblTitle->setSring(getCom("HeroCom")->title);
 * }
 *
 *
 * anchor仅用于顶级元素，对于非顶级元素，其大小，位置都是固定的，顶级元素的大小也是固定的，但是位置是不固定
 * anchor仅用于修正在全屏的位置
 */
class NodeCom :public GX::Com
{
    static const int DEFAULT_CAPACITY = 29;
    
public:
    Node* node;
    
    static std::string _TYPE;
    NodeCom();
    
    // for lua
    static NodeCom* create();
    Node* getNode(){return node;}
    void setNode(Node*);
    
    Node* getNodeByName(const std::string& name) const;
    
    //支持压缩纹理等特殊处理
    static Sprite* createSprite(const std::string& filename);
    static Sprite* createSprite(const std::string& filename, const Rect& rect);
    
    static SpriteBatchNode* createSpriteBatchNode(const std::string& fileImage, ssize_t capacity = DEFAULT_CAPACITY);
    static AtlasNode * createAtlasNode(const std::string& filename, int tileWidth, int tileHeight, int itemsToRender);
    static TileMapAtlas * createTileMapAtlas(const std::string& tile, const std::string& mapFile, int tileWidth, int tileHeight);
    static TMXTiledMap* createTMXTiledMap(const std::string& tmxFile);
    static TMXTiledMap* createTMXTiledMapWithXML(const std::string& tmxString, const std::string& resourcePath);
    
protected:
    cocos2d::Sprite* initSprite(rapidjson::Value&);
    cocos2d::Label* initLabel(rapidjson::Value&);
    cocos2d::Layer* initLayer(rapidjson::Value&);
    cocos2d::ui::Button* initButton(rapidjson::Value&);
    cocos2d::extension::TableView* initTable(rapidjson::Value&);
    cocos2d::ProgressTimer* initTimer(rapidjson::Value&);
    
    cocos2d::Point getRealPosition(const cocos2d::Size& size, const cocos2d::Point& pos,const cocos2d::Point& alignment) const;
    
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
    
    std::map<std::string,cocos2d::Node*> __nodeNames;
};

NS_GX_END

#endif /* defined(__GX__NodeCom__) */
