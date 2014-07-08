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

#include "DragSystem.h"
USING_NS_GX;


std::string GX::DragSystem::_TYPE="DragSystem";

GX::DragSystem::DragSystem()
:GX::System(_TYPE,DragCom::_TYPE)
,_drag(nullptr)
,_originPosition(Vec2::ZERO)
,_originZOrder(0)
,_isMoving(false)
{
    
}

GX::System* GX::DragSystem::cloneEmpty() const
{
    return new GX::DragSystem();
}

void GX::DragSystem::onAttached()
{
    _drag=(DragCom*)getComByType(DragCom::_TYPE);
    
    setTouchEnabled(true);
    setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
}

void GX::DragSystem::onDeattached()
{
    
}

bool DragSystem::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    for (Node* c = getNode()->getParent(); c !=nullptr; c = c->getParent())
        if (c-> isVisible() == false)
            return false;
    
    if(_isMoving){
        return false;
    }
    
    Rect frame=Rect(0, 0, getNode()->getContentSize().width,getNode()->getContentSize().height);
    if(!frame.containsPoint(getNode()->convertTouchToNodeSpace(touch)))
    {
        return false;
    }
    
    _isMoving=false;
    _beginPont=getNode()->getParent()->convertToWorldSpace(getNode()->getPosition());
    _touchPoint= getNode()->convertTouchToNodeSpace(touch);
    return true;}

void DragSystem::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    Vec2 currentPoint  = getNode()->convertTouchToNodeSpace(touch);
    Vec2 moveDistance = currentPoint-_touchPoint;
    if(!_isMoving&&currentPoint.getDistance(_touchPoint)>SingleClickDistance&&_drag->onBeginMove(getNode(), touch->getLocation()))
    {
        _isMoving=true;
        
        if(_drag->_clickable||_drag->_dragable)
        {
            if (_drag->_localZOrderChanged) {
                _originZOrder=_drag->_localZOrder;
                getNode()->setLocalZOrder(_originZOrder);
            }
            else if(_drag->_globalZOrderChanged) {
                _originZOrder=_drag->_globalZOrder;
                getNode()->setGlobalZOrder(_originZOrder);
            }
            
            _originPosition=getNode()->getPosition();
        }
    }
    
    if(_isMoving)
    {
        Vec2 point=Point(getNode()->getPositionX()+moveDistance.x,getNode()->getPositionY()+moveDistance.y);
        
        //move position
        getNode()->setPosition(point);
        _drag->onMoving(getNode(), touch->getLocation());
    }
}

void DragSystem::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    if(!_isMoving) //single click
    {
        _drag->onNodeClicked(getNode());
    }
    else if(_drag->onMoved(getNode(),touch->getLocation()))
    {
        //if handled, do not do anything, the handle method must take care the node.
        _isMoving=false;
    }
    else
    {
        //or,move back to origin position, and set the node to it's origin parent
        setTouchEnabled(false);
        getNode()->runAction(CCSequence::create(CCMoveTo::create(0.3f, _originPosition),
                                                CallFunc::create([this](){
            //set back to the origin layer
            _isMoving=false;
            getNode()->setPosition(_originPosition);
            
            if (_drag->_localZOrderChanged) {
                getNode()->setLocalZOrder(_originZOrder);
            }
            else if (_drag->_globalZOrderChanged){
                getNode()->setGlobalZOrder(_originZOrder);
            }
            
            setTouchEnabled(true);
            _drag->onMovebacked();
            

        }),nullptr));
    }
}

void DragSystem::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    getNode()->setPosition(_beginPont);
    _isMoving=false;

}