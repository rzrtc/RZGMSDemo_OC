//
//  NSString+Util.h
//  DbyGmsDemo_OC
//
//  Created by 钟凡 on 2020/8/1.
//  Copyright © 2020 多贝云. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Util)

- (NSString *)md5Value;
- (BOOL)match:(NSString *)regex;

@end

NS_ASSUME_NONNULL_END
