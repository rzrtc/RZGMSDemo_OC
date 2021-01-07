//
//  RZGMSPeerOnlineStatus.h
//  RZ-GMS
//
//  Created by yxibng on 2020/5/15.
//

#import <Foundation/Foundation.h>
#import "RZEnumerates.h"

NS_ASSUME_NONNULL_BEGIN


@interface RZGMSPeerOnlineStatus : NSObject

@property (nonatomic, copy, nonnull) NSString *peerId;
@property (nonatomic, assign) BOOL isOnline;

@end

NS_ASSUME_NONNULL_END
