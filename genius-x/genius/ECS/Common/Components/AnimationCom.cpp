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

#include "AnimationCom.h"
USING_NS_GX;

std::string AnimationCom::_TYPE="AnimationCom";

AnimationCom::AnimationCom()
:Com(_TYPE)
{
    
}

void GX::AnimationCom::initWithMap(rapidjson::Value& value)
{
    if (value.HasMember("filename")&& value.HasMember("animations")&&value["animations"].Size()) {
        filename=value["filename"].GetString();
        
        int count=value["animations"].Size();
        for (int i=0; i<count; i++) {
            rapidjson::Value& entity=value["animations"][i];
            
            if (entity.HasMember("name")) {
                AnimationDefinition definition;
                definition.name=entity["name"].GetString();
                
                if (entity.HasMember("position")) {
                    definition.position=cocos2d::PointFromString(entity["position"].GetString());
                }
                
                if(entity.HasMember("anchorPoint")){
                    definition.anchorPoint=cocos2d::PointFromString(entity["anchorPoint"].GetString());
                }

                if(entity.HasMember("scale")){
                    definition.scale=cocos2d::PointFromString(entity["scale"].GetString());
                }

                if(entity.HasMember("localZOrder")){
                    definition.localZOrder=entity["localZOrder"].GetInt();
                }
                
                if(entity.HasMember("loops")){
                    definition.loops=entity["loops"].GetInt();
                }
                
                if(entity.HasMember("autoPlay")){
                    definition.autoPlay=entity["autoPlay"].GetBool();
                }
                
                if(entity.HasMember("delayPerUnit")){
                    definition.delayPerUnit=(float)entity["delayPerUnit"].GetDouble();
                }
                
                animations.insert(std::make_pair(definition.name, definition));
            }
        }
    }
}

GX::Com* AnimationCom::cloneEmpty() const
{
    return new AnimationCom();
}

cocos2d::Animation* getAnimation(const std::string& name)
{
    auto cache = cocos2d::AnimationCache::getInstance();
    return cache->getAnimation(name);
}

void AnimationCom::playAnimation(const std::string& name,cocos2d::Node* parent,std::function<void()> callback,const cocos2d::Point& point)
{
    auto iter=animations.find(name);
    if (iter!=animations.end()) {
        auto cache = cocos2d::AnimationCache::getInstance();
        auto animation = cache->getAnimation(name);
        auto action2 = cocos2d::Animate::create(animation);
        
        auto animationFrame=animation->getFrames().at(0);
        
        cocos2d::Sprite* sprite=cocos2d::Sprite::createWithSpriteFrame(animationFrame->getSpriteFrame());
        sprite->setAnchorPoint(iter->second.anchorPoint);
        
        if (point.equals(cocos2d::Point::ZERO)) {
            sprite->setPosition(iter->second.position);
        }
        else{
            sprite->setPosition(point);
        }
        
        sprite->setScale(iter->second.scale.x, iter->second.scale.y);
        sprite->setLocalZOrder(iter->second.localZOrder);
        parent->addChild(sprite);
        
        //animation->setDelayPerUnit(iter->second.delayPerUnit);
        //animation->setLoops(iter->second.loops);
        
        sprite->runAction(cocos2d::Sequence::create(action2, cocos2d::RemoveSelf::create(), NULL));
    }
}