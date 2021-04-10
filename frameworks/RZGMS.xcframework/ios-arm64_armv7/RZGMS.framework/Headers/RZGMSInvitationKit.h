//
//  RZGMSInvitationKit.h
//  RZ-GMS
//
//  Created by 钟凡 on 2020/6/22.
//

#import <Foundation/Foundation.h>
#import "RZEnumerates.h"

@import SocketIO;

@class RZGMSSocketManager;
@class RZGMSInvitationKit;
@class RZGMSInvitation;

NS_ASSUME_NONNULL_BEGIN

typedef void (^RZGMSInvitationSendBlock)(RZGMSInvitationApiCallErrorCode errorCode);
typedef void (^RZGMSInvitationAcceptBlock)(RZGMSInvitationApiCallErrorCode errorCode);
typedef void (^RZGMSInvitationRefuseBlock)(RZGMSInvitationApiCallErrorCode errorCode);
typedef void (^RZGMSInvitationCancelBlock)(RZGMSInvitationApiCallErrorCode errorCode);

@protocol RZGMSInvitationDelegate <NSObject>

@optional
- (void)gmsInvitationKit:(RZGMSInvitationKit *)invitationKit invitationFailed:(RZGMSInvitation *)invitation errorCode:(RZGMSInvitationErrorCode)errorCode;
- (void)gmsInvitationKit:(RZGMSInvitationKit *)invitationKit invitationArrived:(RZGMSInvitation *)invitation;
- (void)gmsInvitationKit:(RZGMSInvitationKit *)invitationKit invitationCanceled:(RZGMSInvitation *)invitation;
- (void)gmsInvitationKit:(RZGMSInvitationKit *)invitationKit invitationAccept:(RZGMSInvitation *)invitation;
- (void)gmsInvitationKit:(RZGMSInvitationKit *)invitationKit invitationRefused:(RZGMSInvitation *)invitation;

@end


@interface RZGMSInvitation: NSObject

/**
 User ID of the Invitationer.
 */
@property (nonatomic, copy) NSString *inviter;
/**
 User ID of the Invitationee.
 */
@property (nonatomic, copy) NSString *invitee;

/**
 The Invitation invitation content set by the Invitationer.
 */
@property (nonatomic, copy, nullable) NSString *requestInfo;
/**
 The Invitation invitation content set by the Invitationee.
 */
@property (nonatomic, copy, nullable) NSString *responseInfo;

/**
 The state of the outgoing Invitation invitation. See RZGMSInvitationState.
 */
@property (nonatomic, assign) RZGMSInvitationState state;

- (instancetype)initWithInviter:(NSString *)inviter invitee:(NSString *)invitee;

@end


@interface RZGMSInvitationKit : NSObject

@property (nonatomic, weak) id<RZGMSInvitationDelegate> delegate;

- (void)sendInvitation:(RZGMSInvitation *)invitation completion:(RZGMSInvitationSendBlock)completion;
- (void)cancelInvitation:(RZGMSInvitation *)invitation completion:(RZGMSInvitationCancelBlock)completion;

- (void)acceptInvitation:(RZGMSInvitation *)invitation completion:(RZGMSInvitationAcceptBlock)completion;
- (void)refuseInvitation:(RZGMSInvitation *)invitation completion:(RZGMSInvitationRefuseBlock)completion;

@end

NS_ASSUME_NONNULL_END
