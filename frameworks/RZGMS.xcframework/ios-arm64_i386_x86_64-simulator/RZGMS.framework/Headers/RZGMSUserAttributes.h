//
//  RZGMSUserAttributes.h
//  RZGMS
//
//  Created by yxibng on 2021/5/31.
//

#import <Foundation/Foundation.h>
#import "RZGMSAttribute.h"
#import "RZEnumerates.h"

NS_ASSUME_NONNULL_BEGIN


@interface RZGMSAttributeWithState: RZGMSAttribute
/// 属性是否被移除
@property (nonatomic, assign) BOOL deleted;
@end


@interface RZGMSUserAttributes : NSObject

@property (nonatomic, copy) NSString *userId;
@property (nonatomic, strong) NSArray<RZGMSAttributeWithState *> * attributes;

- (instancetype)initWithUserId:(NSString *)userId;
- (void)configAttributes:(NSDictionary *)attributes;
@end

NS_ASSUME_NONNULL_END
