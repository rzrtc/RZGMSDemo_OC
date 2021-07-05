//
//  RZGMSStateHelper.h
//  RZGMS
//
//  Created by yxibng on 2021/6/22.
//

#import <Foundation/Foundation.h>
#import "RZGMSAttribute.h"
#import "RZGMSChannel.h"

NS_ASSUME_NONNULL_BEGIN

@interface RZGMSChannelManager: NSObject
- (void)onJoinChannel:(RZGMSChannel *)channel;
- (void)onLeaveChannel:(RZGMSChannel *)channel;
- (void)logout;

//当前加入的频道
@property (nonatomic, strong, readonly) NSArray <RZGMSChannel *> *channels;

@end


#pragma mark -
@class RZGMSOnlinePeersManager;
@protocol RZGMSOnlinePeersManagerDelegate <NSObject>
- (void)onlinePeersManager:(RZGMSOnlinePeersManager *)manager onChangeOfStatus:(NSDictionary *)statusDic;
@end
@interface RZGMSOnlinePeersManager : NSObject
@property (nonatomic, weak) id<RZGMSOnlinePeersManagerDelegate>delegate;
- (void)onPeersOnlineStatusChanged:(NSDictionary *)statusDic;
- (void)unsubscribeOnlineStatusOf:(NSArray<NSString *> *)peerIds;
- (void)logout;
@end


@interface RZGMSLoginParams : NSObject

- (NSDictionary *)generateSocketConfig;

- (void)loginWithToken:(NSString *)token
                 appId:(NSString *)appId
                userId:(NSString *)userId
             timestamp:(int64_t)timestamp;


- (void)renewToken:(NSString *)token
         timestamp:(int64_t)timestamp;

- (void)logout;

@end
#pragma mark -
@interface RZGMSLocalUserAttributes : NSObject

@property (nonatomic, copy, readonly) NSDictionary *userAttributes;
@property (nonatomic, copy, readonly) NSArray<RZGMSAttribute *> *gmsAttributes;

- (void)setLocalUserAttributes:(NSDictionary *)attributes;
- (void)addOrUpdateLocalUserAttributes:(NSDictionary *)attributes;
- (void)deleteLocalUserAttributesByKeys:(NSArray<NSString *> *)keys;
- (void)clearLocalUserAttributes;
- (void)logout;

@end



@interface RZGMSStateHelper : NSObject

@property (nonatomic, copy, readonly) NSSet<NSString *> *subscribedOnlineStatusPeerIds;
@property (nonatomic, copy, readonly) NSSet<NSString *> *subscribedAttributesPeerIds;

@property (nonatomic, strong, readonly) RZGMSLoginParams *loginParams;
@property (nonatomic, strong, readonly) RZGMSLocalUserAttributes *localUserAttributes;
@property (nonatomic, strong, readonly) RZGMSOnlinePeersManager *onlinePeersManager;
@property (nonatomic, strong, readonly) RZGMSChannelManager *channelManager;


- (void)subscribeOnlineStatusOf:(NSArray<NSString *> *)peerIds;
- (void)unsubscribeOnlineStatusOf:(NSArray<NSString *> *)peerIds;

- (void)subscribeAttributesOf:(NSArray<NSString *> *)peerIds;
- (void)unsubscribeAttributesOf:(NSArray<NSString *> *)peerIds;

- (void)logout;

@end

NS_ASSUME_NONNULL_END
