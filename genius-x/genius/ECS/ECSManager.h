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

#ifndef __GX__EntityManager__
#define __GX__EntityManager__

#include "../GXMacros.h"
#include "Entity.h"
#include "System.h"

NS_GX_BEGIN

/** 
 * 管理所有的游戏对象Entity
 * 管理游戏对象所有的Com的添加，移除
 * 根据Com类型自动给Entity附加System,并对System进行排序
 * 驱动所有System的逻辑更新
 */
class ECSManager:public cocos2d::Ref
{
public:
    static ECSManager* create();
    
    /**
     * 可以创建多个ECSManager
     */
    ECSManager();
    ~ECSManager();
    
    /**
     * 创建Entity的唯一入口
     */
    Entity* createEntity();
    Entity* createEntity(const std::string& filename);
    void removeEntity(Entity* entity);
    
    /**
     * 游戏运行中将Com添加到一个Entity游戏对象
     *
     * 1,将Com添加到Entity
     * 2,从__unusedSystem查找哪些System会处理此类型，并将System附加到Entity
     * 3,对Entity所有的System触发onComsChanged事件，参见: System::onComsChanged()
     */
    void addComToEntity(Com* Com,Entity* entity);
    
    /**
     * 移除Entity某个类型的Com
     *
     * 1，移除并销毁Com对象
     * 2，对所有System执行onComsChanged事件
     * 3，对需要移除的Syetm执行 onAttached事件
     * 4, 移除并销毁System对象
     */
    void removeComFromEntity(const std::string& ComId, Entity*){};
    cocos2d::Vector<Entity*> getAllEntitiesPosessingCom(const std::string& cId);
    void removeAllCom();
    
    /**
     * 所有Entity并不会被排序，但是每个Entity的System会被按优先级执行
     * 参见: _entitySystems
     */
    void update(float dt);
    
    /**
     * C++不支持反射，缓存所有System，并使用cloneEmpty来复制实例
     * 应该在所有Entity被创建之前指定所有使用的System，但也可以动态添加
     */
    void registerSystem(System*);
    void unregisterSystem(std::string typeName);
    
    void registerCom(Com*);
    void unregisterCom(const std::string& typeName);
    
private:
    Com* createCom(const std::string& typeName);
    void __addingEntities();
    void __removingEntities();
    void __addCompontForIndex(Com*,Entity*);
    void __autoAttachingSystem(const std::string&,Entity*);
    bool __findEntity(const cocos2d::Vector<Entity*>&,entity_id_type);
    
    entity_id_type generateNewEid();
    
    cocos2d::Vector<Entity*> _entities;
    
    /** 
     * 存储每个类型Com对应的所有Entity
     * 为了便于快速根据类型查找对象
     * 这是面向类型的基础，始终通过类型查找游戏对象，而不是Id或者name
     */
    std::map<std::string, cocos2d::Vector<Entity*>*> _ComEntities;
    int _lowestUnassignedEid;
    cocos2d::Vector<Entity*> __beAdding;
    cocos2d::Vector<Entity*> __beRemoving;
    cocos2d::Vector<Entity*> __handing;
    
    
    /* This System instance will not to be used at any time(it's always free!)
     * This because C++ does't support reflection, So we can't init a system instance accord to a string, but we need system be auto-attach to an Entity
     * So we store a unused system instance for every System, and clone a new instance from it when needed.
     * This cause more memery but .... :)
     *
     * you must add all System before add any Com to an Entity. you need add System dynamically ?
     */
    std::map<std::string,System*> __unuseSystems;        //类型名称作为key：typeid(system).name
    std::map<std::string,Com*> __unuseComs;   //组件类型作为key: com->getType();
};

NS_GX_END

#endif /* defined(__GX__EntityManager__) */
