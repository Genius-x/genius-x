/******************************************
 Copyright (C), 2014,SoulGame Inc.
 @file          Entity_Tests.mm
 @version       1.0
 @date          2014-03-14
 @update        2014-03-16
 ******************************************/

#import <XCTest/XCTest.h>
#include "ECSManager.h"
#include "Entity.h"
#include "TestSystem.h"

USING_NS_GX;

@interface Entity_Tests : XCTestCase

@end

@implementation Entity_Tests

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testRemoveComponent
{
    /*
    
    ECSManager* ecs=new ECSManager();
    
    Entity* entity=ecs->createEntity();
    TestComponent* node=new TestComponent();
    ecs->addComponentToEntity(node,entity);
    
    //test method.
    entity->removeComponent(TestComponent::_TYPE);
    
    //1,
    XCTAssertTrue(entity->getComponentByType(TestComponent::_TYPE)==nullptr,@"Entity should not contain the nodecomponent any more.");
    XCTAssertTrue(entity->_systems.size()==0, @"Entity should not contain NodeSystem.");
     */
}

@end
