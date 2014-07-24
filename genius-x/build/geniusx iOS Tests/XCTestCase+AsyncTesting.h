//
//  XCTestCase+AsyncTesting.h
//  AsyncXCTestingKit
//
//  Created by 小野 将司 on 12/03/17.
//  Modified for XCTest by Vincil Bishop
//  Copyright (c) 2012年 AppBankGames Inc. All rights reserved.
//

#import <XCTest/XCTest.h>

typedef void(^Cocos2dUpdate)(void);


enum {
    XCTAsyncTestCaseStatusUnknown = 0,
    XCTAsyncTestCaseStatusWaiting,
    XCTAsyncTestCaseStatusSucceeded,
    XCTAsyncTestCaseStatusFailed,
    XCTAsyncTestCaseStatusCancelled,
};
typedef NSUInteger XCTAsyncTestCaseStatus;


@interface XCTestCase (AsyncTesting)

- (void)waitForStatus:(XCTAsyncTestCaseStatus)status timeout:(NSTimeInterval)timeout;
- (void)waitForTimeout:(NSTimeInterval)timeout;
- (void)notify:(XCTAsyncTestCaseStatus)status;
- (void)waitForStatusWithUpdate:(XCTAsyncTestCaseStatus)status timeout:(NSTimeInterval)timeout update:(Cocos2dUpdate)update;

@end