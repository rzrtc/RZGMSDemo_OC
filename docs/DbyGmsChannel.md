---
title: DbyGmsChannel
description: 多贝云 Gms - iOS 频道 API 参考文档。
---

## delegate
```objectivec
@property (nonatomic, weak, nullable) id<DbyGmsChannelDelegate> delegate;
```
## channelId
```objectivec
@property (nonatomic, copy) NSString *channelId;
```

## joinWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [DbyGmsJoinChannelBlock](#dbygmsjoinchannelblock)， 错误码[DbyGmsJoinChannelErrorCode](./DbyGmsEnum.md/#dbygmsjoinchannelerrorcode) |

## leaveWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [DbyGmsLeaveChannelBlock](#dbygmsleavechannelblock)， 错误码[DbyGmsLeaveChannelErrorCode](./DbyGmsEnum.md/#dbygmsleavechannelerrorcode) |

## sendMessage
|  参数   | 描述  |
|  ----  | ----  |
| message  | [DbyGmsMessage](./DbyGmsModel.md/#dbygmsmessage) 可以发送文字和二进制 [DbyGmsRawMessage](./DbyGmsModel.md/#dbygmsrawmessage) 消息 |
| options  | [DbyGmsSendMessageOptions](./DbyGmsModel.md/#dbygmssendmessageoptions) 一些设置，如是否服务器缓存 |
| completionBlock  | [DbyGmsSendChannelMessageBlock](#dbygmssendchannelmessageblock)， 错误码[DbyGmsSendChannelMessageErrorCode](./DbyGmsEnum.md/#dbygmsgetmemberserrorcode) |

## getMembersWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [DbyGmsGetMembersBlock](#dbygmsgetmembersblock)， 错误码[DbyGmsGetMembersErrorCode](./DbyGmsEnum.md/#dbygmsgetmemberserrorcode) |

# DbyGmsChannelDelegate

## memberJoined
```objectivec
- (void)channel:(DbyGmsChannel * _Nonnull)channel memberJoined:(DbyGmsMember * _Nonnull)member;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [DbyGmsChannel](#)加入的频道 |
| member  | [DbyGmsMember](./DbyGmsModel.md/#dbygmsmember)加入的用户 |

## memberLeft
```objectivec
- (void)channel:(DbyGmsChannel * _Nonnull)channel memberLeft:(DbyGmsMember * _Nonnull)member;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [DbyGmsChannel](#)离开的频道 |
| member  | [DbyGmsMember](./DbyGmsModel.md/#dbygmsmember)离开的用户 |

## messageReceived
```objectivec
- (void)channel:(DbyGmsChannel * _Nonnull)channel messageReceived:(DbyGmsMessage * _Nonnull)message fromMember:(DbyGmsMember * _Nonnull)member;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [DbyGmsChannel](#)当前频道 |
| message  | [DbyGmsMessage](./DbyGmsModel.md/#dbygmsmessage)收到的消息 |
| member  | [DbyGmsMember](./DbyGmsModel.md/#dbygmsmember)发送消息的用户 |

## attributeUpdate
```objectivec
- (void)channel:(DbyGmsChannel * _Nonnull)channel attributeUpdate:(NSArray< DbyGmsAttribute *> * _Nonnull)attributes;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [DbyGmsChannel](#)当前频道 |
| attributes  | [DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute)频道属性 |

## memberCount
```objectivec
- (void)channel:(DbyGmsChannel * _Nonnull)channel memberCount:(int)count;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [DbyGmsChannel](#)当前频道 |
| count  | 频道人数 |


## Block
### DbyGmsJoinChannelBlock
```objectivec
typedef void (^DbyGmsJoinChannelBlock)(DbyGmsJoinChannelErrorCode errorCode);
```
### DbyGmsLeaveChannelBlock
```objectivec
typedef void (^DbyGmsLeaveChannelBlock)(DbyGmsLeaveChannelErrorCode errorCode);
```
### DbyGmsGetMembersBlock
```objectivec
typedef void (^DbyGmsGetMembersBlock)(NSArray< DbyGmsMember *> * _Nullable members, DbyGmsGetMembersErrorCode errorCode);
```
### DbyGmsSendChannelMessageBlock
```objectivec
typedef void (^DbyGmsSendChannelMessageBlock)(DbyGmsSendChannelMessageErrorCode errorCode);
```
