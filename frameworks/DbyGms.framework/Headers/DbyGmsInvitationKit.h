//
//  DbyGMSInvitationKit.h
//  DBY-GMS
//
//  Created by 钟凡 on 2020/6/22.
//

#import <Foundation/Foundation.h>
#import "DbyEnumerates.h"

@import SocketIO;

@class DbyGmsSocketManager;
@class DbyGmsInvitationKit;
@class DbyGmsInvitation;

NS_ASSUME_NONNULL_BEGIN

typedef void (^DbyGmsInvitationSendBlock)(DbyGmsInvitationApiCallErrorCode errorCode);
typedef void (^DbyGmsInvitationAcceptBlock)(DbyGmsInvitationApiCallErrorCode errorCode);
typedef void (^DbyGmsInvitationRefuseBlock)(DbyGmsInvitationApiCallErrorCode errorCode);
typedef void (^DbyGmsInvitationCancelBlock)(DbyGmsInvitationApiCallErrorCode errorCode);

@protocol DbyGmsInvitationDelegate <NSObject>

@optional
- (void)gmsInvitationKit:(DbyGmsInvitationKit *)invitationKit invitationFailed:(DbyGmsInvitation *)invitation;
- (void)gmsInvitationKit:(DbyGmsInvitationKit *)invitationKit invitationArrived:(DbyGmsInvitation *)invitation;
- (void)gmsInvitationKit:(DbyGmsInvitationKit *)invitationKit invitationCanceled:(DbyGmsInvitation *)invitation;
- (void)gmsInvitationKit:(DbyGmsInvitationKit *)invitationKit invitationAccept:(DbyGmsInvitation *)invitation;
- (void)gmsInvitationKit:(DbyGmsInvitationKit *)invitationKit invitationRefused:(DbyGmsInvitation *)invitation;

@end


@interface DbyGmsInvitation: NSObject

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
 The state of the outgoing Invitation invitation. See DbyGmsInvitationState.
 */
@property (nonatomic, assign) DbyGmsInvitationState state;

- (instancetype)initWithInviter:(NSString *)inviter invitee:(NSString *)invitee;

@end


@interface DbyGmsInvitationKit : NSObject

@property (nonatomic, weak) id<DbyGmsInvitationDelegate> delegate;

- (void)sendInvitation:(DbyGmsInvitation *)invitation completion:(DbyGmsInvitationSendBlock)completion;
- (void)cancelInvitation:(DbyGmsInvitation *)invitation completion:(DbyGmsInvitationCancelBlock)completion;

- (void)acceptInvitation:(DbyGmsInvitation *)invitation completion:(DbyGmsInvitationAcceptBlock)completion;
- (void)refuseInvitation:(DbyGmsInvitation *)invitation completion:(DbyGmsInvitationRefuseBlock)completion;

@end

NS_ASSUME_NONNULL_END
