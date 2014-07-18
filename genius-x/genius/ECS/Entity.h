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

#ifndef __GX__Entity__
#define __GX__Entity__

#include "../GXMacros.h"
#include "System.h"
#include "../Resource/ComData.h"

NS_GX_BEGIN

class Com;
class System;
class ECSManager;

//最大值:4294967295U
typedef int32_t entity_id_type;

/**
 * Entity仅表示一个Id,它可以用来表示游戏中的任何有意义的游戏对象，如button,hero,boss,tree等
 *
 * @note
 * 1,Entity只能通过ECSManager来创建和删除，ECSManager负责Entity的Com和System附加管理，不能手动创建
 * 2,Entity一般只存在于Scene，Layer等游戏场景中，它一般不能被其它的Entity引用
 * 3,System或者其它地方对Entity的查找和引用一般通过类型查找，见：ECSManager::getAllEntitiesPosessingCom
 * 4,每个Entity包含或者不包含一个Node，所有的Entity对象是扁平的，但是Node的树形结构保持不变
 *
 * Entity不能被继承
 */
class Entity:public cocos2d::Ref
{
public:
    
    /**
     * 对对象进行桶式更新
     */
    void setBucket(int bucket);
    Entity* getParent(){return nullptr;}
    
    const entity_id_type& getId(){return _id;}
    
    //每个Entity仅能对应一个或者不对应Node
    cocos2d::Node* getNode();
    Com* getComByType(const std::string&);
    
    //bool operator==(const Entity& right) const;
    //bool operator!=(const Entity& right) const;
    
    bool equals(const Entity& target) const
    {
        return target._id==_id;
    }
    
private:
    Entity();
    virtual ~Entity();
    
    /*
     * Entity只能通过ECSManager创建
     */
    static Entity* createWithId(const entity_id_type& id);
    
    void initWithId(const entity_id_type& id);
    
    void setComData(ComData*);
    ComData* __jsonData;
    
    inline bool getIsMoving(){return __beMoving;}
    
    bool __beMoving;
    
public:
    //for unit test
    void removeCom(const std::string&);
    void removeAllComs();
    void ComsChanged();

    entity_id_type _id;
    
    /*
     * _systems和_coms仅存储用于更快查询遍历，它们只能被ECSManager使用
     * Com只能通过ECSManager添加，System则是自动附加的
     */
    std::map<std::string, Com*> _coms; //所有Com,每种类型最多一个
    
public:
    /**
     * 每个Entity拥有哪些System
     *
     * 每一帧，只有这里的System才会被执行update
     * 每个Entity对应的System在被附加时排序
     */
    std::map<std::string,System*> _systems;
    
    friend ECSManager;
};

NS_GX_END

#endif /* defined(__GX__Entity__) */
