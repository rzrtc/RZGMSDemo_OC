//
//  RZGMSChannel+RZGMS.h
//  RZGMS
//
//  Created by yxibng on 2021/6/28.
//

#import "RZGMSChannel.h"

NS_ASSUME_NONNULL_BEGIN

@class RZGMSChannel;
@protocol RZGMSChannelStateDelegate <NSObject>
- (void)onJoinChannel:(RZGMSChannel *)channel;
- (void)onLeaveChannel:(RZGMSChannel *)channel;
@end

@interface RZGMSChannel ()

- (void)onMemberJoined:(RZGMSMember *)member;
- (void)onMemberLeft:(RZGMSMember *)member resaon:(RZGMSMemberLeaveChannelReason)reason;
- (void)onChannelMessageReceived:(NSString *)ChannelId message:(RZGMSMessage *)message fromMember:(RZGMSMember *)member;

@property (nonatomic, weak) id<RZGMSChannelStateDelegate>stateDelegate;


@end
NS_ASSUME_NONNULL_END
