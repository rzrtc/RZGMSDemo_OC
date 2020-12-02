//
//  DbyGmsKit.h
//  DBY-Gms
//
//  Created by yxibng on 2020/5/6.
//

#import "DbyChannelMemberCount.h"
#import "DbyEnumerates.h"
#import "DbyGmsAttribute.h"
#import "DbyGmsChannel.h"
#import "DbyGmsChannelAttributeOptions.h"
#import "DbyGmsInvitationKit.h"
#import "DbyGmsMember.h"
#import "DbyGmsMessage.h"
#import "DbyGmsPeerOnlineStatus.h"
#import "DbyGmsSendMessageOptions.h"
#import <Foundation/Foundation.h>

@class DbyGmsKit;

NS_ASSUME_NONNULL_BEGIN

typedef void (^DbyGmsLoginBlock)(DbyGmsLoginErrorCode errorCode);
typedef void (^DbyGmsLogoutBlock)(DbyGmsLogoutErrorCode errorCode);
typedef void (^DbyGmsSendPeerMessageBlock)(DbyGmsSendPeerMessageErrorCode errorCode);
typedef void (^DbyChannelMemberCountBlock)(NSArray<DbyChannelMemberCount *> *_Nullable channelMemberCounts, DbyGmsChannelMemberCountErrorCode errorCode);
typedef void (^DbyGmsQueryPeersOnlineBlock)(NSArray<DbyGmsPeerOnlineStatus *> *_Nullable peerOnlineStatus, DbyGmsQueryPeersOnlineErrorCode errorCode);
typedef void (^DbyGmsQueryPeersBySubscriptionOptionBlock)(NSArray<NSString *> *_Nullable peers, DbyGmsPeerSubscriptionStatusErrorCode errorCode);

#pragma mark - channel attributes -
/**
 Returns the result of the [setLocalUserAttributes]([DbyGmsKit setChannel:Attributes:Options:completion:]) <p><li><i>errorCode:</i> See DbyGmsProcessAttributeErrorCode.
 */
typedef void (^DbyGmsSetChannelAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);
/**
 Returns the result of the [addOrUpdateChannelAttributes]([DbyGmsKit addOrUpdateChannel:Attributes:Options:completion:]) method call. <p><li><i>errorCode:</i> See DbyGmsProcessAttributeErrorCode.
 */
typedef void (^DbyGmsAddOrUpdateChannelAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);
/**
 Returns the result of the [deleteChannelAttributesByKeys]([DbyGmsKit deleteChannel:AttributesByKeys:Options:completion:]) method call. <p><li><i>errorCode:</i> DbyGmsProcessAttributeErrorCode.
 */
typedef void (^DbyGmsDeleteChannelAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [clearChannelAttributesWithCompletion]([DbyGmsKit clearChannel:Options:AttributesWithCompletion:]) method call. <p><li><i>errorCode:</i> See DbyGmsProcessAttributeErrorCode.
 */
typedef void (^DbyGmsClearChannelAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [getChannelAttributes]([DbyGmsKit getChannelAllAttributes:completion:]) or the [getChannelAttributesByKeys]([DbyGmsKit getChannelAttributes:ByKeys:completion:]) method call. <p><li><i>attributes:</i> An array of DbyGmsChannelAttibute. See DbyGmsChannelAttibute. <p><li><i>errorCode:</i> See DbyGmsProcessAttributeErrorCode.
 */
typedef void (^DbyGmsGetChannelAttributesBlock)(NSArray<DbyGmsAttribute *> *_Nullable attributes, DbyGmsProcessAttributeErrorCode errorCode);

#pragma mark - user attributes -
/**
 Returns the result of the [setLocalUserAttributes]([DbyGmsKit setLocalUserAttributes:completion:]) <p><li><i>errorCode:</i> See DbyGmsProcessAttributeErrorCode.
 */
typedef void (^DbyGmsSetLocalUserAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [addOrUpdateLocalUserAttributes]([DbyGmsKit addOrUpdateLocalUserAttributes:completion:]) method call. <p><li><i>errorCode:</i> See DbyGmsProcessAttributeErrorCode.
 */
typedef void (^DbyGmsAddOrUpdateLocalUserAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [deleteLocalUserAttributesByKeys]([DbyGmsKit deleteLocalUserAttributesByKeys:completion:]) method call. <p><li><i>errorCode:</i> DbyGmsProcessAttributeErrorCode.
 */
typedef void (^DbyGmsDeleteLocalUserAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [clearLocalUserAttributesWithCompletion]([DbyGmsKit clearLocalUserAttributesWithCompletion:]) method call. <p><li><i>errorCode:</i> See DbyGmsProcessAttributeErrorCode.
 */
typedef void (^DbyGmsClearLocalUserAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [getUserAttributes]([DbyGmsKit getUserAllAttributes:completion:]) or the [getUserAttributesByKeys]([DbyGmsKit getUserAttributes:ByKeys:completion:]) method call. <p><li><i>attributes:</i> An array of RtmAttibutes. See DbyGmsAttribute. <p><li><i>userId:</i> The User ID of the specified user. <p><li><i>errorCode:</i> See DbyGmsProcessAttributeErrorCode.
 */
typedef void (^DbyGmsGetUserAttributesBlock)(NSArray<DbyGmsAttribute *> *_Nullable attributes, NSString *userId, DbyGmsProcessAttributeErrorCode errorCode);
/**
 Returns the result of the [renewToken]([DbyGmsKit renewToken:completion:]) method call. <p><li><i>token</i> Your new Token. <li><i>errorCode:</i> See DbyGmsRenewTokenErrorCode.
 */
typedef void (^DbyGmsRenewTokenBlock)(NSString *token, DbyGmsRenewTokenErrorCode errorCode);

#pragma mark - onlin status -
/**
 Returns the result of the [subscribePeersOnlineStatus]([DbyGmsKit subscribePeersOnlineStatus:completion:]) or [unsubscribePeersOnlineStatus]([DbyGmsKit unsubscribePeersOnlineStatus:completion:]) method call. <p><i>errorCode:</i> See DbyGmsPeerSubscriptionStatusErrorCode.
 */
typedef void (^DbyGmsSubscriptionRequestBlock)(DbyGmsPeerSubscriptionStatusErrorCode errorCode);

#pragma mark -

@protocol DbyGmsDelegate <NSObject>
@optional

- (void)dbyGmsKit:(DbyGmsKit *)kit connectionStateChanged:(DbyGmsConnectionState)state reason:(DbyGmsConnectionChangeReason)reason;
- (void)dbyGmsKit:(DbyGmsKit *)kit peersOnlineStatusChanged:(NSArray<DbyGmsPeerOnlineStatus *> *)onlineStatus;
///收到点对点消息
- (void)dbyGmsKit:(DbyGmsKit *)kit messageReceived:(DbyGmsMessage *)message fromPeer:(NSString *)peerId;
///token过期通知，重连的时候触发
- (void)dbyGmsKitTokenDidExpire:(DbyGmsKit *)kit;

@end

@interface DbyGmsKit : NSObject

@property (nonatomic, weak) id<DbyGmsDelegate> delegate;

- (instancetype)initWithAppId:(NSString *)appId delegate:(id<DbyGmsDelegate> _Nullable)delegate;

#pragma mark - login
- (void)loginByToken:(NSString *)token timeStamp:(int64_t)timeStamp userId:(NSString *)userId completion:(DbyGmsLoginBlock)completionBlock;
- (void)logoutWithCompletion:(DbyGmsLogoutBlock)completionBlock;
- (void)renewToken:(NSString *)token timeStamp:(int64_t)timeStamp completion:(DbyGmsRenewTokenBlock)completionBlock;

#pragma mark - channel
- (DbyGmsChannel *_Nullable)createChannelWithId:(NSString *)channelId delegate:(id<DbyGmsChannelDelegate> _Nullable)delegate;
- (BOOL)destroyChannelWithId:(NSString *)channelId;
- (void)getChannelMemberCount:(NSArray<NSString *> *)channelIds completion:(DbyChannelMemberCountBlock)completionBlock;

#pragma mark - channel attributes
- (void)setChannel:(NSString *)channelId attributes:(NSArray<DbyGmsAttribute *> *_Nullable)attributes options:(DbyGmsChannelAttributeOptions *)options completion:(DbyGmsSetChannelAttributesBlock)completionBlock;
- (void)addOrUpdateChannel:(NSString *)channelId attributes:(NSArray<DbyGmsAttribute *> *_Nullable)attributes options:(DbyGmsChannelAttributeOptions *)options completion:(DbyGmsAddOrUpdateChannelAttributesBlock)completionBlock;
- (void)deleteChannelAttributes:(NSString *)channelId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys options:(DbyGmsChannelAttributeOptions *)options completion:(DbyGmsDeleteChannelAttributesBlock)completionBlock;
- (void)clearChannelAttributes:(NSString *)channelId options:(DbyGmsChannelAttributeOptions *)options completion:(DbyGmsClearChannelAttributesBlock)completionBlock;
- (void)getChannelAttributes:(NSString *)channelId completion:(DbyGmsGetChannelAttributesBlock)completionBlock;
- (void)getChannelAttributes:(NSString *)channelId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(DbyGmsGetChannelAttributesBlock)completionBlock;

#pragma mark - user attributes
- (void)setLocalUserAttributes:(NSArray<DbyGmsAttribute *> *_Nullable)attributes completion:(DbyGmsSetLocalUserAttributesBlock)completionBlock;
- (void)addOrUpdateLocalUserAttributes:(NSArray<DbyGmsAttribute *> *_Nullable)attributes completion:(DbyGmsAddOrUpdateLocalUserAttributesBlock)completionBlock;
- (void)deleteLocalUserAttributesByKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(DbyGmsDeleteLocalUserAttributesBlock)completionBlock;
- (void)clearLocalUserAttributesWithCompletion:(DbyGmsClearLocalUserAttributesBlock)completionBlock;
- (void)getUserAttributes:(NSString *)userId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(DbyGmsGetUserAttributesBlock)completionBlock;
- (void)getUserAttributes:(NSString *)userId completion:(DbyGmsGetUserAttributesBlock)completionBlock;

#pragma mark - onlin status -
- (void)subscribePeersOnlineStatus:(NSArray<NSString *> *)peerIds completion:(DbyGmsSubscriptionRequestBlock)completionBlock;
- (void)unsubscribePeersOnlineStatus:(NSArray<NSString *> *)peerIds completion:(DbyGmsSubscriptionRequestBlock)completionBlock;
- (void)queryPeersOnlineStatus:(NSArray<NSString *> *)peerIds completion:(DbyGmsQueryPeersOnlineBlock)completionBlock;
- (void)queryPeersBySubscriptionOption:(DbyGmsPeerSubscriptionOptions)option completion:(DbyGmsQueryPeersBySubscriptionOptionBlock)completionBlock;

#pragma mark - 呼叫邀请管理
///获取呼叫邀请实例，需要在登录后调用
- (DbyGmsInvitationKit *)getGmsInvitationKit;

#pragma mark - 点对点消息
- (void)sendMessage:(DbyGmsMessage *)message
             toPeer:(NSString *)peerId
 sendMessageOptions:(DbyGmsSendMessageOptions *)options
         completion:(DbyGmsSendPeerMessageBlock)completionBlock;

#pragma mark - 其他
- (int)setParameters:(NSString *)parameters;
- (void)setLogFile:(NSString *)logFile;
- (void)setLogFilters:(DbyGmsLogFilter)filter;
+ (NSString *)getSDKVersion;

@end

NS_ASSUME_NONNULL_END
