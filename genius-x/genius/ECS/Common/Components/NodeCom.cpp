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

#include "NodeCom.h"
#include "../../../genius-x.h"
#include "../../../GameSystem/Localization.h"

USING_NS_GX;

std::string NodeCom::_TYPE="NodeCom";

NodeCom* NodeCom::create()
{
    return new NodeCom();
}

NodeCom::NodeCom()
:Com(_TYPE)
,node(nullptr)
{
    
}

GX::Com* NodeCom::cloneEmpty() const
{
    return new NodeCom();
}

cocos2d::Point NodeCom::getRealPosition(const cocos2d::Size& size,const cocos2d::Point& pos,const cocos2d::Point& alignment) const
{
    float x,y;
    if (alignment.x==1)
        x=size.width-pos.x;
    else
        x=size.width*alignment.x+pos.x;
    
    if (alignment.y==1)
        y=size.height-pos.y;
    else
        y=size.height*alignment.y+pos.y;
    
    return cocos2d::Point(x,y);
}

void NodeCom::initWithMap(rapidjson::Value& value)
{
    auto visibleSize=Director::getInstance()->getVisibleSize();
    
    node=cocos2d::Node::create();
    if (value.HasMember("contentSize")) {
        auto size=cocos2d::SizeFromString(value["contentSize"].GetString());
        if (size.width<0)
            size.width=visibleSize.width;
        
        if (size.height<0)
            size.height=visibleSize.height;
        
        node->setContentSize(size);
    }
    else {
        node->setContentSize(visibleSize);
    }
    
    if (value.HasMember("anchorPoint")) {
        node->setAnchorPoint(cocos2d::PointFromString(value["anchorPoint"].GetString()));
    }
        
    cocos2d::Point position=value.HasMember("position")?cocos2d::PointFromString(value["position"].GetString()):cocos2d::Point::ZERO;
    if (value.HasMember("anchor")) {
        node->setPosition(getRealPosition(cocos2d::Director::getInstance()->getVisibleSize(),
                                              position,
                                              cocos2d::PointFromString(value["anchor"].GetString())));
    }
    else if (value.HasMember("position")) {
        node->setPosition(cocos2d::PointFromString(value["position"].GetString()));
    }

    if (value.HasMember("Node")) {
        
        int count=value["Node"].Size();
        for (int i=0; i<count; i++) {
            rapidjson::Value& nodeValue=value["Node"][i];
            if (!nodeValue.IsNull()&&nodeValue.HasMember("type")) {
                const char* type=nodeValue["type"].GetString();
                cocos2d::Node* child=nullptr;
                
                if (strcmp("Label", type)==0) {
                    child=initLabel(nodeValue);
                }
                else if (strcmp("Sprite", type)==0) {
                    child=initSprite(nodeValue);
                }
                else if (strcmp("Layer", type)==0) {
                    child=initLayer(nodeValue);
                }
                else if (strcmp("Button", type)==0) {
                    child=initButton(nodeValue);
                }
                else if (strcmp("TableView", type)==0){
                    child=initTable(nodeValue);
                }
                else if (strcmp("ProgressTimer", type)==0){
                    child=initTimer(nodeValue);
                }
                    
                
                if (child!=nullptr) {
                    node->addChild(child);

                    if (nodeValue.HasMember("name")) {
                        const char* name= nodeValue["name"].GetString();
                        __nodeNames.insert(std::make_pair(name, child));
                    }
                    
                    if (nodeValue.HasMember("scale")) {
                        cocos2d::Point point=cocos2d::PointFromString(nodeValue["scale"].GetString());
                        child->setScale(point.x, point.y);
                    }

                    if (nodeValue.HasMember("position")) {
                        child->setPosition(cocos2d::PointFromString(nodeValue["position"].GetString()));
                    }
                    
                    if (nodeValue.HasMember("anchorPoint")) {
                        child->setAnchorPoint(cocos2d::PointFromString(nodeValue["anchorPoint"].GetString()));
                    }
                    
                    if (nodeValue.HasMember("localZOrder")) {
                        child->setLocalZOrder(nodeValue["localZOrder"].GetInt());
                    }
                    
                    if (nodeValue.HasMember("globalOrder")) {
                        child->setGlobalZOrder((float)nodeValue["globalOrder"].GetInt());
                    }
                    
                    if (nodeValue.HasMember("visible")) {
                        child->setVisible(nodeValue["visible"].GetBool());
                    }

                    if (nodeValue.HasMember("tag")) {
                        child->setTag(nodeValue["tag"].GetInt());
                    }
                    
                    //如果声明了anchor，则按照新的规则布局
                    cocos2d::Point position1=nodeValue.HasMember("position")? cocos2d::PointFromString(nodeValue["position"].GetString()):cocos2d::Point::ZERO;
                    if (nodeValue.HasMember("anchor")) {
                        child->setPosition(getRealPosition(node->getContentSize(), position1, cocos2d::PointFromString(nodeValue["anchor"].GetString())));
                    }
                    else if (nodeValue.HasMember("position")) {
                        child->setPosition(position1);
                    }
                }
            }
        }
    }
}

cocos2d::Sprite* NodeCom::initSprite(rapidjson::Value& value)
{
    cocos2d::Sprite* sprite=nullptr;
    if (value.HasMember("filename")) {
        const char* filename=value["filename"].GetString();
        sprite=cocos2d::Sprite::create(filename);
    }
    else {
        sprite=cocos2d::Sprite::create();
    }
    
    return sprite;
}

cocos2d::Label* NodeCom::initLabel(rapidjson::Value& value)
{
    if (value.IsNull()||!value.HasMember("font")) {
        return nullptr;
    }
    
    auto local=GX::Localization::getInstance();
    
    std::string text=value.HasMember("text")?
        local->getStr(value["text"].GetString()).c_str():"";
    std::string font=local->getStr(value["font"].GetString()).c_str();
    cocos2d::Value s(GX::Localization::getInstance()->getStr(value["fontSize"].GetString()));
    int size=s.asInt();
    
    cocos2d::Label* label=cocos2d::Label::createWithTTF(text, font, (float)size);
    
    if (value.HasMember("fontColor")) {
        label->setTextColor(Color4BFromString(value["fontColor"].GetString()));
    }
    
    if (value.HasMember("textVAlignment")) {
        const char* str=value["textVAlignment"].GetString();
        if (strcmp("top", str)==0) {
            label->setVerticalAlignment(cocos2d::TextVAlignment::TOP);
        }
        else if(strcmp("center", str)==0){
            label->setVerticalAlignment(cocos2d::TextVAlignment::CENTER);
        }
        else if(strcmp("bottom", str)==0){
            label->setVerticalAlignment(cocos2d::TextVAlignment::BOTTOM);
        }
    }
    
    if (value.HasMember("textHAlignment")) {
        const char* str=value["textHAlignment"].GetString();
        if (strcmp("left", str)==0) {
            label->setHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
        }
        else if(strcmp("center", str)==0){
            label->setHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
        }
        else if(strcmp("right", str)==0){
            label->setHorizontalAlignment(cocos2d::TextHAlignment::RIGHT);
        }
    }

    return label;
}

cocos2d::ui::Button* NodeCom::initButton(rapidjson::Value& value)
{
    cocos2d::ui::Button* button=cocos2d::ui::Button::create();
    auto local=GX::Localization::getInstance();
    
    
    if (value.HasMember("titleText")) {
        button->setTitleText( local->getStr(value["titleText"].GetString()));
    }
    
    if (value.HasMember("titleFont")) {
        button->setTitleFontName(local->getStr(value["titleFont"].GetString()));
    }
    
    if (value.HasMember("titleSize")) {
        button->setTitleFontSize((float)value["titleSize"].GetInt());
    }
    
    if (value.HasMember("titleColor")) {
        button->setTitleColor(cocos2d::Color3B::BLACK);
    }
    
    if (value.HasMember("normal")) {
        button->loadTextureNormal(value["normal"].GetString());
    }
    return button;
}

cocos2d::extension::TableView* NodeCom::initTable(rapidjson::Value& value)
{
    cocos2d::extension::TableView* table=cocos2d::extension::TableView::create();
    return table;
}

cocos2d::ProgressTimer* NodeCom::initTimer(rapidjson::Value& value)
{
    auto sprite=cocos2d::Sprite::create(value["filename"].GetString());
    cocos2d::ProgressTimer* timer=cocos2d::ProgressTimer::create(sprite);
    auto to1 = cocos2d::ProgressTo::create(2, 100);
    timer->setType(cocos2d::ProgressTimer::Type::BAR);
    //    Setup for a bar starting from the left since the midpoint is 0 for the x
    timer->setMidpoint(cocos2d::Point(0,0));
    //    Setup for a horizontal bar since the bar change rate is 0 for y meaning no vertical change
    timer->setBarChangeRate(cocos2d::Point(1, 0));
    //timer->setPosition(Point(100, s.height/2));
    //timer->runAction( cocos2d::RepeatForever::create(to1));
    timer->setPercentage(100.0f);
    return timer;
}

cocos2d::Layer* NodeCom::initLayer(rapidjson::Value&)
{
    cocos2d::Layer * layer=cocos2d::Layer::create();
    return layer;
}

void NodeCom::setNode(Node* n)
{
    if (node==nullptr) {
        node=n;
    }
    else {
        node->addChild(n);
    }
}

Node* NodeCom::getNodeByName(const std::string& name) const
{
    auto iter=__nodeNames.find(name);
    if (iter!=__nodeNames.end()) {
        return iter->second;
    }
    
    return nullptr;
}


Sprite* NodeCom::createSprite(const std::string& filename)
{
    return Sprite::create(filename);
}

Sprite* NodeCom::createSprite(const std::string& filename, const Rect& rect)
{
    return Sprite::create(filename, rect);
}

SpriteBatchNode* NodeCom::createSpriteBatchNode(const std::string& fileImage, ssize_t capacity)
{
    return SpriteBatchNode::create(fileImage,capacity);
}

AtlasNode * NodeCom::createAtlasNode(const std::string& filename, int tileWidth, int tileHeight, int itemsToRender)
{
    return AtlasNode::create(filename, tileWidth, tileHeight, itemsToRender);
}

TileMapAtlas * NodeCom::createTileMapAtlas(const std::string& tile, const std::string& mapFile, int tileWidth, int tileHeight)
{
    return TileMapAtlas::create(tile, mapFile, tileWidth, tileHeight);
}

TMXTiledMap* NodeCom::createTMXTiledMap(const std::string& tmxFile)
{
    return TMXTiledMap::create(tmxFile);
}

TMXTiledMap* NodeCom::createTMXTiledMapWithXML(const std::string& tmxString, const std::string& resourcePath)
{
    return TMXTiledMap::createWithXML(tmxString, resourcePath);
}
