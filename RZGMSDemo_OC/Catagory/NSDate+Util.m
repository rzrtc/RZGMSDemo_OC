//
//  NSDate+Util.m
//  RZGMSDemo_OC
//
//  Created by 钟凡 on 2020/8/1.
//  Copyright © 2020 认真通信. All rights reserved.
//

#import "NSDate+Util.h"

@implementation NSDate (Util)

///in millisecond
+ (int64_t)currentTimeStamp {
    NSDate *date = [NSDate date];
    return (int64_t)(date.timeIntervalSince1970 * 1000);
}

@end
