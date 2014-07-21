//
//  Resource_SenTests.m
//  sg
//
//  Created by Elvis on 14-4-1.
//
//

#import <XCTest/XCTest.h>
#include "Resource.h"
#include "ComData.h"
#include "XCTestCase+AsyncTesting.h"
USING_NS_GX;

@interface Resource_AsyncTests : XCTestCase
{
    Resource* _resource;
}
@end

@implementation Resource_AsyncTests

- (void)setUp
{
    [super setUp];
    
    _resource=new Resource();
}

- (void)tearDown
{
    [super tearDown];
}

-(void)testAddResourceAsync
{
    /*
    auto completed=[self](void* data){
        [self notify:XCTAsyncTestCaseStatusSucceeded];
    };
    
    _resource->addResourceAsync("test.png", completed);
    
    Cocos2dUpdate ccxupdate=^{
        Director::getInstance()->mainLoop();
    };
    
    [self waitForStatusWithUpdate:XCTAsyncTestCaseStatusSucceeded timeout:1000 update:ccxupdate];
     */
}

-(void)testAddResource
{
    auto result= _resource->addResource("test.png");
    //XCTAssertTrue(result!=nullptr, @"file should be added.");
    
    int ref=_resource->getResourceReference("test.png");
    //XCTAssertTrue(ref==1, @"reference should be added automatic");
    
    auto result1= _resource->addResource("hero.json",ComData::_TYPE);
    //XCTAssertTrue(result1!=nullptr, @"file should be added.");
    
    int ref1=_resource->getResourceReference("hero.json");
    //XCTAssertTrue(ref1==1, @"reference should be added automatic");
}

-(void)testRemoveResource
{
    auto data= _resource->addResource("test.png");
    _resource->removeResource(data);
    
    //XCTAssertTrue(true, @"reference should be added automatic");
}

-(void)testRemoveResourceForKey
{
    _resource->addResource("test.png");
    _resource->removeResourceForKey("test.png");
    
    //直接移除元素去除引用计数
    int ref=_resource->getResourceReference("test.png");
    //XCTAssertTrue(ref==0, @"reference should be added automatic");
}

-(void)testGetResourceReference
{
    std::unordered_map<std::string, Value> files;
    files.insert(std::make_pair("hero.json", Value(typeid(ComData).name())));

    _resource->addResourceReference(files);
    
    int ref=_resource->getResourceReference("hero.json");
    //XCTAssertTrue(ref==1, @"reference should be added automatic");
}

-(void)testAddWillUseResource
{
        std::unordered_map<std::string, Value> files;
    files.insert(std::make_pair("hero.json", Value(typeid(ComData).name())));
    
    _resource->addResourceReference(files);
    //XCTAssertTrue(_resource->getResourceReference("hero.json")==1, @"");
    
    _resource->addResourceReference(files);
    //XCTAssertTrue(_resource->getResourceReference("hero.json")==2, @"");
}

-(void)testRemoveUsedResource
{
        std::unordered_map<std::string, Value> files;
    files.insert(std::make_pair("hero.json", Value(typeid(ComData).name())));
    
    _resource->addResourceReference(files);
    _resource->addResourceReference(files);
    _resource->removeResourceReference(std::vector<std::string>({"hero.json"}));
    
    //XCTAssertTrue(_resource->getResourceReference("hero.json")==1, @"");
}

@end
