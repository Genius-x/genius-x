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

#include "Entity.h"
#include "System.h"
#include "Com.h"
#include "Common/Components/NodeCom.h"

USING_NS_GX;

Entity::Entity()
:__beMoving(false)
,__jsonData(nullptr)
{
    
}

Entity::~Entity()
{
    if (__jsonData!=nullptr) {
        __jsonData->release();
    }
    
    CCLOG("Entity: %d be deleted.",_id);
}

//bool Entity::operator==(const Entity& right) const
//{
//    return right._id == _id;
//}

//bool Entity::operator!=(const Entity& right) const
//{
//    return !(*this == right);
//}


void Entity::setComData(ComData* data)
{
    CCASSERT(data!=nullptr, "data can't be nil.");
    
    if (__jsonData!=nullptr) {
        __jsonData->release();
        
        __jsonData=data;
        __jsonData->retain();
    }
}

Entity* Entity::createWithId(const entity_id_type& id)
{
    Entity* entity=new Entity();
    if(entity){
        entity->initWithId(id);
        return entity;
    }
    
    delete entity;
    return nullptr;
}

void Entity::initWithId(const entity_id_type& id)
{
    _id=id;
    CCLOG("Entity: %d be created.",_id);
}

GX::Com* Entity::getComByType(const std::string& type)
{    
    auto Com=_coms.find(type);
    if (Com!=_coms.end()) {
        return Com->second;
    }
    
    return nullptr;
}

void Entity::removeCom(const std::string& type)
{
    Com* com=getComByType(type);
    if (com!=nullptr) {
        //1，移除对应的System
        auto iter=_systems.begin();
        while (iter!=_systems.end()) {
            if (iter->second->firstType()==type) {
               iter->second->onDeattached();
               delete iter->second;
               iter= _systems.erase(iter);
            }
            else {
                iter++;
            }
        }
        
        //2,移除Com
        _coms.erase(com->getType());
        com->release();
    }
}

cocos2d::Node* Entity::getNode()
{
    NodeCom* node= (NodeCom*)getComByType(NodeCom::_TYPE);
    
    if (node!=nullptr) {
        return node->node;
    }
    
    return nullptr;
}

void Entity::sortSystem()
{
    //std::sort(_systems.begin(), _systems.end(),sortSystem);
}

void Entity::removeAllComs()
{
    for (auto iter=_coms.begin(); iter!=_coms.end();) {
        const std::string& type=iter->first;
        iter++;
        removeCom(type);
    }
}

void Entity::ComsChanged()
{
    for (auto iter=_systems.begin(); iter!=_systems.end(); iter++) {
        iter->second->onComsChanged();
    }
}

std::string Entity::toJson()
{
    return nullptr;
}

std::string Entity::toXML()
{
    return nullptr;
}