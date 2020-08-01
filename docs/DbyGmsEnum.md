---
title: DbyGmsEnum
description: "多贝云 Gms - iOS API 参考文档"
---

## Login
### DbyGmsConnectionState
```objc
typedef NS_ENUM(NSInteger, DbyGmsConnectionState) {
    DbyGmsConnectionStateDisconnected = 1, //断开连接
    DbyGmsConnectionStateConnecting = 2,   //正在连接
    DbyGmsConnectionStateConnected = 3,    //已连接
    DbyGmsConnectionStateReconnecting = 4, //已断开，正在重连
    DbyGmsConnectionStateAborted = 5,      //被踢出，终止
};
```

### DbyGmsConnectionChangeReason
```objc
typedef NS_ENUM(NSInteger, DbyGmsConnectionChangeReason) {
    DbyGmsConnectionChangeReasonLogin = 1,          //sdk 正在登录
    DbyGmsConnectionChangeReasonLoginSuccess = 2,   //sdk 已经登录
    DbyGmsConnectionChangeReasonLoginFailure = 3,   //登录失败
    DbyGmsConnectionChangeReasonLoginTimeout = 4,   //登录超时
    DbyGmsConnectionChangeReasonInterrupted = 5,    //已登录，由于网络原因，断开连接了
    DbyGmsConnectionChangeReasonLogout = 6,         //调用了logout
    DbyGmsConnectionChangeReasonBannedByServer = 7, //登录被禁止
    DbyGmsConnectionChangeReasonRemoteLogin = 8,    //远端登录，本地被踢出
};
```
### DbyGmsLoginErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsLoginErrorCode) {
    DbyGmsLoginErrorOk = 0,                    //登录成功
    DbyGmsLoginErrorUnknown = 1,               //登录失败，原因未知
    DbyGmsLoginErrorRejected = 2,              //登录被服务器拒绝
    DbyGmsLoginErrorInvalidArgument = 3,       //参数错误
    DbyGmsLoginErrorInvalidAppId = 4,          //App ID 无效
    DbyGmsLoginErrorInvalidToken = 5,          //Token 无效
    DbyGmsLoginErrorTokenExpired = 6,          //Token 已过期，登录被拒绝
    DbyGmsLoginErrorNotAuthorized = 7,         //登录未经授权
    DbyGmsLoginErrorAlreadyLogin = 8,          //用户已登录，或正在登录系统，或未调用 logoutWithCompletion 方法退出
    DbyGmsLoginErrorTimeout = 9,               //登录超时。目前的超时设置为 6 秒。
    DbyGmsLoginErrorLoginTooOften = 10,        //登录过于频繁。方法 loginByToken 的调用频率超过 2 次／秒的上限
    DbyGmsLoginErrorLoginNotInitialized = 101, //SDK 未完成初始化
};
```
### DbyGmsLogoutErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsLogoutErrorCode ) {
    DbyGmsLogoutErrorOk = 0,                    //登出成功
    DbyGmsLogoutErrorNotLoggedIn = 102,         //未登录
};
```
### DbyGmsRenewTokenErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsRenewTokenErrorCode) {
DbyGmsRenewTokenErrorOk = 0,                //更新 Token 成功
DbyGmsRenewTokenErrorFailure = 1,           //更新 Token 失败
DbyGmsRenewTokenErrorInvalidArgument = 2,   //无效参数
DbyGmsRenewTokenErrorRejected = 3,          //预留错误码
DbyGmsRenewTokenErrorTooOften = 4,          //方法调用过于频繁。超过 2 次／秒上限
DbyGmsRenewTokenErrorTokenExpired = 5,      //输入 Token 已过期
DbyGmsRenewTokenErrorInvalidToken = 6,      //输入 Token 无效
DbyGmsRenewTokenErrorNotInitialized = 101,  //SDK 未完成初始化
DbyGmsRenewTokenErrorNotLoggedIn = 102,     //更新 Token 前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```

## Channel
### DbyGmsJoinChannelErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsJoinChannelErrorCode) {
    DbyGmsJoinChannelErrorOk = 0,               //用户成功加入频道
    DbyGmsJoinChannelErrorFailure = 1,          //用户加入频道失败
    DbyGmsJoinChannelErrorRejected = 2,         //预留错误码
    DbyGmsJoinChannelErrorInvalidArgument = 3,  //用户无法加入频道。因为参数无效
    DbyGmsJoinChannelErrorTimeout = 4,          //用户加入频道超时。当前的超时设置为 5 秒。
    DbyGmsJoinChannelErrorExceedLimit = 5,      //同时加入的频道数超过 20 上限。
    DbyGmsJoinChannelErrorAlreadyJoined = 6,    //用户正在加入频道或已成功加入频道。
    DbyGmsJoinChannelErrorTooOften = 7,         //方法调用超过 50 次每 3 秒的上限
    DbyGmsJoinSameChannelErrorTooOften = 8,     //加入相同频道的频率超过每 5 秒 2 次的上限
    DbyGmsJoinChannelErrorNotInitialized = 101, //SDK 未完成初始化
    DbyGmsJoinChannelErrorNotLoggedIn = 102,    //用户加入频道前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```
### DbyGmsLeaveChannelErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsLeaveChannelErrorCode) {
    DbyGmsLeaveChannelErrorOk = 0,              //用户离开频道成功
    DbyGmsLeaveChannelErrorFailure = 1,         //用户离开频道失败
    DbyGmsLeaveChannelErrorRejected = 2,        //预留错误码
    DbyGmsLeaveChannelErrorNotInChannel = 3,    //用户不在频道内
    DbyGmsLeaveChannelErrorNotInitialized = 101,//SDK 未完成初始化
    DbyGmsLeaveChannelErrorNotLoggedIn = 102,   //未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```
### DbyGmsChannelMemberCountErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsChannelMemberCountErrorCode) {
    DbyGmsChannelMemberCountErrorOk = 0,               //获取指定频道成员人数成功
    DbyGmsChannelMemberCountErrorFailure = 1,          //通用未知错误
    DbyGmsChannelMemberCountErrorInvalidArgument = 2,  //频道 ID 无效
    DbyGmsChannelMemberCountErrorTooOften = 3,         //方法调用过于频繁。超过每秒 1 次的限制
    DbyGmsChannelMemberCountErrorTimeout = 4,          //服务器响应超时。当前的当前的超时设定为 5 秒
    DbyGmsChannelMemberCountErrorExceedLimit = 5,      //查询频道数超过 32 条上限
    DbyGmsChannelMemberCountErrorNotInitialized = 101, //sdk 服务未完成初始化
    DbyGmsChannelMemberCountErrorNotLoggedIn = 102,    //本次操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```
### DbyGmsGetMembersErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsGetMembersErrorCode) {
    DbyGmsGetMembersErrorOk = 0,               //频道成员列表获取成功
    DbyGmsGetMembersErrorFailure = 1,          //频道成员列表获取失败
    DbyGmsGetMembersErrorRejected = 2,         //预留错误码
    DbyGmsGetMembersErrorTimeout = 3,          //获取频道内成员列表超时。当前的超时设置为 5 秒
    DbyGmsGetMembersErrorTooOften = 4,         //方法调用频率超过 5 次每 2 秒的上限
    DbyGmsGetMembersErrorNotInChannel = 5,     //用户不在频道内
    DbyGmsGetMembersErrorNotInitialized = 101, //SDK 未完成初始化
    DbyGmsGetMembersErrorNotLoggedIn = 102,    //获取频道成员列表前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```
### DbyGmsSendChannelMessageErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsSendChannelMessageErrorCode) {
    DbyGmsSendChannelMessageErrorOk = 0,               //服务端已接收到频道消息
    DbyGmsSendChannelMessageErrorFailure = 1,          //频道消息发送失败
    DbyGmsSendChannelMessageErrorTimeout = 2,          //服务器未收到频道消息或者 SDK 未在 10 秒内收到服务器响应
    DbyGmsSendChannelMessageTooOften = 3,              //发送消息（点对点消息和频道消息一并计算在内）超过 60 次／秒的上限
    DbyGmsSendChannelMessageInvalidMessage = 4,        //消息为 null 或超出 32 KB 的长度限制
    DbyGmsSendChannelMessageErrorNotInChannel = 5,     //不在频道内
    DbyGmsSendChannelMessageErrorNotInitialized = 101, //SDK 未完成初始化
    DbyGmsSendChannelMessageNotLoggedIn = 102,         //用户未登录
};
```
## User
### DbyGmsProcessAttributeErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsProcessAttributeErrorCode) {
    DbyGmsAttributeOperationErrorOk = 0,                //操作成功
    DbyGmsAttributeOperationErrorFailure = 2,           //操作失败
    DbyGmsAttributeOperationErrorInvalidArgument = 3,   //无效参数
    DbyGmsAttributeOperationErrorSizeOverflow = 4,      //用户属性或频道属性超过上限
    DbyGmsAttributeOperationErrorTooOften = 5,          //方法调用频率超过限制
    DbyGmsAttributeOperationErrorUserNotFound = 6,      //未找到指定用户
    DbyGmsAttributeOperationErrorTimeout = 7,           //属性操作超时。当前的超时设定为 5 秒
    DbyGmsAttributeOperationErrorNotInitialized = 101,  //SDK 未完成初始化
    DbyGmsAttributeOperationErrorNotLoggedIn = 102,     //执行用户属性操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```

### DbyGmsQueryPeersOnlineErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsProcessAttributeErrorCode) {
    DbyGmsAttributeOperationErrorOk = 0,                //操作成功
    DbyGmsAttributeOperationErrorFailure = 2,           //操作失败
    DbyGmsAttributeOperationErrorInvalidArgument = 3,   //无效参数
    DbyGmsAttributeOperationErrorSizeOverflow = 4,      //用户属性或频道属性超过上限
    DbyGmsAttributeOperationErrorTooOften = 5,          //方法调用频率超过限制
    DbyGmsAttributeOperationErrorUserNotFound = 6,      //未找到指定用户
    DbyGmsAttributeOperationErrorTimeout = 7,           //属性操作超时。当前的超时设定为 5 秒
    DbyGmsAttributeOperationErrorNotInitialized = 101,  //SDK 未完成初始化
    DbyGmsAttributeOperationErrorNotLoggedIn = 102,     //执行用户属性操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```

### DbyGmsPeerSubscriptionStatusErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsPeerSubscriptionStatusErrorCode) {
    DbyGmsPeerSubscriptionStatusErrorOk = 0,                //方法调用成功，或订阅退订操作成功
    DbyGmsPeerSubscriptionStatusErrorFailure = 1,           //通用未知错误。订阅或退订操作失败
    DbyGmsPeerSubscriptionStatusErrorInvalidArgument = 2,   //无效的输入参数
    DbyGmsPeerSubscriptionStatusErrorRejected = 3,          //预留错误码
    DbyGmsPeerSubscriptionStatusErrorTimeout = 4,           //服务器响应超时
    DbyGmsPeerSubscriptionStatusErrorTooOften = 5,          //方法调用过于频繁
    DbyGmsPeerSubscriptionStatusErrorOverflow = 6,          //订阅人数超过 512 人的上限
    DbyGmsPeerSubscriptionStatusErrorNotInitialized = 101,  //SDK 未完成初始化
    DbyGmsPeerSubscriptionStatusErrorNotLoggedIn = 102,     //本次操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```

### DbyGmsPeerSubscriptionOptions
```objc
typedef NS_ENUM(NSInteger, DbyGmsPeerSubscriptionOptions) {
    DbyGmsPeerSubscriptionOnlineStatus = 0, //用户在线状态
};
```

### DbyGmsSendPeerMessageErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsSendPeerMessageErrorCode) {
    DbyGmsSendPeerMessageErrorOk = 0,               //对端已接收到点对点消息
    DbyGmsSendPeerMessageErrorFailure = 1,          //点对点消息发送失败
    DbyGmsSendPeerMessageErrorTimeout = 2,          //点对点消息发送超时
    DbyGmsSendPeerMessageErrorPeerUnreachable = 3,  //接收者处于离线状态，无法接收点对点消息
    DbyGmsSendPeerMessageErrorCachedByServer = 4,   //服务器已经缓存这条消息并将在用户上线后重新发送
    DbyGmsSendPeerMessageErrorTooOften = 5,         //发送消息（点对点消息和频道消息一并计算在内）超过 60 次／秒的上限
    DbyGmsSendPeerMessageErrorInvalidUserId = 6,    //用户 ID 无效
    DbyGmsSendPeerMessageErrorInvalidMessage = 7,   //消息为 null 或超出 32 KB 的长度限制
    DbyGmsSendPeerMessageErrorNotInitialized = 101, //SDK 未完成初始化
    DbyGmsSendPeerMessageErrorNotLoggedIn = 102,    //发送点对点消息前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```
### DbyGmsInvitationApiCallErrorCode
```objc
typedef NS_ENUM(NSInteger, DbyGmsInvitationApiCallErrorCode) {
    DbyGmsInvitationApiCallErrorOk = 0,              //呼叫邀请相关 API 调用成功
    DbyGmsInvitationApiCallErrorFailure = 1,         //呼叫邀请相关 API 调用失败：未知错误
    DbyGmsInvitationApiCallErrorInvalidArgument = 2, //呼叫邀请相关 API 调用失败：参数错误
    DbyGmsInvitationApiCallErrorInvalidState = 3,    //呼叫邀请相关 API 调用失败：状态错误
    DbyGmsInvitationApiCallErrorPeerOffline = 4,     //呼叫邀请相关 API 调用失败：用户不在线
    DbyGmsInvitationApiCallErrorWrongIdentity = 5,   //呼叫邀请相关 API 调用失败：非法身份调用
    DbyGmsInvitationApiCallErrorNotLoggedIn = 102,   //呼叫邀请相关 API 调用失败：未登录
};
```
### DbyGmsInvitationState
```objc
typedef NS_ENUM(NSInteger, DbyGmsInvitationState) {
    DbyGmsInvitationStateIdle = 0,     //初始状态
    DbyGmsInvitationStateFailure = 1,  //呼叫失败
    DbyGmsInvitationStateArrived = 2,  //呼叫到达
    DbyGmsInvitationStateCanceled = 3, //呼叫被取消
    DbyGmsInvitationStateAccepted = 4, //呼叫被接受
    DbyGmsInvitationStateRefused = 5,  //呼叫被拒绝
};
```
## Log
### DbyGmsLogFilter
```objc
typedef NS_ENUM(NSInteger, DbyGmsLogFilter) {
    DbyGmsLogFilterOff = 0,             //关闭
    DbyGmsLogFilterInfo = 1 << 0,       //普通
    DbyGmsLogFilterWarn = 1 << 1,       //警告
    DbyGmsLogFilterError = 1 << 2,      //错误
    DbyGmsLogFilterCritical = 1 << 3,   //严重
    DbyGmsLogFilterMask = 0x1111,       //所有
};
```
