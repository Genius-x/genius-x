/******************************************
 Copyright (C), 2014,SoulGame Inc.
 @file          ECSManager_Tests.mm
 @version       1.0
 @date          2014-03-14
 @update        2014-03-16
 ******************************************/

#import <XCTest/XCTest.h>
#include "ECSManager.h"
#include "Entity.h"
#include "TestSystem.h"

USING_NS_GX;

@interface ECSManager_Tests : XCTestCase
{
    ECSManager* _ecs;
}
@end

@implementation ECSManager_Tests


- (void)setUp
{
    [super setUp];
    _ecs=new ECSManager();
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testCreateEntity
{
    Entity* entity=_ecs->createEntity();
    
    XCTAssertTrue(entity!=nullptr,@"Create entity succeeded.");
    XCTAssertTrue(entity->getId()>0,@"Entity Id greater than 0.");
}

- (void)testCreateEntityWithFile
{
    //test method
    //Entity* entity=_ecs->createEntity("ecs/entities/test.json");
    
    //
    //XCTAssertTrue(entity->getComByType(TestCom::_TYPE)!=nullptr, @"Should contail TestComponent.");
}

- (void)testAddComponentToEntity
{
    Entity* entity=_ecs->createEntity();
    TestCom* node=new TestCom();
    
    //0,Test Method
    _ecs->addComToEntity(node,entity);
    
    //1,add component
    Com* com=entity->getComByType(node->_TYPE);
    XCTAssertTrue(com!=nullptr, @"Component should not be nil.");
    XCTAssertEqual(com->getType(), TestCom::_TYPE, @"The Component should be NodeComponent.");
    
    //2,automatic attch system
    XCTAssertTrue(entity->_systems.size()==1,@"NodeSystem Should be attached.");
}

- (void)testGetAllEntitiesPosessingComponent
{
    Entity* entity=_ecs->createEntity();
    TestCom* node=new TestCom();
    
    _ecs->addComToEntity(node,entity);
    _ecs->update(1);
    
    //3,entity should be find by component type.
    auto entities= _ecs->getAllEntitiesPosessingCom(TestCom::_TYPE);
    XCTAssertTrue(entities.at(0)->getId()==entity->getId(),@"Entity can be find by type.");
}

- (void)testRemoveEntity
{
    Entity* entity=_ecs->createEntity();
    TestCom* node=new TestCom();
    
    _ecs->addComToEntity(node,entity);
    _ecs->update(1);
    
    //test method.
    _ecs->removeEntity(entity);
    _ecs->update(1);
    
    //1,
    auto entities= _ecs->getAllEntitiesPosessingCom(TestCom::_TYPE);
    XCTAssertTrue(entities.size()==0,@"Entity should not be find by type any more.");
}

@end
