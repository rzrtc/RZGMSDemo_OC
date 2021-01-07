//
//  RZGMSChannel.h
//  RZ-GMS
//
//  Created by 钟凡 on 2020/7/15.
//

#import <Foundation/Foundation.h>
#import "RZGMSMessage.h"
#import "RZGMSMember.h"
#import "RZGMSSendMessageOptions.h"
#import "RZEnumerates.h"

@class RZGMSChannel;
@class RZGMSAttribute;

NS_ASSUME_NONNULL_BEGIN

typedef void (^RZGMSJoinChannelBlock)(RZGMSJoinChannelErrorCode errorCode);
typedef void (^RZGMSLeaveChannelBlock)(RZGMSLeaveChannelErrorCode errorCode);
typedef void (^RZGMSGetMembersBlock)(NSArray<RZGMSMember *> *_Nullable members, RZGMSGetMembersErrorCode errorCode);
typedef void (^RZGMSSendChannelMessageBlock)(RZGMSSendChannelMessageErrorCode errorCode);


@protocol RZGMSChannelDelegate <NSObject>
@optional

/**
 Occurs when a user joins the channel.
 
 When a remote user calls the [joinWithCompletion]([RZGMSChannel joinWithCompletion:]) method and successfully joins the channel, the local user receives this callback.
 
 **NOTE**
 
 This callback is disabled when the number of the channel members exceeds 512.
 
 @param channel The channel that the user joins. See RZGMSChannel.
 @param member The user joining the channel. See RZGMSMember.
 */
- (void)channel:(RZGMSChannel *)channel memberJoined:(RZGMSMember *)member;

/**
 Occurs when a channel member leaves the channel.
 
 When a remote channel member calls the [leaveWithCompletion]([RZGMSChannel leaveWithCompletion:]) method and successfully leaves the channel, the local user receives this callback.
 
 **NOTE**
 
 This callback is disabled when the number of the channel members exceeds 512.
 
 @param channel The channel that the user leaves. See RZGMSChannel.
 @param member The channel member that leaves the channel. See RZGMSMember.
 */
- (void)channel:(RZGMSChannel *)channel memberLeft:(RZGMSMember *)member;

/**
 Occurs when receiving a channel message.
 
 When a remote channel member calls the [sendMessage]([RZGMSChannel sendMessage:completion:]) method and successfully sends out a channel message, the local user receives this callback.
 
 @param channel The channel, to which the local user belongs. See RZGMSChannel.
 @param message The received channel message. See RZGMSMessage. Ensure that you check the `type` property when receiving the message instance: If the message type is `RZGMSMessageTypeRaw`, you need to downcast the received instance from RZGMSMessage to RZGMSRawMessage. See RZGMSMessageType.
 @param member The message sender. See RZGMSMember.
 */
- (void)channel:(RZGMSChannel *)channel messageReceived:(RZGMSMessage *)message fromMember:(RZGMSMember * _Nonnull)member;

/**
 Occurs when channel attributes are updated, and returns all attributes of the channel.
 
 **NOTE**
 
 This callback is enabled only when the user, who updates the attributes of the channel, sets [enableNotificationToChannelMembers]([RZGMSChannelAttributeOptions enableNotificationToChannelMembers]) as YES. Also note that this flag is valid only within the current channel attribute method call.
 
 @param channel The channel, to which the local user belongs. See RZGMSChannel.
 @param attributes An array of RZGMSChannelAttribute. See RZGMSChannelAttribute.
 */
- (void)channel:(RZGMSChannel *)channel attributeUpdate:(NSArray< RZGMSAttribute *> *)attributes;

/**
 Occurs when the number of the channel members changes, and returns the new number.
 
 **NOTE**
 
 - When the number of channel members &le; 512, the SDK returns this callback when the number changes and at a MAXIMUM speed of once per second.
 - When the number of channel members exceeds 512, the SDK returns this callback when the number changes and at a MAXIMUM speed of once every three seconds.
 - You will receive this callback when successfully joining an RTM channel, so Agore recommends implementing this callback to receive timely updates on the number of the channel members.
 
 @param channel The channel, to which the local user belongs. See RZGMSChannel.
 @param count Member count of this channel.
 */
- (void)channel:(RZGMSChannel *)channel memberCount:(int)count;

@end


@class RZGMSSocketManager;

@interface RZGMSChannel : NSObject

@property (nonatomic, weak, nullable) id<RZGMSChannelDelegate> delegate;
@property (nonatomic, copy) NSString *channelId;

- (void)joinWithCompletion:(RZGMSJoinChannelBlock)completionBlock;

- (void)leaveWithCompletion:(RZGMSLeaveChannelBlock)completionBlock;

- (void)sendMessage:(RZGMSMessage *)message options:(RZGMSSendMessageOptions *)options completion:(RZGMSSendChannelMessageBlock)completionBlock;

- (void)getMembersWithCompletion:(RZGMSGetMembersBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
