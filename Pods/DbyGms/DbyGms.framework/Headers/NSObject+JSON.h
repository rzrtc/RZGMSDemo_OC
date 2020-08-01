//
//  NSObject+JSON.h
//  DBY-GMS
//
//  Created by 钟凡 on 2020/6/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (JSON)

- (NSString *)jsonString;
- (NSDictionary *)jsonObject;

- (instancetype)initWithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
