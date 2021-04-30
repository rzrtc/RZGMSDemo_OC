//
//  RZGMSKit.h
//  RZ-GMS
//
//  Created by yxibng on 2020/5/6.
//

#import "RZChannelMemberCount.h"
#import "RZEnumerates.h"
#import "RZGMSAttribute.h"
#import "RZGMSChannel.h"
#import "RZGMSChannelAttributeOptions.h"
#import "RZGMSInvitationKit.h"
#import "RZGMSMember.h"
#import "RZGMSMessage.h"
#import "RZGMSPeerOnlineStatus.h"
#import "RZGMSSendMessageOptions.h"
#import "RZGMSOptions.h"
#import <Foundation/Foundation.h>

@class RZGMSKit;

NS_ASSUME_NONNULL_BEGIN

typedef void (^RZGMSLoginBlock)(RZGMSLoginErrorCode errorCode);
typedef void (^RZGMSLogoutBlock)(RZGMSLogoutErrorCode errorCode);
typedef void (^RZGMSSendPeerMessageBlock)(RZGMSSendPeerMessageErrorCode errorCode);
typedef void (^RZChannelMemberCountBlock)(NSArray<RZChannelMemberCount *> *_Nullable channelMemberCounts, RZGMSChannelMemberCountErrorCode errorCode);
typedef void (^RZGMSQueryPeersOnlineBlock)(NSArray<RZGMSPeerOnlineStatus *> *_Nullable peerOnlineStatus, RZGMSQueryPeersOnlineErrorCode errorCode);
typedef void (^RZGMSQueryPeersBySubscriptionOptionBlock)(NSArray<NSString *> *_Nullable peers, RZGMSPeerSubscriptionStatusErrorCode errorCode);

#pragma mark - channel attributes -
/**
 Returns the result of the [setLocalUserAttributes]([RZGMSKit setChannel:Attributes:Options:completion:]) <p><li><i>errorCode:</i> See RZGMSProcessAttributeErrorCode.
 */
typedef void (^RZGMSSetChannelAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);
/**
 Returns the result of the [addOrUpdateChannelAttributes]([RZGMSKit addOrUpdateChannel:Attributes:Options:completion:]) method call. <p><li><i>errorCode:</i> See RZGMSProcessAttributeErrorCode.
 */
typedef void (^RZGMSAddOrUpdateChannelAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);
/**
 Returns the result of the [deleteChannelAttributesByKeys]([RZGMSKit deleteChannel:AttributesByKeys:Options:completion:]) method call. <p><li><i>errorCode:</i> RZGMSProcessAttributeErrorCode.
 */
typedef void (^RZGMSDeleteChannelAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [clearChannelAttributesWithCompletion]([RZGMSKit clearChannel:Options:AttributesWithCompletion:]) method call. <p><li><i>errorCode:</i> See RZGMSProcessAttributeErrorCode.
 */
typedef void (^RZGMSClearChannelAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [getChannelAttributes]([RZGMSKit getChannelAllAttributes:completion:]) or the [getChannelAttributesByKeys]([RZGMSKit getChannelAttributes:ByKeys:completion:]) method call. <p><li><i>attributes:</i> An array of RZGMSChannelAttibute. See RZGMSChannelAttibute. <p><li><i>errorCode:</i> See RZGMSProcessAttributeErrorCode.
 */
typedef void (^RZGMSGetChannelAttributesBlock)(NSArray<RZGMSAttribute *> *_Nullable attributes, RZGMSProcessAttributeErrorCode errorCode);

#pragma mark - user attributes -
/**
 Returns the result of the [setLocalUserAttributes]([RZGMSKit setLocalUserAttributes:completion:]) <p><li><i>errorCode:</i> See RZGMSProcessAttributeErrorCode.
 */
typedef void (^RZGMSSetLocalUserAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [addOrUpdateLocalUserAttributes]([RZGMSKit addOrUpdateLocalUserAttributes:completion:]) method call. <p><li><i>errorCode:</i> See RZGMSProcessAttributeErrorCode.
 */
typedef void (^RZGMSAddOrUpdateLocalUserAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [deleteLocalUserAttributesByKeys]([RZGMSKit deleteLocalUserAttributesByKeys:completion:]) method call. <p><li><i>errorCode:</i> RZGMSProcessAttributeErrorCode.
 */
typedef void (^RZGMSDeleteLocalUserAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [clearLocalUserAttributesWithCompletion]([RZGMSKit clearLocalUserAttributesWithCompletion:]) method call. <p><li><i>errorCode:</i> See RZGMSProcessAttributeErrorCode.
 */
typedef void (^RZGMSClearLocalUserAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [getUserAttributes]([RZGMSKit getUserAllAttributes:completion:]) or the [getUserAttributesByKeys]([RZGMSKit getUserAttributes:ByKeys:completion:]) method call. <p><li><i>attributes:</i> An array of RtmAttibutes. See RZGMSAttribute. <p><li><i>userId:</i> The User ID of the specified user. <p><li><i>errorCode:</i> See RZGMSProcessAttributeErrorCode.
 */
typedef void (^RZGMSGetUserAttributesBlock)(NSArray<RZGMSAttribute *> *_Nullable attributes, NSString *userId, RZGMSProcessAttributeErrorCode errorCode);
/**
 Returns the result of the [renewToken]([RZGMSKit renewToken:completion:]) method call. <p><li><i>token</i> Your new Token. <li><i>errorCode:</i> See RZGMSRenewTokenErrorCode.
 */
typedef void (^RZGMSRenewTokenBlock)(NSString *token, RZGMSRenewTokenErrorCode errorCode);

#pragma mark - onlin status -
/**
 Returns the result of the [subscribePeersOnlineStatus]([RZGMSKit subscribePeersOnlineStatus:completion:]) or [unsubscribePeersOnlineStatus]([RZGMSKit unsubscribePeersOnlineStatus:completion:]) method call. <p><i>errorCode:</i> See RZGMSPeerSubscriptionStatusErrorCode.
 */
typedef void (^RZGMSSubscriptionRequestBlock)(RZGMSPeerSubscriptionStatusErrorCode errorCode);

#pragma mark -

@protocol RZGMSDelegate <NSObject>
@optional

- (void)rzGMSKit:(RZGMSKit *)kit connectionStateChanged:(RZGMSConnectionState)state reason:(RZGMSConnectionChangeReason)reason;
- (void)rzGMSKit:(RZGMSKit *)kit peersOnlineStatusChanged:(NSArray<RZGMSPeerOnlineStatus *> *)onlineStatus;
///收到点对点消息
- (void)rzGMSKit:(RZGMSKit *)kit messageReceived:(RZGMSMessage *)message fromPeer:(NSString *)peerId;
///token过期通知，重连的时候触发
- (void)rzGMSKitTokenDidExpire:(RZGMSKit *)kit;

@end

@interface RZGMSKit : NSObject

@property (nonatomic, weak) id<RZGMSDelegate> delegate;


/// 创建 RZGMSKit 实例
/// @param appId 应用id
/// @param delegate 接收sdk事件的 RZGMSDelegate 代理对象
- (instancetype)initWithAppId:(NSString *)appId delegate:(id<RZGMSDelegate> _Nullable)delegate;

/// 创建 RZGMSKit 实例, 支持自定义域名配置
/// @param appId 应用id
/// @param delegate 接收sdk事件的 RZGMSDelegate 代理对象
/// @param options 通过options.envConfig.apiServer来自定义api域名。为空：使用sdk提供的默认域名。不为空：使用自定义域名或者ip进行请求。
/// 注意：如果 options.envConfig.apiServer 不为空，sdk会对其格式合法性进行验证，验证失败，返回 nil。
- (instancetype _Nullable)initWithAppId:(NSString *)appId delegate:(id<RZGMSDelegate> _Nullable)delegate options:(RZGMSOptions *_Nullable)options;

#pragma mark - login
- (void)loginByToken:(NSString *)token timeStamp:(int64_t)timeStamp userId:(NSString *)userId completion:(RZGMSLoginBlock)completionBlock;
- (void)logoutWithCompletion:(RZGMSLogoutBlock)completionBlock;
- (void)renewToken:(NSString *)token timeStamp:(int64_t)timeStamp completion:(RZGMSRenewTokenBlock)completionBlock;

#pragma mark - channel
- (RZGMSChannel *_Nullable)createChannelWithId:(NSString *)channelId delegate:(id<RZGMSChannelDelegate> _Nullable)delegate;
- (BOOL)destroyChannelWithId:(NSString *)channelId;
- (void)getChannelMemberCount:(NSArray<NSString *> *)channelIds completion:(RZChannelMemberCountBlock)completionBlock;

#pragma mark - channel attributes
- (void)setChannel:(NSString *)channelId attributes:(NSArray<RZGMSAttribute *> *_Nullable)attributes options:(RZGMSChannelAttributeOptions *)options completion:(RZGMSSetChannelAttributesBlock)completionBlock;
- (void)addOrUpdateChannel:(NSString *)channelId attributes:(NSArray<RZGMSAttribute *> *_Nullable)attributes options:(RZGMSChannelAttributeOptions *)options completion:(RZGMSAddOrUpdateChannelAttributesBlock)completionBlock;
- (void)deleteChannelAttributes:(NSString *)channelId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys options:(RZGMSChannelAttributeOptions *)options completion:(RZGMSDeleteChannelAttributesBlock)completionBlock;
- (void)clearChannelAttributes:(NSString *)channelId options:(RZGMSChannelAttributeOptions *)options completion:(RZGMSClearChannelAttributesBlock)completionBlock;
- (void)getChannelAttributes:(NSString *)channelId completion:(RZGMSGetChannelAttributesBlock)completionBlock;
- (void)getChannelAttributes:(NSString *)channelId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(RZGMSGetChannelAttributesBlock)completionBlock;

#pragma mark - user attributes
- (void)setLocalUserAttributes:(NSArray<RZGMSAttribute *> *_Nullable)attributes completion:(RZGMSSetLocalUserAttributesBlock)completionBlock;
- (void)addOrUpdateLocalUserAttributes:(NSArray<RZGMSAttribute *> *_Nullable)attributes completion:(RZGMSAddOrUpdateLocalUserAttributesBlock)completionBlock;
- (void)deleteLocalUserAttributesByKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(RZGMSDeleteLocalUserAttributesBlock)completionBlock;
- (void)clearLocalUserAttributesWithCompletion:(RZGMSClearLocalUserAttributesBlock)completionBlock;
- (void)getUserAttributes:(NSString *)userId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(RZGMSGetUserAttributesBlock)completionBlock;
- (void)getUserAttributes:(NSString *)userId completion:(RZGMSGetUserAttributesBlock)completionBlock;

#pragma mark - onlin status -
- (void)subscribePeersOnlineStatus:(NSArray<NSString *> *)peerIds completion:(RZGMSSubscriptionRequestBlock)completionBlock;
- (void)unsubscribePeersOnlineStatus:(NSArray<NSString *> *)peerIds completion:(RZGMSSubscriptionRequestBlock)completionBlock;
- (void)queryPeersOnlineStatus:(NSArray<NSString *> *)peerIds completion:(RZGMSQueryPeersOnlineBlock)completionBlock;
- (void)queryPeersBySubscriptionOption:(RZGMSPeerSubscriptionOptions)option completion:(RZGMSQueryPeersBySubscriptionOptionBlock)completionBlock;

#pragma mark - 呼叫邀请管理
///获取呼叫邀请实例，需要在登录后调用
- (RZGMSInvitationKit *)getGMSInvitationKit;

#pragma mark - 点对点消息
- (void)sendMessage:(RZGMSMessage *)message
             toPeer:(NSString *)peerId
 sendMessageOptions:(RZGMSSendMessageOptions *)options
         completion:(RZGMSSendPeerMessageBlock)completionBlock;

#pragma mark - 其他
- (int)setParameters:(NSString *)parameters;
- (void)setLogFile:(NSString *)logFile;
- (void)setLogFilters:(RZGMSLogFilter)filter;
+ (NSString *)getSDKVersion;

///返回sdk内部的一些状态，方便调试和排查问题
- (NSDictionary *)getDebugInfo;

@end

NS_ASSUME_NONNULL_END
