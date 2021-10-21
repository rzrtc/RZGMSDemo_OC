//
//  RZGMSChannel+RZGMS.h
//  RZGMS
//
//  Created by yxibng on 2021/6/28.
//

#import "RZGMSChannel.h"
@import SocketIO;

NS_ASSUME_NONNULL_BEGIN
@class RZGMSChannel;
@protocol RZGMSChannelStateDelegate <NSObject>
- (void)onJoinChannel:(RZGMSChannel *)channel;
- (void)onLeaveChannel:(RZGMSChannel *)channel;
@end

@interface RZGMSChannel ()

//是否已经加入频道
@property (nonatomic, assign) BOOL joined;
//是否已经被销毁
@property (nonatomic, assign) BOOL destroyed;

@property (nonatomic, weak) RZGMSStateManager *stateManager;
@property (nonatomic, weak) SocketIOClient *socket;

- (void)onMemberJoined:(RZGMSMember *)member;
- (void)onMemberLeft:(RZGMSMember *)member resaon:(RZGMSMemberLeaveChannelReason)reason;
- (void)onChannelMessageReceived:(NSString *)ChannelId message:(RZGMSMessage *)message fromMember:(RZGMSMember *)member;

@property (nonatomic, weak) id<RZGMSChannelStateDelegate>stateDelegate;


@end
NS_ASSUME_NONNULL_END
