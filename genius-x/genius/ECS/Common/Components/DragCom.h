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

#ifndef __cocos2d_libs__DragCom__
#define __cocos2d_libs__DragCom__

#include "cocos2d.h"
#include "../../../GXMacros.h"
#include "../../Com.h"
#include "../../Entity.h"

NS_GX_BEGIN
class DragSystem;

/**
 * 用来拖动一个该Entity对应的Node
 */
class DragCom :public GX::Com
{
public:
    static std::string _TYPE;
    DragCom();
    
    static DragCom* create(){return new DragCom();}
    
    /**
     * 能否开始拖动
     */
    std::function<bool(Node*,const Vec2)> beginMove;
    
    /**
     * 拖动中
     */
    std::function<void(Node*,const Vec2)> moving;
    
    /**
     * 移动完成，返回结果告诉是否需要处理，如果为false则将移回原来的位置
     */
    std::function<bool(Node*,const Vec2)> moved;
    
    /**
     * 返回到原来的位置
     */
    std::function<void()> movebacked;
    
    /**
     * 单击
     */
    std::function<void(Node*)> nodeClicked;
    
    void setLocalZOrder(int order);
    void setGlobalZOrder(int order);
    void setTouchBehavior(bool draggable,bool clickable);
    
protected:
    
    bool onBeginMove(Node*,const Vec2);
    void onMoving(Node*,const Vec2);
    bool onMoved(Node*,const Vec2);
    void onMovebacked();
    
    void onNodeClicked(Node*);
    
    virtual void initWithMap(rapidjson::Value&) override;
    virtual Com* cloneEmpty() const override;
    
private:
    int _localZOrder;
    int _globalZOrder;
    bool _localZOrderChanged;
    bool _globalZOrderChanged;
    bool _dragable;
    bool _clickable;
    
    friend DragSystem;
};

NS_GX_END

#endif /* defined(__cocos2d_libs__DragCom__) */
