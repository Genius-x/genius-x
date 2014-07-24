//
//  GameConfig_Tests.m
//  sg
//
//  Created by Elvis on 14-4-1.
//
//

#import <XCTest/XCTest.h>
#include "GameConfig.h"

@interface GameConfig_Tests : XCTestCase

@end

@implementation GameConfig_Tests

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testGetConfig
{
    //const rapidjson::Value& json=GX::GameConfig::getInstance()->getConfig("test");
    //std::string value=json.GetString();
    
    //XCTAssertTrue("hello"==value, @"");
}

-(void)testSetConfig
{
    /*
    rapidjson::Value node(100);
    
    //向GameConfig中动态添加数据
    GX::GameConfig::getInstance()->setConfig("test1",node);
    const rapidjson::Value& value=GX::GameConfig::getInstance()->getConfig("test1");
    int str=value.GetInt();
    
    XCTAssertTrue(100==str, @"");
     */
}

@end
