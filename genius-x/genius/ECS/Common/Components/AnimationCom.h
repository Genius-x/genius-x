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

#ifndef __GX__AnimationCom__
#define __GX__AnimationCom__

#include <iostream>
#include "cocos2d.h"
#include "../../../GXMacros.h"
#include "../../Com.h"

NS_GX_BEGIN

//USING_NS_CC;

/*
 * 给Entity的Node定义一个或多个关键帧动画，以及动画的相关属性，程序中直接通过Id播放
 *  "type": "AnimationCom",
 *  "filename": "woc_change_black.plist",
 *  "animations": [
 *   {
 *      "name": "change"
 *    },
 *    {
 *      "name": "black"
 *    }
 *  ]
 */
class AnimationCom :public GX::Com
{
    struct AnimationDefinition {
        
        AnimationDefinition()
        :position(cocos2d::Point(0.0f,0.0f))
        ,anchorPoint(cocos2d::Point(0.5f, 0.5f))
        ,localZOrder(0)
        ,loops(1)
        ,autoPlay(false)
        ,delayPerUnit(0.0)
        ,scale(cocos2d::Point(1.0f, 1.0f))
        {};
        
        AnimationDefinition(std::string aName,cocos2d::Point aPosition,cocos2d::Point aAnchorPoint,int aLocalZOrder,int aLoops,bool aAutoPlay,float aDelayPerUnit,cocos2d::Point aScale)
        :name(aName)
        ,position(aPosition)
        ,anchorPoint(aAnchorPoint)
        ,localZOrder(aLocalZOrder)
        ,loops(aLoops)
        ,autoPlay(aAutoPlay)
        ,delayPerUnit(aDelayPerUnit)
        ,scale(aScale)
        {};
        
        std::string name;
        cocos2d::Point position;
        cocos2d::Point anchorPoint;
        int localZOrder;
        int loops;
        bool autoPlay;
        float delayPerUnit;
        cocos2d::Point scale;
    };
    
public:
    static std::string _TYPE;
    AnimationCom();
    
    std::string filename;
    std::map<std::string,AnimationDefinition> animations;
    
    cocos2d::Animation* getAnimation(const std::string& name);
    
    void playAnimation(const std::string& name,cocos2d::Node* parent,std::function<void()> callback = nullptr,const cocos2d::Point& point=cocos2d::Point::ZERO);
protected:
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
};

NS_GX_END

#endif /* defined(__GX__AnimationCom__) */
