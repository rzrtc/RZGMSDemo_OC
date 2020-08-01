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


typedef void (^DbyGmsInvitationSendBlock)(DbyGmsInvitationApiCallErrorCode errorCode);
typedef void (^DbyGmsInvitationAcceptBlock)(DbyGmsInvitationApiCallErrorCode errorCode);
typedef void (^DbyGmsInvitationRefuseBlock)(DbyGmsInvitationApiCallErrorCode errorCode);
typedef void (^DbyGmsInvitationCancelBlock)(DbyGmsInvitationApiCallErrorCode errorCode);


@class DbyGmsInvitationKit;
@class DbyGmsInvitation;

@protocol DbyGmsInvitationDelegate <NSObject>

@optional
- (void)gmsInvitationKit:(DbyGmsInvitationKit *_Nonnull)invitationKit invitationFailed:(DbyGmsInvitation *_Nonnull)invitation;
- (void)gmsInvitationKit:(DbyGmsInvitationKit *_Nonnull)invitationKit invitationArrived:(DbyGmsInvitation *_Nonnull)invitation;
- (void)gmsInvitationKit:(DbyGmsInvitationKit *_Nonnull)invitationKit invitationCanceled:(DbyGmsInvitation *_Nonnull)invitation;
- (void)gmsInvitationKit:(DbyGmsInvitationKit *_Nonnull)invitationKit invitationAccept:(DbyGmsInvitation *_Nonnull)invitation;
- (void)gmsInvitationKit:(DbyGmsInvitationKit *_Nonnull)invitationKit invitationRefused:(DbyGmsInvitation *_Nonnull)invitation;

@end

NS_ASSUME_NONNULL_BEGIN


@interface DbyGmsInvitation: NSObject

/**
 User ID of the Invitationer.
 */
@property (nonatomic, copy, nonnull) NSString *inviter;
/**
 User ID of the Invitationee.
 */
@property (nonatomic, copy, nonnull) NSString *invitee;

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

- (instancetype _Nonnull)initWithInviter:(NSString *)inviter invitee:(NSString *)invitee;

@end


@interface DbyGmsInvitationKit : NSObject

@property (nonatomic, weak) id<DbyGmsInvitationDelegate> delegate;

- (instancetype)initWithSocketManager:(DbyGmsSocketManager *)manager;

- (void)sendInvitation:(DbyGmsInvitation *_Nonnull)invitation completion:(DbyGmsInvitationSendBlock _Nullable)completion;
- (void)cancelInvitation:(DbyGmsInvitation *_Nonnull)invitation completion:(DbyGmsInvitationCancelBlock _Nullable)completion;

- (void)acceptInvitation:(DbyGmsInvitation *_Nonnull)invitation completion:(DbyGmsInvitationAcceptBlock _Nullable)completion;
- (void)refuseInvitation:(DbyGmsInvitation *_Nonnull)invitation completion:(DbyGmsInvitationRefuseBlock _Nullable)completion;

@end

NS_ASSUME_NONNULL_END
