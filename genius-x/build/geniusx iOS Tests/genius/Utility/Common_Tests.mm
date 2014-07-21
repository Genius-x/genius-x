//
//  Common_Tests.m
//  sg
//
//  Created by Elvis on 14-4-1.
//
//

#import <XCTest/XCTest.h>

#include "GXMacros.h"
#include "Common.h"

USING_NS_GX;

@interface Common_Tests : XCTestCase

@end

@implementation Common_Tests

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testColor3BFromString
{
    Color3B color=Color3BFromString("{23,24,25}");
    XCTAssertTrue(color.r==23&&color.g==24&&color.b==25, @"");
}

-(void)testTime4fFromSeconds
{
    Time4f t=Time4fFromSeconds(90061);
    XCTAssertTrue(t.d==1&&t.h==1&&t.m==1&&t.s==1, @"");
}

@end
