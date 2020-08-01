//
//  DbyGmsKit.h
//  DBY-Gms
//
//  Created by yxibng on 2020/5/6.
//

#import <Foundation/Foundation.h>
#import "DbyGmsAttribute.h"
#import "DbyGmsChannelAttributeOptions.h"
#import "DbyGmsMessage.h"
#import "DbyGmsSendMessageOptions.h"
#import "DbyChannelMemberCount.h"
#import "DbyEnumerates.h"
#import "DbyGmsPeerOnlineStatus.h"
#import "DbyGmsMember.h"
#import "DbyGmsInvitationKit.h"
#import "DbyGmsChannel.h"


NS_ASSUME_NONNULL_BEGIN

@class DbyGmsKit;

typedef void (^DbyGmsLoginBlock)(DbyGmsLoginErrorCode errorCode);
typedef void (^DbyGmsLogoutBlock)(DbyGmsLogoutErrorCode errorCode);
/**
 Returns the result of the [sendMessage]([DbyGmsKit sendMessage:toPeer:completion:]) method call. Error code of sending the peer-to-peer message. See DbyGmsSendPeerMessageErrorCode.
 */
typedef void (^DbyGmsSendPeerMessageBlock)(DbyGmsSendPeerMessageErrorCode errorCode);

typedef void (^DbyChannelMemberCountBlock)(NSArray<DbyChannelMemberCount *> * _Nullable channelMemberCounts, DbyGmsChannelMemberCountErrorCode errorCode);
typedef void (^DbyGmsQueryPeersOnlineBlock)(NSArray<DbyGmsPeerOnlineStatus *>  * _Nullable peerOnlineStatus, DbyGmsQueryPeersOnlineErrorCode errorCode);
typedef void (^DbyGmsQueryPeersBySubscriptionOptionBlock)(NSArray<NSString *> * _Nullable peers, DbyGmsPeerSubscriptionStatusErrorCode errorCode);

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
typedef void (^DbyGmsGetChannelAttributesBlock)(NSArray< DbyGmsAttribute *> * _Nullable attributes, DbyGmsProcessAttributeErrorCode errorCode);

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
typedef void (^DbyGmsGetUserAttributesBlock)(NSArray< DbyGmsAttribute *> * _Nullable attributes, NSString * userId, DbyGmsProcessAttributeErrorCode errorCode);
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
- (void)dbyGmsKit:(DbyGmsKit *)kit peersOnlineStatusChanged:(NSArray<DbyGmsPeerOnlineStatus *> *_Nonnull)onlineStatus;
///收到点对点消息
- (void)dbyGmsKit:(DbyGmsKit *)kit messageReceived:(DbyGmsMessage *_Nonnull)message fromPeer:(NSString *_Nonnull)peerId;
///收到呼叫邀请
- (void)dbyGmsKit:(DbyGmsKit *)kit invitationReceived:(DbyGmsInvitation *_Nonnull)invitation fromPeer:(NSString *_Nonnull)peerId;

@end


@interface DbyGmsKit : NSObject

@property (nonatomic, weak) id<DbyGmsDelegate> delegate;

- (instancetype)initWithAppId:(NSString *_Nonnull)appId delegate:(id<DbyGmsDelegate> _Nullable)delegate;

#pragma mark - login
- (void)loginByToken:(NSString *_Nonnull)token timeStamp:(NSTimeInterval)timeStamp userId:(NSString *)userId completion:(DbyGmsLoginBlock _Nullable)completionBlock;
- (void)logoutWithCompletion:(DbyGmsLogoutBlock _Nullable)completionBlock;
- (void)renewToken:(NSString *_Nonnull)token timeStamp:(NSTimeInterval)timeStamp completion:(DbyGmsRenewTokenBlock _Nullable)completionBlock;

#pragma mark - channel
- (DbyGmsChannel *_Nullable)createChannelWithId:(NSString *_Nonnull)channelId delegate:(id<DbyGmsChannelDelegate> _Nullable)delegate;
- (BOOL)destroyChannelWithId:(NSString *_Nonnull)channelId;
- (void)getChannelMemberCount:(NSArray<NSString *> *_Nonnull)channelIds completion:(DbyChannelMemberCountBlock _Nullable)completionBlock;

#pragma mark - channel attributes
- (void)setChannel:(NSString *_Nonnull)channelId attributes:(NSArray<DbyGmsAttribute *> *_Nullable)attributes options:(DbyGmsChannelAttributeOptions *_Nonnull)options completion:(DbyGmsSetChannelAttributesBlock _Nullable)completionBlock;
- (void)addOrUpdateChannel:(NSString *_Nonnull)channelId attributes:(NSArray<DbyGmsAttribute *> *_Nullable)attributes options:(DbyGmsChannelAttributeOptions *_Nonnull)options completion:(DbyGmsAddOrUpdateChannelAttributesBlock _Nullable)completionBlock;
- (void)deleteChannelAttributes:(NSString *_Nonnull)channelId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys options:(DbyGmsChannelAttributeOptions *_Nonnull)options completion:(DbyGmsDeleteChannelAttributesBlock _Nullable)completionBlock;
- (void)clearChannelAttributes:(NSString *_Nonnull)channelId options:(DbyGmsChannelAttributeOptions *_Nonnull)options completion:(DbyGmsClearChannelAttributesBlock _Nullable)completionBlock;
- (void)getChannelAttributes:(NSString *_Nonnull)channelId completion:(DbyGmsGetChannelAttributesBlock _Nullable)completionBlock;
- (void)getChannelAttributes:(NSString *_Nonnull)channelId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(DbyGmsGetChannelAttributesBlock _Nullable)completionBlock;


#pragma mark - user attributes
- (void)setLocalUserAttributes:(NSArray<DbyGmsAttribute *> *_Nullable)attributes completion:(DbyGmsSetLocalUserAttributesBlock _Nullable)completionBlock;
- (void)addOrUpdateLocalUserAttributes:(NSArray<DbyGmsAttribute *> *_Nullable)attributes completion:(DbyGmsAddOrUpdateLocalUserAttributesBlock _Nullable)completionBlock;
- (void)deleteLocalUserAttributesByKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(DbyGmsDeleteLocalUserAttributesBlock _Nullable)completionBlock;
- (void)clearLocalUserAttributesWithCompletion:(DbyGmsClearLocalUserAttributesBlock _Nullable)completionBlock;
- (void)getUserAttributes:(NSString *_Nonnull)userId byKeys:(NSArray<NSString*> *_Nullable)attributeKeys completion:(DbyGmsGetUserAttributesBlock _Nullable)completionBlock;
- (void)getUserAttributes:(NSString *_Nonnull)userId completion:(DbyGmsGetUserAttributesBlock _Nullable)completionBlock;


#pragma mark - onlin status -
- (void)subscribePeersOnlineStatus:(NSArray<NSString *> *_Nonnull)peerIds completion:(DbyGmsSubscriptionRequestBlock _Nullable)completionBlock;
- (void)unsubscribePeersOnlineStatus:(NSArray<NSString *> *_Nonnull)peerIds completion:(DbyGmsSubscriptionRequestBlock _Nullable)completionBlock;
- (void)queryPeersOnlineStatus:(NSArray<NSString *> *_Nonnull)peerIds completion:(DbyGmsQueryPeersOnlineBlock _Nullable)completionBlock;
- (void)queryPeersBySubscriptionOption:(DbyGmsPeerSubscriptionOptions)option completion:(DbyGmsQueryPeersBySubscriptionOptionBlock _Nullable)completionBlock;


#pragma mark - 呼叫邀请管理
///获取呼叫邀请实例，需要在登录后调用
- (DbyGmsInvitationKit *)getGmsInvitationKit;

#pragma mark - 点对点消息
- (void)sendMessage:(DbyGmsMessage *_Nonnull)message
             toPeer:(NSString *_Nonnull)peerId
 sendMessageOptions:(DbyGmsSendMessageOptions *_Nonnull)options
         completion:(DbyGmsSendPeerMessageBlock _Nullable)completionBlock;

#pragma mark - 其他
- (int)setParameters:(NSString *_Nonnull)parameters;
- (void)setLogFile:(NSString *_Nonnull)logFile;
- (void)setLogFilters:(DbyGmsLogFilter)filter;
+ (NSString *)getSDKVersion;

@end

NS_ASSUME_NONNULL_END
