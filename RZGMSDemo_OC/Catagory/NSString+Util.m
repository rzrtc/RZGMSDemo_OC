//
//  NSString+Util.m
//  RZGMSDemo_OC
//
//  Created by 钟凡 on 2020/8/1.
//  Copyright © 2020 认真通信. All rights reserved.
//

#import "NSString+Util.h"
#import <CommonCrypto/CommonCrypto.h>


@implementation NSString (Util)

- (NSString *)md5Value
{
    const char *original_str = [self UTF8String];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(original_str, (uint32_t)strlen(original_str), result);
    NSMutableString *hash = [NSMutableString string];
    for (int i = 0; i < 16; i++) {
        [hash appendFormat:@"%02X", result[i]];
    }
    return [hash lowercaseString];
}
- (BOOL)match:(NSString *)regex {
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [predicate evaluateWithObject:self];
}
@end
