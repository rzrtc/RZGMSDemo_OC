//
//  DbyGmsChannel.h
//  DBY-GMS
//
//  Created by 钟凡 on 2020/7/15.
//

#import <Foundation/Foundation.h>
#import "DbyGmsMessage.h"
#import "DbyGmsMember.h"
#import "DbyGmsSendMessageOptions.h"
#import "DbyEnumerates.h"

@class DbyGmsChannel;
@class DbyGmsAttribute;

@protocol DbyGmsChannelDelegate <NSObject>

@optional

/**
 Occurs when a user joins the channel.
 
 When a remote user calls the [joinWithCompletion]([DbyGmsChannel joinWithCompletion:]) method and successfully joins the channel, the local user receives this callback.
 
 **NOTE**
 
 This callback is disabled when the number of the channel members exceeds 512.
 
 @param channel The channel that the user joins. See DbyGmsChannel.
 @param member The user joining the channel. See DbyGmsMember.
 */
- (void)channel:(DbyGmsChannel * _Nonnull)channel memberJoined:(DbyGmsMember * _Nonnull)member;

/**
 Occurs when a channel member leaves the channel.
 
 When a remote channel member calls the [leaveWithCompletion]([DbyGmsChannel leaveWithCompletion:]) method and successfully leaves the channel, the local user receives this callback.
 
 **NOTE**
 
 This callback is disabled when the number of the channel members exceeds 512.
 
 @param channel The channel that the user leaves. See DbyGmsChannel.
 @param member The channel member that leaves the channel. See DbyGmsMember.
 */
- (void)channel:(DbyGmsChannel * _Nonnull)channel memberLeft:(DbyGmsMember * _Nonnull)member;

/**
 Occurs when receiving a channel message.
 
 When a remote channel member calls the [sendMessage]([DbyGmsChannel sendMessage:completion:]) method and successfully sends out a channel message, the local user receives this callback.
 
 @param channel The channel, to which the local user belongs. See DbyGmsChannel.
 @param message The received channel message. See DbyGmsMessage. Ensure that you check the `type` property when receiving the message instance: If the message type is `DbyGmsMessageTypeRaw`, you need to downcast the received instance from DbyGmsMessage to DbyGmsRawMessage. See DbyGmsMessageType.
 @param member The message sender. See DbyGmsMember.
 */
- (void)channel:(DbyGmsChannel * _Nonnull)channel messageReceived:(DbyGmsMessage * _Nonnull)message fromMember:(DbyGmsMember * _Nonnull)member;

/**
 Occurs when channel attributes are updated, and returns all attributes of the channel.
 
 **NOTE**
 
 This callback is enabled only when the user, who updates the attributes of the channel, sets [enableNotificationToChannelMembers]([DbyGmsChannelAttributeOptions enableNotificationToChannelMembers]) as YES. Also note that this flag is valid only within the current channel attribute method call.
 
 @param channel The channel, to which the local user belongs. See DbyGmsChannel.
 @param attributes An array of DbyGmsChannelAttribute. See DbyGmsChannelAttribute.
 */
- (void)channel:(DbyGmsChannel * _Nonnull)channel attributeUpdate:(NSArray< DbyGmsAttribute *> * _Nonnull)attributes;


/**
 Occurs when the number of the channel members changes, and returns the new number.
 
 **NOTE**
 
 - When the number of channel members &le; 512, the SDK returns this callback when the number changes and at a MAXIMUM speed of once per second.
 - When the number of channel members exceeds 512, the SDK returns this callback when the number changes and at a MAXIMUM speed of once every three seconds.
 - You will receive this callback when successfully joining an RTM channel, so Agore recommends implementing this callback to receive timely updates on the number of the channel members.
 
 @param channel The channel, to which the local user belongs. See DbyGmsChannel.
 @param count Member count of this channel.
 */
- (void)channel:(DbyGmsChannel * _Nonnull)channel memberCount:(int)count;

@end

typedef void (^DbyGmsJoinChannelBlock)(DbyGmsJoinChannelErrorCode errorCode);
typedef void (^DbyGmsLeaveChannelBlock)(DbyGmsLeaveChannelErrorCode errorCode);
typedef void (^DbyGmsGetMembersBlock)(NSArray<DbyGmsMember *> * _Nullable members, DbyGmsGetMembersErrorCode errorCode);
typedef void (^DbyGmsSendChannelMessageBlock)(DbyGmsSendChannelMessageErrorCode errorCode);

NS_ASSUME_NONNULL_BEGIN

@class DbyGmsSocketManager;

@interface DbyGmsChannel : NSObject

@property (nonatomic, weak, nullable) id<DbyGmsChannelDelegate> delegate;
@property (nonatomic, copy) NSString *channelId;

- (instancetype)initWithSocketManager:(DbyGmsSocketManager *)manager;

- (void)joinWithCompletion:(DbyGmsJoinChannelBlock _Nullable)completionBlock;

- (void)leaveWithCompletion:(DbyGmsLeaveChannelBlock _Nullable)completionBlock;

- (void)sendMessage:(DbyGmsMessage *_Nonnull)message options:(DbyGmsSendMessageOptions *_Nonnull)options completion:(DbyGmsSendChannelMessageBlock _Nullable)completionBlock;

- (void)getMembersWithCompletion:(DbyGmsGetMembersBlock _Nullable)completionBlock;

@end

NS_ASSUME_NONNULL_END
