---
title: RZGMSKit
description: "认真通信 GMS - iOS API 参考文档"
---
## Login
### initWithAppId
|  参数   | 描述  |
|  ----  | ----  |
| appId  | 应用id |
| delegate  | [RZGMSDelegate](#rzgmsdelegate) 接收事件 |

### loginByToken
|  参数   | 描述  |
|  ----  | ----  |
| token  | 校验身份用token |
| timeStamp  | 时间戳 毫秒 |
| userId  | 用户id |
| completion  | [RZGMSLoginBlock](#rzgmsloginblock)，错误码 [RZGMSLoginErrorCode](./RZGMSEnum.md/#rzgmsloginerrorcode)。 |

### logoutWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [RZGMSLogoutBlock](#rzgmslogoutblock)，错误码 [RZGMSLogoutErrorCode](./RZGMSEnum.md/#rzgmslogouterrorcode)。 |

### renewToken
|  参数   | 描述  |
|  ----  | ----  |
| token  | 新的token |
| timeStamp  | 时间戳 毫秒 |
| completionBlock  | [RZGMSRenewTokenBlock](#rzgmsrenewtokenblock)，错误码 [RZGMSRenewTokenErrorCode](./RZGMSEnum.md/#rzgmsrenewtokenerrorcode) 。|

### createChannelWithId
|  参数   | 描述  |
|  ----  | ----  |
| channelId | channelId 必须为不超过 64 字节的字符串，不能为空、nil，或设为 "null" |
| delegate  | 接收channel的相关通知 |
| return  | [RZGMSChannel](./RZGMSChannel.md) channel实例 |

### destroyChannelWithId
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |


### getChannelMemberCount
|  参数   | 描述  |
|  ----  | ----  |
| channelIds  | channelId数组 |
| completionBlock  | [RZChannelMemberCountBlock](#rzchannelmembercountblock)，结果 [RZChannelMemberCount](./RZGMSModel.md/#RZChannelMemberCount) 数组，错误码 [RZGMSChannelMemberCountErrorCode](./RZGMSEnum.md/#rzgmschannelmembercounterrorcode) 。|

## Channel
### setChannel
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute)数组 |
| options  | RZGMSChannelAttributeOptions |
| completionBlock  | [RZGMSSetChannelAttributesBlock](#rzgmssetchannelattributesblock)，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode)。 |

### addOrUpdateChannel
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute)数组 |
| options  | [RZGMSChannelAttributeOptions](./RZGMSModel.md/#rzgmschannelattributeoptions) |
| completionBlock  | [RZGMSAddOrUpdateChannelAttributesBlock](#rzgmsaddorupdatechannelattributesblock)，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode) 。|

### deleteChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute) 数组 |
| attributeKeys  | 字符串数组 |
| options  | [RZGMSChannelAttributeOptions](./RZGMSModel.md/#rzgmschannelattributeoptions) |
| completionBlock  | [RZGMSDeleteChannelAttributesBlock](#rzgmsdeletechannelattributesblock)，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode) 。|

### clearChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute) 数组 |
| options  | [RZGMSChannelAttributeOptions](./RZGMSModel.md/#rzgmschannelattributeoptions) |
| completionBlock  | [RZGMSClearChannelAttributesBlock](#rzgmsclearchannelattributesblock)，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode)。 |

### getChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| completionBlock  | [RZGMSGetChannelAttributesBlock](#rzgmsgetchannelattributesblock)，结果 [RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute) 数组，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode)。 |

### getChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributeKeys  | 字符串数组 |
| completionBlock  | [RZGMSGetChannelAttributesBlock](#rzgmsgetchannelattributesblock)，结果 [RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute) 数组，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode)。 |

## User

### setLocalUserAttributes
|  参数   | 描述  |
|  ----  | ----  |
| attributes  | [RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute) 数组 |
| completionBlock  | [RZGMSSetLocalUserAttributesBlock](#rzgmssetlocaluserattributesblock)，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode)。 |

### addOrUpdateLocalUserAttributes
|  参数   | 描述  |
|  ----  | ----  |
| attributes  | [RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute) 数组 |
| completionBlock  | [RZGMSAddOrUpdateLocalUserAttributesBlock](#rzgmsaddorupdatelocaluserattributesblock)，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode)。 |

### deleteLocalUserAttributesByKeys
|  参数   | 描述  |
|  ----  | ----  |
| attributeKeys  | 字符串数组 |
| completionBlock  | [RZGMSDeleteLocalUserAttributesBlock](#rzgmsdeletelocaluserattributesblock)，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode)。 |

### clearLocalUserAttributesWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [RZGMSClearLocalUserAttributesBlock](#rzgmsclearlocaluserattributesblock)，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode)。 |

### getUserAttributes
|  参数   | 描述  |
|  ----  | ----  |
| userId  | 用户的id |
| completionBlock  | [RZGMSGetUserAttributesBlock](#rzgmsgetuserattributesblock)，结果[RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute)数组，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode)。 |


### getUserAttributesByKeys
|  参数   | 描述  |
|  ----  | ----  |
| userId  | 用户的id |
| attributeKeys  | 指定的属性key数组 |
| completionBlock  | [RZGMSGetUserAttributesBlock](#rzgmsgetuserattributesblock)，结果[RZGMSAttribute](./RZGMSModel.md/#rzgmsattribute)数组，错误码 [RZGMSProcessAttributeErrorCode](./RZGMSEnum.md/#rzgmsprocessattributeerrorcode)。 |

### subscribePeersOnlineStatus
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [RZGMSSubscriptionRequestBlock](#rzgmssubscriptionrequestblock)，错误码 [RZGMSPeerSubscriptionStatusErrorCode](./RZGMSEnum.md/#rzgmspeersubscriptionstatuserrorcode) 。|

### unsubscribePeersOnlineStatus
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [RZGMSSubscriptionRequestBlock](#rzgmssubscriptionrequestblock)，错误码 [RZGMSPeerSubscriptionStatusErrorCode](./RZGMSEnum.md/#rzgmspeersubscriptionstatuserrorcode)。 |

### queryPeersOnlineStatus
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [RZGMSQueryPeersOnlineBlock](#rzgmsquerypeersonlineblock)，结果[RZGMSPeerOnlineStatus](./RZGMSModel.md/#RZGMSPeerOnlineStatus)数组，错误码 [RZGMSQueryPeersOnlineErrorCode](./RZGMSEnum.md/#rzgmsquerypeersonlineerrorcode)。 |

### queryPeersBySubscriptionOption
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [RZGMSSubscriptionRequestBlock](#rzgmssubscriptionrequestblock)，结果userId数组，错误码 [RZGMSPeerSubscriptionStatusErrorCode](./RZGMSEnum.md/#rzgmspeersubscriptionstatuserrorcode)。 |

## Invitation

### getGMSInvitationKit
|  参数   | 描述  |
|  ----  | ----  |
| return  | [RZGMSInvitationKit](./RZGMSInvitationKit.md) 实例 |

## Message

### sendMessage
发送点对点消息
|  参数   | 描述  |
|  ----  | ----  |
| message  | [RZGMSMessage](./RZGMSModel.md/#rzgmsmessage) 文本消息或者二进制消息 |
| peerId  | 接收消息用户的id |
| options  | [RZGMSSendMessageOptions](./RZGMSModel.md/#rzgmssendmessageoptions) 是否发生离线消息 |
| completionBlock  | [RZGMSSendPeerMessageBlock](#rzgmssendpeermessageblock)，错误码 [RZGMSSendPeerMessageErrorCode](./RZGMSEnum.md/#rzgmssendpeermessageerrorcode)。 |

## Other

### setLogFile
|  参数   | 描述  |
|  ----  | ----  |
| logFile  | 本地日志路径，不设置默认存储在`~Library/Caches/rz_gms.log` |

### setLogFilters
|  参数   | 描述  |
|  ----  | ----  |
| filter  | 控制台打印日志级别 [RZGMSLogFilter](./RZGMSEnum.md/#rzgmslogfilter) |

### getSDKVersion
|  参数   | 描述  |
|  ----  | ----  |
| return  | sdk的版本信息，包名，版本，编译数字等信息 |

## RZGMSDelegate

### connectionStateChanged
连接状态变化通知
```objectivec
- (void)rzGMSKit:(RZGMSKit *)kit connectionStateChanged:(RZGMSConnectionState)state reason:(RZGMSConnectionChangeReason)reason;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [RZGMSKit](#) 实例 |
| state  | [RZGMSConnectionState](./RZGMSEnum.md/#rzgmsconnectionstate) 状态 |
| reason  | [RZGMSConnectionChangeReason](./RZGMSEnum.md/#rzgmsconnectionchangereason) 产生这个状态的原因 |

### peersOnlineStatusChanged
用户状态变化通知
```objectivec
- (void)rzGMSKit:(RZGMSKit *)kit peersOnlineStatusChanged:(NSArray<RZGMSPeerOnlineStatus *> *_Nonnull)onlineStatus;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [RZGMSKit](#) 实例 |
| onlineStatus  | [RZGMSPeerOnlineStatus](./RZGMSModel.md/#rzgmspeeronlinestatus) 数组，在线用户的状态 |

### messageReceived
收到点对点消息
```objectivec
- (void)rzGMSKit:(RZGMSKit *)kit messageReceived:(RZGMSMessage *_Nonnull)message fromPeer:(NSString *_Nonnull)peerId;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [RZGMSKit](#) 实例 |
| message  | [RZGMSMessage](./RZGMSModel.md/#rzgmsmessage) 点对点消息 |
| peerId  | 用户id |

### invitationReceived
收到呼叫邀请
```objectivec
- (void)rzGMSKit:(RZGMSKit *)kit invitationReceived:(RZGMSInvitation *_Nonnull)invitation fromPeer:(NSString *_Nonnull)peerId;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [RZGMSKit](#) 实例 |
| invitation  | [RZGMSInvitation](./RZGMSModel.md/#rzgmsinvitation) 邀请实例 |
| peerId  | 用户id |


## Block
### RZGMSLoginBlock
```objectivec
typedef void (^RZGMSLoginBlock)(RZGMSLoginErrorCode errorCode);
```

### RZGMSLogoutBlock
```objectivec
typedef void (^RZGMSLogoutBlock)(RZGMSLogoutErrorCode errorCode);
```
### RZGMSSendPeerMessageBlock
```objectivec
typedef void (^RZGMSSendPeerMessageBlock)(RZGMSSendPeerMessageErrorCode errorCode);
```
### RZChannelMemberCountBlock
```objectivec
typedef void (^RZChannelMemberCountBlock)(NSArray<RZChannelMemberCount *> * _Nullable channelMemberCounts, RZGMSChannelMemberCountErrorCode errorCode);
```
### RZGMSQueryPeersOnlineBlock
```objectivec
typedef void (^RZGMSQueryPeersOnlineBlock)(NSArray<RZGMSPeerOnlineStatus *>  * _Nullable peerOnlineStatus, RZGMSQueryPeersOnlineErrorCode errorCode);
```
### RZGMSQueryPeersBySubscriptionOptionBlock
```objectivec
typedef void (^RZGMSQueryPeersBySubscriptionOptionBlock)(NSArray<NSString *> * _Nullable peers, RZGMSPeerSubscriptionStatusErrorCode errorCode);
```
### RZGMSSetChannelAttributesBlock
```objectivec
typedef void (^RZGMSSetChannelAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);
```
### RZGMSAddOrUpdateChannelAttributesBlock
```objectivec
typedef void (^RZGMSAddOrUpdateChannelAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);
```
### RZGMSDeleteChannelAttributesBlock
```objectivec
typedef void (^RZGMSDeleteChannelAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);
```
### RZGMSClearChannelAttributesBlock
```objectivec
typedef void (^RZGMSClearChannelAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);
```

### RZGMSGetChannelAttributesBlock
```objectivec
typedef void (^RZGMSGetChannelAttributesBlock)(NSArray< RZGMSAttribute *> * _Nullable attributes, RZGMSProcessAttributeErrorCode errorCode);
```

### RZGMSSetLocalUserAttributesBlock
```objectivec
typedef void (^RZGMSSetLocalUserAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);
```

### RZGMSAddOrUpdateLocalUserAttributesBlock
```objectivec
typedef void (^RZGMSAddOrUpdateLocalUserAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);
```

### RZGMSDeleteLocalUserAttributesBlock
```objectivec
typedef void (^RZGMSDeleteLocalUserAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);
```

### RZGMSClearLocalUserAttributesBlock
```objectivec
typedef void (^RZGMSClearLocalUserAttributesBlock)(RZGMSProcessAttributeErrorCode errorCode);
```

### RZGMSGetUserAttributesBlock
```objectivec
typedef void (^RZGMSGetUserAttributesBlock)(NSArray< RZGMSAttribute *> * _Nullable attributes, NSString * userId, RZGMSProcessAttributeErrorCode errorCode);
```

### RZGMSRenewTokenBlock
```objectivec
typedef void (^RZGMSRenewTokenBlock)(NSString *token, RZGMSRenewTokenErrorCode errorCode);
```

### RZGMSSubscriptionRequestBlock
```objectivec
typedef void (^RZGMSSubscriptionRequestBlock)(RZGMSPeerSubscriptionStatusErrorCode errorCode);
```
