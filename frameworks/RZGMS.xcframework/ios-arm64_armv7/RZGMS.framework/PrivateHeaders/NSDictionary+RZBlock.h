//
//  NSDictionary+RZBlock.h
//  RZGMS
//
//  Created by yxibng on 2021/6/25.
//

#import <Foundation/Foundation.h>
#import "RZGMSDefines.h"
NS_ASSUME_NONNULL_BEGIN

@interface __GENERICS(NSDictionary, KeyType, ObjectType) (RZBlock)
- (void)rz_each:(void (^)(KeyType key, ObjectType obj))block;
- (NSArray<id> *)rz_map:(id (^)(id key, id obj))block;
@end

NS_ASSUME_NONNULL_END
