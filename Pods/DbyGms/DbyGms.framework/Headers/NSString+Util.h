//
//  NSString+Util.h
//  DBY-GMS
//
//  Created by 钟凡 on 2020/7/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Util)

- (NSString *)md5Value;
- (BOOL)match:(NSString *)regex;

@end

NS_ASSUME_NONNULL_END
