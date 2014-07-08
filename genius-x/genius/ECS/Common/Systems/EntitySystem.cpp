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

#include "EntitySystem.h"
#include "../../ECSManager.h"
#include "../Components/EntityCom.h"

USING_NS_GX;

std::string GX::EntitySystem::_TYPE="EntitySystem";

GX::EntitySystem::EntitySystem()
:GX::System(_TYPE,EntityCom::_TYPE)
{
    
}

GX::System* GX::EntitySystem::cloneEmpty() const
{
    return new GX::EntitySystem();
}

void GX::EntitySystem::onAttached()
{
    GX::EntityCom* com = (GX::EntityCom*)getComByType(GX::EntityCom::_TYPE);
    for (auto iter=com->entityNames.begin(); iter!=com->entityNames.end(); iter++) {
        Entity* entity=getECSManager()->createEntity(iter->second);
        com->entities.insert(std::make_pair(iter->first, entity));
        if (entity->getNode()) {
            getNode()->addChild(entity->getNode());
        }
    }
}

void GX::EntitySystem::onDeattached()
{
    
}