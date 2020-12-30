---
title: RZGMSChannel
description: 认真通信 GMS - iOS 频道 API 参考文档。
---

## delegate
```objectivec
@property (nonatomic, weak, nullable) id<RZGMSChannelDelegate> delegate;
```
## channelId
```objectivec
@property (nonatomic, copy) NSString *channelId;
```

## joinWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [RZGMSJoinChannelBlock](#rzgmsjoinchannelblock)， 错误码[RZGMSJoinChannelErrorCode](./RZGMSEnum.md/#rzgmsjoinchannelerrorcode) |

## leaveWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [RZGMSLeaveChannelBlock](#rzgmsleavechannelblock)， 错误码[RZGMSLeaveChannelErrorCode](./RZGMSEnum.md/#rzgmsleavechannelerrorcode) |

## sendMessage
|  参数   | 描述  |
|  ----  | ----  |
| message  | [RZGMSMessage](./RZGMSModel.md/#rzgmsmessage) 可以发送文字和二进制 [RZGMSRawMessage](./RZGMSModel.md/#rzgmsrawmessage) 消息 |
| options  | [RZGMSSendMessageOptions](./RZGMSModel.md/#rzgmssendmessageoptions) 一些设置，如是否服务器缓存 |
| completionBlock  | [RZGMSSendChannelMessageBlock](#rzgmssendchannelmessageblock)， 错误码[RZGMSSendChannelMessageErrorCode](./RZGMSEnum.md/#rzgmsgetmemberserrorcode) |

## getMembersWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [RZGMSGetMembersBlock](#rzgmsgetmembersblock)， 错误码[RZGMSGetMembersErrorCode](./RZGMSEnum.md/#rzgmsgetmemberserrorcode) |

# RZGMSChannelDelegate

## memberJoined
```objectivec
- (void)channel:(RZGMSChannel * _Nonnull)channel memberJoined:(RZGMSMember * _Nonnull)member;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [RZGMSChannel](#)加入的频道 |
| member  | [RZGMSMember](./RZGMSModel.md/#rzgmsmember)加入的用户 |

## memberLeft
```objectivec
- (void)channel:(RZGMSChannel * _Nonnull)channel memberLeft:(RZGMSMember * _Nonnull)member;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [RZGMSChannel](#)离开的频道 |
| member  | [RZGMSMember](./RZGMSModel.md/#rzgmsmember)离开的用户 |

## messageReceived
```objectivec
- (void)channel:(RZGMSChannel * _Nonnull)channel messageReceived:(RZGMSMessage * _Nonnull)message fromMember:(RZGMSMember * _Nonnull)member;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [RZGMSChannel](#)当前频道 |
| message  | [RZGMSMessage](./RZGMSModel.md/#rzgmsmessage)收到的消息 |
| member  | [RZGMSMember](./RZGMSModel.md/#rzgmsmember)发送消息的用户 |

## attributeUpdate
```objectivec
- (void)channel:(RZGMSChannel * _Nonnull)channel attributeUpdate:(NSArray< RZGMSAttribute *> * _Nonnull)attributes;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [RZGMSChannel](#)当前频道 |
| attributes  | [RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute)频道属性 |

## memberCount
```objectivec
- (void)channel:(RZGMSChannel * _Nonnull)channel memberCount:(int)count;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [RZGMSChannel](#)当前频道 |
| count  | 频道人数 |


## Block
### RZGMSJoinChannelBlock
```objectivec
typedef void (^RZGMSJoinChannelBlock)(RZGMSJoinChannelErrorCode errorCode);
```
### RZGMSLeaveChannelBlock
```objectivec
typedef void (^RZGMSLeaveChannelBlock)(RZGMSLeaveChannelErrorCode errorCode);
```
### RZGMSGetMembersBlock
```objectivec
typedef void (^RZGMSGetMembersBlock)(NSArray< RZGMSMember *> * _Nullable members, RZGMSGetMembersErrorCode errorCode);
```
### RZGMSSendChannelMessageBlock
```objectivec
typedef void (^RZGMSSendChannelMessageBlock)(RZGMSSendChannelMessageErrorCode errorCode);
```
