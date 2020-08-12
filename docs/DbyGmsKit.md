---
title: DbyGmsKit
description: "多贝云 Gms - iOS API 参考文档"
---
## Login
### initWithAppId
|  参数   | 描述  |
|  ----  | ----  |
| appId  | 应用id |
| delegate  | [DbyGmsDelegate](#dbygmsdelegate) 接收事件 |

### loginByToken
|  参数   | 描述  |
|  ----  | ----  |
| token  | 校验身份用token |
| timeStamp  | 时间戳 毫秒 |
| userId  | 用户id |
| completion  | [DbyGmsLoginBlock](#dbygmsloginblock)，错误码 [DbyGmsLoginErrorCode](./DbyGmsEnum.md/#dbygmsloginerrorcode)。 |

### logoutWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [DbyGmsLogoutBlock](#dbygmslogoutblock)，错误码 [DbyGmsLogoutErrorCode](./DbyGmsEnum.md/#dbygmslogouterrorcode)。 |

### renewToken
|  参数   | 描述  |
|  ----  | ----  |
| token  | 新的token |
| timeStamp  | 时间戳 毫秒 |
| completionBlock  | [DbyGmsRenewTokenBlock](#dbygmsrenewtokenblock)，错误码 [DbyGmsRenewTokenErrorCode](./DbyGmsEnum.md/#dbygmsrenewtokenerrorcode) 。|

### createChannelWithId
|  参数   | 描述  |
|  ----  | ----  |
| channelId | channelId 必须为不超过 64 字节的字符串，不能为空、nil，或设为 "null" |
| delegate  | 接收channel的相关通知 |
| return  | [DbyGmsChannel](./DbyGmsChannel.md) channel实例 |

### destroyChannelWithId
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |


### getChannelMemberCount
|  参数   | 描述  |
|  ----  | ----  |
| channelIds  | channelId数组 |
| completionBlock  | [DbyChannelMemberCountBlock](#dbychannelmembercountblock)，结果 [DbyChannelMemberCount](./DbyGmsModel.md/#DbyChannelMemberCount) 数组，错误码 [DbyGmsChannelMemberCountErrorCode](./DbyGmsEnum.md/#dbygmschannelmembercounterrorcode) 。|

## Channel
### setChannel
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute)数组 |
| options  | DbyGmsChannelAttributeOptions |
| completionBlock  | [DbyGmsSetChannelAttributesBlock](#dbygmssetchannelattributesblock)，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode)。 |

### addOrUpdateChannel
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute)数组 |
| options  | [DbyGmsChannelAttributeOptions](./DbyGmsModel.md/#dbygmschannelattributeoptions) |
| completionBlock  | [DbyGmsAddOrUpdateChannelAttributesBlock](#dbygmsaddorupdatechannelattributesblock)，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode) 。|

### deleteChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute) 数组 |
| attributeKeys  | 字符串数组 |
| options  | [DbyGmsChannelAttributeOptions](./DbyGmsModel.md/#dbygmschannelattributeoptions) |
| completionBlock  | [DbyGmsDeleteChannelAttributesBlock](#dbygmsdeletechannelattributesblock)，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode) 。|

### clearChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute) 数组 |
| options  | [DbyGmsChannelAttributeOptions](./DbyGmsModel.md/#dbygmschannelattributeoptions) |
| completionBlock  | [DbyGmsClearChannelAttributesBlock](#dbygmsclearchannelattributesblock)，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode)。 |

### getChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| completionBlock  | [DbyGmsGetChannelAttributesBlock](#dbygmsgetchannelattributesblock)，结果 [DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute) 数组，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode)。 |

### getChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributeKeys  | 字符串数组 |
| completionBlock  | [DbyGmsGetChannelAttributesBlock](#dbygmsgetchannelattributesblock)，结果 [DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute) 数组，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode)。 |

## User

### setLocalUserAttributes
|  参数   | 描述  |
|  ----  | ----  |
| attributes  | [DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute) 数组 |
| completionBlock  | [DbyGmsSetLocalUserAttributesBlock](#dbygmssetlocaluserattributesblock)，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode)。 |

### addOrUpdateLocalUserAttributes
|  参数   | 描述  |
|  ----  | ----  |
| attributes  | [DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute) 数组 |
| completionBlock  | [DbyGmsAddOrUpdateLocalUserAttributesBlock](#dbygmsaddorupdatelocaluserattributesblock)，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode)。 |

### deleteLocalUserAttributesByKeys
|  参数   | 描述  |
|  ----  | ----  |
| attributeKeys  | 字符串数组 |
| completionBlock  | [DbyGmsDeleteLocalUserAttributesBlock](#dbygmsdeletelocaluserattributesblock)，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode)。 |

### clearLocalUserAttributesWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [DbyGmsClearLocalUserAttributesBlock](#dbygmsclearlocaluserattributesblock)，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode)。 |

### getUserAttributes
|  参数   | 描述  |
|  ----  | ----  |
| userId  | 用户的id |
| completionBlock  | [DbyGmsGetUserAttributesBlock](#dbygmsgetuserattributesblock)，结果[DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute)数组，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode)。 |


### getUserAttributesByKeys
|  参数   | 描述  |
|  ----  | ----  |
| userId  | 用户的id |
| attributeKeys  | 指定的属性key数组 |
| completionBlock  | [DbyGmsGetUserAttributesBlock](#dbygmsgetuserattributesblock)，结果[DbyGmsAttribute](./DbyGmsModel.md/#dbygmsattribute)数组，错误码 [DbyGmsProcessAttributeErrorCode](./DbyGmsEnum.md/#dbygmsprocessattributeerrorcode)。 |

### subscribePeersOnlineStatus
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [DbyGmsSubscriptionRequestBlock](#dbygmssubscriptionrequestblock)，错误码 [DbyGmsPeerSubscriptionStatusErrorCode](./DbyGmsEnum.md/#dbygmspeersubscriptionstatuserrorcode) 。|

### unsubscribePeersOnlineStatus
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [DbyGmsSubscriptionRequestBlock](#dbygmssubscriptionrequestblock)，错误码 [DbyGmsPeerSubscriptionStatusErrorCode](./DbyGmsEnum.md/#dbygmspeersubscriptionstatuserrorcode)。 |

### queryPeersOnlineStatus
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [DbyGmsQueryPeersOnlineBlock](#dbygmsquerypeersonlineblock)，结果[DbyGmsPeerOnlineStatus](./DbyGmsModel.md/#DbyGmsPeerOnlineStatus)数组，错误码 [DbyGmsQueryPeersOnlineErrorCode](./DbyGmsEnum.md/#dbygmsquerypeersonlineerrorcode)。 |

### queryPeersBySubscriptionOption
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [DbyGmsSubscriptionRequestBlock](#dbygmssubscriptionrequestblock)，结果userId数组，错误码 [DbyGmsPeerSubscriptionStatusErrorCode](./DbyGmsEnum.md/#dbygmspeersubscriptionstatuserrorcode)。 |

## Invitation

### getGmsInvitationKit
|  参数   | 描述  |
|  ----  | ----  |
| return  | [DbyGmsInvitationKit](./DbyGmsInvitationKit.md) 实例 |

## Message

### sendMessage
发送点对点消息
|  参数   | 描述  |
|  ----  | ----  |
| message  | [DbyGmsMessage](./DbyGmsModel.md/#dbygmsmessage) 文本消息或者二进制消息 |
| peerId  | 接收消息用户的id |
| options  | [DbyGmsSendMessageOptions](./DbyGmsModel.md/#dbygmssendmessageoptions) 是否发生离线消息 |
| completionBlock  | [DbyGmsSendPeerMessageBlock](#dbygmssendpeermessageblock)，错误码 [DbyGmsSendPeerMessageErrorCode](./DbyGmsEnum.md/#dbygmssendpeermessageerrorcode)。 |

## Other

### setLogFile
|  参数   | 描述  |
|  ----  | ----  |
| logFile  | 本地日志路径，不设置默认存储在`~Library/Caches/dby_gms.log` |

### setLogFilters
|  参数   | 描述  |
|  ----  | ----  |
| filter  | 控制台打印日志级别 [DbyGmsLogFilter](./DbyGmsEnum.md/#dbygmslogfilter) |

### getSDKVersion
|  参数   | 描述  |
|  ----  | ----  |
| return  | sdk的版本信息，包名，版本，编译数字等信息 |

## DbyGmsDelegate

### connectionStateChanged
连接状态变化通知
```objectivec
- (void)dbyGmsKit:(DbyGmsKit *)kit connectionStateChanged:(DbyGmsConnectionState)state reason:(DbyGmsConnectionChangeReason)reason;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [DbyGmsKit](#) 实例 |
| state  | [DbyGmsConnectionState](./DbyGmsEnum.md/#dbygmsconnectionstate) 状态 |
| reason  | [DbyGmsConnectionChangeReason](./DbyGmsEnum.md/#dbygmsconnectionchangereason) 产生这个状态的原因 |

### peersOnlineStatusChanged
用户状态变化通知
```objectivec
- (void)dbyGmsKit:(DbyGmsKit *)kit peersOnlineStatusChanged:(NSArray<DbyGmsPeerOnlineStatus *> *_Nonnull)onlineStatus;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [DbyGmsKit](#) 实例 |
| onlineStatus  | [DbyGmsPeerOnlineStatus](./DbyGmsModel.md/#dbygmspeeronlinestatus) 数组，在线用户的状态 |

### messageReceived
收到点对点消息
```objectivec
- (void)dbyGmsKit:(DbyGmsKit *)kit messageReceived:(DbyGmsMessage *_Nonnull)message fromPeer:(NSString *_Nonnull)peerId;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [DbyGmsKit](#) 实例 |
| message  | [DbyGmsMessage](./DbyGmsModel.md/#dbygmsmessage) 点对点消息 |
| peerId  | 用户id |

### invitationReceived
收到呼叫邀请
```objectivec
- (void)dbyGmsKit:(DbyGmsKit *)kit invitationReceived:(DbyGmsInvitation *_Nonnull)invitation fromPeer:(NSString *_Nonnull)peerId;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [DbyGmsKit](#) 实例 |
| invitation  | [DbyGmsInvitation](./DbyGmsModel.md/#dbygmsinvitation) 邀请实例 |
| peerId  | 用户id |


## Block
### DbyGmsLoginBlock
```objectivec
typedef void (^DbyGmsLoginBlock)(DbyGmsLoginErrorCode errorCode);
```

### DbyGmsLogoutBlock
```objectivec
typedef void (^DbyGmsLogoutBlock)(DbyGmsLogoutErrorCode errorCode);
```
### DbyGmsSendPeerMessageBlock
```objectivec
typedef void (^DbyGmsSendPeerMessageBlock)(DbyGmsSendPeerMessageErrorCode errorCode);
```
### DbyChannelMemberCountBlock
```objectivec
typedef void (^DbyChannelMemberCountBlock)(NSArray<DbyChannelMemberCount *> * _Nullable channelMemberCounts, DbyGmsChannelMemberCountErrorCode errorCode);
```
### DbyGmsQueryPeersOnlineBlock
```objectivec
typedef void (^DbyGmsQueryPeersOnlineBlock)(NSArray<DbyGmsPeerOnlineStatus *>  * _Nullable peerOnlineStatus, DbyGmsQueryPeersOnlineErrorCode errorCode);
```
### DbyGmsQueryPeersBySubscriptionOptionBlock
```objectivec
typedef void (^DbyGmsQueryPeersBySubscriptionOptionBlock)(NSArray<NSString *> * _Nullable peers, DbyGmsPeerSubscriptionStatusErrorCode errorCode);
```
### DbyGmsSetChannelAttributesBlock
```objectivec
typedef void (^DbyGmsSetChannelAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);
```
### DbyGmsAddOrUpdateChannelAttributesBlock
```objectivec
typedef void (^DbyGmsAddOrUpdateChannelAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);
```
### DbyGmsDeleteChannelAttributesBlock
```objectivec
typedef void (^DbyGmsDeleteChannelAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);
```
### DbyGmsClearChannelAttributesBlock
```objectivec
typedef void (^DbyGmsClearChannelAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);
```

### DbyGmsGetChannelAttributesBlock
```objectivec
typedef void (^DbyGmsGetChannelAttributesBlock)(NSArray< DbyGmsAttribute *> * _Nullable attributes, DbyGmsProcessAttributeErrorCode errorCode);
```

### DbyGmsSetLocalUserAttributesBlock
```objectivec
typedef void (^DbyGmsSetLocalUserAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);
```

### DbyGmsAddOrUpdateLocalUserAttributesBlock
```objectivec
typedef void (^DbyGmsAddOrUpdateLocalUserAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);
```

### DbyGmsDeleteLocalUserAttributesBlock
```objectivec
typedef void (^DbyGmsDeleteLocalUserAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);
```

### DbyGmsClearLocalUserAttributesBlock
```objectivec
typedef void (^DbyGmsClearLocalUserAttributesBlock)(DbyGmsProcessAttributeErrorCode errorCode);
```

### DbyGmsGetUserAttributesBlock
```objectivec
typedef void (^DbyGmsGetUserAttributesBlock)(NSArray< DbyGmsAttribute *> * _Nullable attributes, NSString * userId, DbyGmsProcessAttributeErrorCode errorCode);
```

### DbyGmsRenewTokenBlock
```objectivec
typedef void (^DbyGmsRenewTokenBlock)(NSString *token, DbyGmsRenewTokenErrorCode errorCode);
```

### DbyGmsSubscriptionRequestBlock
```objectivec
typedef void (^DbyGmsSubscriptionRequestBlock)(DbyGmsPeerSubscriptionStatusErrorCode errorCode);
```
