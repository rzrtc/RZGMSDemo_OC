//
//  RZChannelMemberCount.h
//  RZ-GMS
//
//  Created by yxibng on 2020/5/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface RZChannelMemberCount : NSObject
@property (nonatomic, copy, nonnull) NSString *channelId;
@property (nonatomic, assign) int count;
@end

NS_ASSUME_NONNULL_END
