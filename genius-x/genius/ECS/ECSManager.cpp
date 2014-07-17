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

#include "ECSManager.h"
#include "../Resource/Resource.h"
#include "../Resource/ComData.h"

#include "Common/Systems/NodeSystem.h"
#include "Common/Components/NodeCom.h"

#include "Common/Systems/AnimationSystem.h"
#include "Common/Components/AnimationCom.h"

#include "Common/Systems/EntitySystem.h"
#include "Common/Components/EntityCom.h"

#include "Common/Systems/TestSystem.h"
#include "Common/Components/TestCom.h"

#include "../Community/DragCom.h"

#include "json/stringbuffer.h"
#include "json/writer.h"

USING_NS_GX;

ECSManager* ECSManager::create()
{
    return new ECSManager();
}

ECSManager::ECSManager()
{
    _entities.reserve(50);
    _lowestUnassignedEid=1;
    
    //系统组件
    registerSystem(new NodeSystem());
    registerCom(new NodeCom());
    
    registerSystem(new AnimationSystem());
    registerCom(new AnimationCom());
    
    registerSystem(new EntitySystem());
    registerCom(new EntityCom());
    
    registerCom(new DragCom());
    registerSystem(new DragSystem());
    
    registerSystem(new TestSystem());
    registerCom(new TestCom());
}

ECSManager::~ECSManager()
{
    //移除所有Com，System
    removeAllCom();
    
    //移除所有Entity游戏对象
    for (auto iter=_entities.begin(); iter!=_entities.end(); iter++) {
        (*iter)->release();
    }
    
    //移除所有模板System
    for (auto iter=__unuseSystems.begin(); iter!=__unuseSystems.end(); iter++) {
        (*iter)->release();
    }
    
    _entities.clear();
    __unuseSystems.clear();
}


bool __findEntity(const std::vector<Entity*>& entities,entity_id_type id)
{
    for (auto iter=entities.begin(); iter!=entities.end(); iter++) {
        if ((*iter)->getId()==id) {
            return true;
        }
    }
    
    return false;
}

entity_id_type ECSManager::generateNewEid()
{
    if (_lowestUnassignedEid < UINT32_MAX){
         return _lowestUnassignedEid++;
    }
    
    return 0;
}

Entity* ECSManager::createEntity()
{
    entity_id_type id=generateNewEid();
    Entity* entity=Entity::createWithId(id);
    
    //任何时候，新加一个Entity添加到__beAdding数组中
    __beAdding.pushBack(entity);
    return entity;
}

// 从配置文件创建游戏对象
Entity* ECSManager::createEntity(const std::string& filename)
{
    auto data=(ComData*)Resource::getInstance()->addResource(filename,ComData::_TYPE);
    if (data!=nullptr) {
        rapidjson::Value& root=data->data;
        if (!root.IsNull()&&root.Size()>0) {
            Entity* entity=createEntity();
            
            CCLOG("Created Entity: %d with filename: %s",entity->getId(),filename.c_str());
            
            int count=root.Size();
            for (int i=0; i<count; i++) {
                rapidjson::Value& comValue=root[i];
                if (!comValue.IsNull()) {
                    const char* type= root[i]["type"].GetString();
                    auto iter=__unuseComs.find(type);
                     if (iter!=__unuseComs.end()) {
                        Com* Com=iter->second->cloneEmpty();
                        
                         //在lua中，不能直接将rapidjson作为参数，所以直接传入json字符串在lua中自行解析
                         if (Com->_isCustom) {
                             //auto custom=(CustomCom*)Com;
                             
                             rapidjson::StringBuffer buffer;
                             rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
                             comValue.Accept(writer);
                             Com->initWithJson(buffer.GetString());
                         }
                         else {
                             Com->initWithMap(comValue);
                         }
                        
                        addComToEntity(Com, entity);
                    }
                }
            }
            
            //增持其引用计数
            entity->setComData(data);
            return entity;
        }
    }
    
    return nullptr;
}

void ECSManager::addComToEntity(GX::Com* com,Entity* entity)
{
    if(com==nullptr||entity==nullptr){
        return;
    }
    
    //1, 每个类型的Com只能有一个实例
    if (entity->_coms.find(com->getType())!=entity->_coms.end()) {
        return;
    }
    
    entity->_coms.insert(std::make_pair(com->getType(), com));
    com->_ownEntity=entity;
    
    //2. auto-attach System
    __autoAttachingSystem(com->getType(),entity);
}

void ECSManager::removeAllCom()
{
    
}

void ECSManager::removeEntity(Entity* entity)
{
    if (entity==nullptr) {
        return;
    }
    
    entity->__beMoving=true;
    
    //2,加入待移除列表(不能立即移除)
    __beRemoving.pushBack(entity);
}

cocos2d::Vector<Entity*> ECSManager::getAllEntitiesPosessingCom(const std::string& cId)
{
    cocos2d::Vector<Entity*> result;
    
    if (!cId.empty()) {
        auto entities=_ComEntities.find(cId);
        if (entities!=_ComEntities.end()) {
            return *entities->second;
        }
    }
    
    return result;
}

void ECSManager::registerSystem(System* system)
{
    auto sort=[](System* i,System* j) { return (i->getPriority()<j->getPriority()); };

    __unuseSystems.push_back(system);
    std::sort(__unuseSystems.begin(), __unuseSystems.end(), sort);
}

void ECSManager::unregisterSystem(std::string typeName)
{
    for (auto iter=__unuseSystems.begin(); iter!=__unuseSystems.end();iter++) {
        if ((*iter)->getType()==typeName) {
            __unuseSystems.erase(iter);
        }
    }
}

void ECSManager::registerCom(GX::Com* com)
{
    std::string name = com->getType();
    if (__unuseComs.find(name)==__unuseComs.end()) {
        __unuseComs.insert(std::make_pair(name, com));
    }
}

GX::Com* ECSManager::createCom(const std::string& typeName)
{
    auto com=__unuseComs.find(typeName);
    if (com!=__unuseComs.end()) {
        return com->second->cloneEmpty();
    }
    
    return nullptr;
}

void ECSManager::unregisterCom(const std::string& typeName)
{
    if (__unuseComs.find(typeName)==__unuseComs.end()) {
        __unuseComs.erase(typeName);
    }
}

/**
 * 1,update的过程中可能新增了Entity
 * 2,update的过程中可能移除了Entity
 */
void ECSManager::update(float dt)
{
    //1， 加入上一帧或者其他地方待加入的游戏对象
    __addingEntities();
    
    //CCLOG("ALl entities: %d",(int)_entities.size());
    //2,更新游戏对象
    for (auto iter=_entities.begin(); iter!=_entities.end(); iter++) {
        if((*iter)->__beMoving) break;
        if ((*iter)->getIsMoving()==false&&(*iter)->_systems.size()>0) {
            for (auto iter1=(*iter)->_systems.begin(); iter1!=(*iter)->_systems.end(); iter1++) {
                if (!iter1->second->_isFree) {
                    iter1->second->update(dt);
                    if((*iter)->__beMoving){
                        break;
                    }
                }
            }
        }
    }
    
    //3，移除游戏对象
    __removingEntities();
    
    //to do：向Statistics统计执行时间
}

void ECSManager::__addCompontForIndex(GX::Com* Com,Entity* entity)
{
    // 2. 为了便于更快根据Com类型查找entity
    cocos2d::Vector<Entity*>* ComEntities;
    auto entities=_ComEntities.find(Com->getType());
    if (entities==_ComEntities.end()) {
        ComEntities=new cocos2d::Vector<Entity*>();
        _ComEntities.insert(std::make_pair(Com->getType(), ComEntities));
    }
    else {
        ComEntities=entities->second;
    }
    
    ComEntities->insert(0, entity);
}


void ECSManager::__autoAttachingSystem(const std::string& type,Entity* entity)
{
    for (auto iter=__unuseSystems.begin(); iter!=__unuseSystems.end(); iter++) {
        if ((*iter)->firstType()==type) {
            std::string typeName=(*iter)->getType();
            if (entity->_systems.find(typeName)==entity->_systems.end()) {
                System* newSystem=(*iter)->cloneEmpty();
                
                entity->_systems.insert(std::make_pair(typeName, newSystem));
                newSystem->_isFree=false;
                newSystem->_entityManager=this;
                newSystem->onInit();
                newSystem->_ownEntity=entity;
                newSystem->onAttached();
            }
        }
    }
}

void ECSManager::__addingEntities()
{
    if (__beAdding.size()<1)
        return;
    
    __handing=__beAdding;
    
    for (auto iter=__handing.begin(); iter!=__handing.end(); iter++) {
        for (auto iter1=(*iter)->_coms.begin(); iter1!=(*iter)->_coms.end(); iter1++) {
            //1，建立组件索引供查找
            __addCompontForIndex(iter1->second,(*iter));
        }

        //2, 排序
        //(*iter)->sortSystem();
        
        //3,onComChanged
        (*iter)->ComsChanged();
        
        //4, 正式加入数组
        _entities.pushBack(*iter);
    }
    
    __beAdding.clear();
    __handing.clear();
}

// 从_entities中移除 __beMoving中的Entity
void ECSManager::__removingEntities()
{
    if (__beRemoving.size()<1)
        return;
    
    __handing=__beRemoving;
    
    //1，清除数据
    for (auto iter=__handing.begin(); iter!=__handing.end(); iter++) {
        //1.2,从ECSManager中移除所有Com(此时Coomponent已被移除)
        for (auto comIter=(*iter)->_coms.begin(); comIter!=(*iter)->_coms.end(); comIter++) {
            auto entities=_ComEntities[comIter->first];
            auto temp=std::find(entities->begin(), entities->end(), (*iter));
            if (temp!=entities->end()) {
                entities->erase(temp);
            }
        }
        
        //1.1，移除Entity自身的Coms和Systems
        (*iter)->removeAllComs();
    }
    
    //2,从_entities集合移除
    for (auto iter=__handing.begin(); iter!=__handing.end(); iter++) {
        auto remove= std::find(_entities.begin(), _entities.end(), (*iter));
        if (remove!=_entities.end()) {
            _entities.erase(remove);
        }
        
        (*iter)->release(); //delete (*iter);
    }
    
    //printLeaks();
    
    __beRemoving.clear();
    __handing.clear();
}
