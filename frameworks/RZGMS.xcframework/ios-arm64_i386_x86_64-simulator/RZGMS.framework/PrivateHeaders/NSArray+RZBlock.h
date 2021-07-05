//
//  NSArray+RZBlock.h
//  RZGMS
//
//  Created by yxibng on 2021/6/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (RZBlock)
- (NSArray *)rz_map:(id (^)(id obj))block;
@end

NS_ASSUME_NONNULL_END
