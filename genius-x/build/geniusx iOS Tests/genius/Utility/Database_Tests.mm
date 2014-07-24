//
//  Database_Tests.m
//  sg
//
//  Created by Elvis on 14-4-1.
//
//

#import <XCTest/XCTest.h>
#include "DataBase.h"

USING_NS_GX;

@interface Database_Tests : XCTestCase

@end

@implementation Database_Tests

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testOpenDataScoure
{
    int result=DataBase::getInstance()->openDataScoure();
    
    XCTAssertTrue(result==0,"@");
}

-(void)testSelectDataWithInteger
{
    DataBase::getInstance()->openDataScoure();
    int result=DataBase::getInstance()->getInstance()->selectDataWithInteger("select user_id from User where user_id=1");
    XCTAssertTrue(result==1, @"");
    
    //Wrong Sql
    result=DataBase::getInstance()->getInstance()->selectDataWithInteger("select user_id from User where user_id=10");
    XCTAssertTrue(result==0, @"");
}

-(void)testSelectDataWithArray
{
    /*
    
    DataBase::getInstance()->openDataScoure();
    const std::vector<Value>& result=DataBase::getInstance()->selectDataWithArray("select * from User");
    XCTAssertTrue(result.size()>0, @"");
    
    XCTAssertTrue(result.at(0).asValueVector()[0].asInt()==1, @"");
    XCTAssertTrue(result.at(0).asValueVector()[1].asString()=="elvis", @"");
    
    const std::vector<Value>& wrongResult=DataBase::getInstance()->selectDataWithArray("select * from Userw");
    XCTAssertTrue(wrongResult.size()==0, @"");
     
     */
}

-(void)testSelectDataWithString
{
    DataBase::getInstance()->openDataScoure();
    const std::string& result= DataBase::getInstance()->selectDataWithString("select name from User where user_id=1");
    XCTAssertTrue(result=="elvis",@"");
    
    const std::string& wrongResult= DataBase::getInstance()->selectDataWithString("select name from User wh2ere user_id=1");
    XCTAssertTrue(wrongResult.empty(),@"");
}


@end
