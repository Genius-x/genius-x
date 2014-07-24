//
//  Localization.m
//  sg
//
//  Created by Elvis on 14-3-31.
//
//

#import <XCTest/XCTest.h>
#include "Localization.h"

@interface Localization_Tests : XCTestCase
{
    GX::Localization* _local;
}
@end

@implementation Localization_Tests

- (void)setUp
{
    [super setUp];
    
    _local = new GX::Localization();
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testGetStr
{
    //默认选择中文
    _local->loadStringsFrom("");
    //XCTAssertTrue("你好"==_local->getStr("test"), @"");

    //英文
    _local->loadStringsFrom("en");
    //XCTAssertTrue("Hello"==_local->getStr("test"), @"");

    //中文
    _local->loadStringsFrom("zh");
    //XCTAssertTrue("你好"==_local->getStr("test"), @"");
}

-(void)testGetMultiStr
{
    XCTAssertTrue("n,m"==_local->getMultiStr(2,"n","m"),@"");
}

@end