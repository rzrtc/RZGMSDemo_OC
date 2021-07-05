//
//  RZEnumerates.h
//  RZ-GMS
//
//  Created by yxibng on 2020/5/13.
//

#ifndef RZEnumerates_h
#define RZEnumerates_h

#import <Foundation/Foundation.h>

#pragma mark - login

typedef NS_ENUM(NSInteger, RZGMSConnectionState) {
    RZGMSConnectionStateDisconnected = 1, //断开连接
    RZGMSConnectionStateConnecting = 2,   //正在连接
    RZGMSConnectionStateConnected = 3,    //已连接
    RZGMSConnectionStateReconnecting = 4, //已断开，正在重连
};
typedef NS_ENUM(NSInteger, RZGMSConnectionChangeReason) {
    RZGMSConnectionChangeReasonLogin = 1,          //sdk 正在登录
    RZGMSConnectionChangeReasonLoginSuccess = 2,   //sdk 已经登录
    RZGMSConnectionChangeReasonLoginFailure = 3,   //登录失败
    RZGMSConnectionChangeReasonLoginTimeout = 4,   //登录超时
    RZGMSConnectionChangeReasonInterrupted = 5,    //已登录，由于网络原因，断开连接了
    RZGMSConnectionChangeReasonLogout = 6,         //调用了logout
    RZGMSConnectionChangeReasonBannedByServer = 7, //登录被禁止
    RZGMSConnectionChangeReasonKickOff = 8,        //远端登录，本地被踢出
    RZGMSConnectionChangeReasonExpireSession = 9,  //session过期
};
typedef NS_ENUM(NSInteger, RZGMSLoginErrorCode) {
    RZGMSLoginErrorOk = 0,                    //登录成功
    RZGMSLoginErrorUnknown = 1,               //登录失败，原因未知
    RZGMSLoginErrorRejected = 2,              //登录被服务器拒绝
    RZGMSLoginErrorInvalidArgument = 3,       //参数错误
    RZGMSLoginErrorInvalidAppId = 4,          //App ID 无效
    RZGMSLoginErrorInvalidToken = 5,          //Token 无效
    RZGMSLoginErrorTokenExpired = 6,          //Token 已过期，登录被拒绝
    RZGMSLoginErrorNotAuthorized = 7,         //登录未经授权
    RZGMSLoginErrorAlreadyLogin = 8,          //用户已登录，或正在登录系统，或未调用 logoutWithCompletion 方法退出
    RZGMSLoginErrorTimeout = 9,               //登录超时。目前的超时设置为 6 秒。
    RZGMSLoginErrorLoginTooOften = 10,        //登录过于频繁。方法 loginByToken 的调用频率超过 2 次／秒的上限
};
typedef NS_ENUM(NSInteger, RZGMSLogoutErrorCode) {
    RZGMSLogoutErrorOk = 0,            //登出成功
    RZGMSLogoutErrorNotLoggedIn = 102, //未登录
};
typedef NS_ENUM(NSInteger, RZGMSRenewTokenErrorCode) {
    RZGMSRenewTokenErrorOk = 0,               //更新 Token 成功
    RZGMSRenewTokenErrorFailure = 1,          //更新 Token 失败
    RZGMSRenewTokenErrorInvalidArgument = 2,  //无效参数
    RZGMSRenewTokenErrorRejected = 3,         //预留错误码
    RZGMSRenewTokenErrorTooOften = 4,         //方法调用过于频繁。超过 2 次／秒上限
    RZGMSRenewTokenErrorTokenExpired = 5,     //输入 Token 已过期
    RZGMSRenewTokenErrorInvalidToken = 6,     //输入 Token 无效
    RZGMSRenewTokenErrorNotLoggedIn = 102,    //更新 Token 前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
#pragma mark - channel
typedef NS_ENUM(NSInteger, RZGMSJoinChannelErrorCode) {
    RZGMSJoinChannelErrorOk = 0,               //用户加入频道成功
    RZGMSJoinChannelErrorFailure = 1,          //用户加入频道失败
    RZGMSJoinChannelErrorRejected = 2,         //预留错误码
    RZGMSJoinChannelErrorInvalidArgument = 3,  //用户无法加入频道。因为参数无效
    RZGMSJoinChannelErrorTimeout = 4,          //用户加入频道超时。当前的超时设置为 5 秒。
    RZGMSJoinChannelErrorExceedLimit = 5,      //同时加入的频道数超过 20 上限。
    RZGMSJoinChannelErrorAlreadyJoined = 6,    //用户正在加入频道或已成功加入频道。
    RZGMSJoinChannelErrorTooOften = 7,         //方法调用超过 50 次每 3 秒的上限
    RZGMSJoinChannelErrorNotLoggedIn = 102,    //用户加入频道前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
typedef NS_ENUM(NSInteger, RZGMSLeaveChannelErrorCode) {
    RZGMSLeaveChannelErrorOk = 0,               //用户离开频道成功
    RZGMSLeaveChannelErrorFailure = 1,          //用户离开频道失败
    RZGMSLeaveChannelErrorRejected = 2,         //预留错误码
    RZGMSLeaveChannelErrorNotInChannel = 3,     //用户不在频道内
    RZGMSLeaveChannelErrorNotLoggedIn = 102,    //未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};

typedef NS_ENUM(NSInteger, RZGMSMemberLeaveChannelReason) {
    RZGMSMemberLeaveChannelReasonUnknown = 0,   // 原因未知
    RZGMSMemberLeaveChannelReasonQuit = 1,      // 用户主动调用leave接口
    RZGMSMemberLeaveChannelReasonDisconnect = 2,// 服务端只感知到了用户断开连接，用户未调用leave接口
};


typedef NS_ENUM(NSInteger, RZGMSChannelMemberCountErrorCode) {
    RZGMSChannelMemberCountErrorOk = 0,               //获取指定频道成员人数成功
    RZGMSChannelMemberCountErrorFailure = 1,          //通用未知错误
    RZGMSChannelMemberCountErrorInvalidArgument = 2,  //频道 ID 无效
    RZGMSChannelMemberCountErrorTooOften = 3,         //方法调用过于频繁。超过每秒 1 次的限制
    RZGMSChannelMemberCountErrorTimeout = 4,          //服务器响应超时。当前的当前的超时设定为 5 秒
    RZGMSChannelMemberCountErrorExceedLimit = 5,      //查询频道数超过 32 条上限
    RZGMSChannelMemberCountErrorNotLoggedIn = 102,    //本次操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
typedef NS_ENUM(NSInteger, RZGMSGetMembersErrorCode) {
    RZGMSGetMembersErrorOk = 0,               //频道成员列表获取成功
    RZGMSGetMembersErrorFailure = 1,          //频道成员列表获取失败
    RZGMSGetMembersErrorRejected = 2,         //预留错误码
    RZGMSGetMembersErrorTimeout = 3,          //获取频道内成员列表超时。当前的超时设置为 5 秒
    RZGMSGetMembersErrorTooOften = 4,         //方法调用频率超过 5 次每 2 秒的上限
    RZGMSGetMembersErrorNotInChannel = 5,     //用户不在频道内
    RZGMSGetMembersErrorNotLoggedIn = 102,    //获取频道成员列表前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
typedef NS_ENUM(NSInteger, RZGMSSendChannelMessageErrorCode) {
    RZGMSSendChannelMessageErrorOk = 0,               //服务端已接收到频道消息
    RZGMSSendChannelMessageErrorFailure = 1,          //频道消息发送失败
    RZGMSSendChannelMessageErrorTimeout = 2,          //服务器未收到频道消息或者 SDK 未在 10 秒内收到服务器响应
    RZGMSSendChannelMessageTooOften = 3,              //发送消息（点对点消息和频道消息一并计算在内）超过 60 次／秒的上限
    RZGMSSendChannelMessageInvalidMessage = 4,        //消息为 null 或超出 32 KB 的长度限制
    RZGMSSendChannelMessageErrorNotInChannel = 5,     //不在频道内
    RZGMSSendChannelMessageNotLoggedIn = 102,         //用户未登录
};
#pragma mark - user
typedef NS_ENUM(NSInteger, RZGMSProcessAttributeErrorCode) {
    RZGMSAttributeOperationErrorOk = 0,               //操作成功
    RZGMSAttributeOperationErrorFailure = 2,          //操作失败
    RZGMSAttributeOperationErrorInvalidArgument = 3,  //无效参数
    RZGMSAttributeOperationErrorSizeOverflow = 4,     //用户属性或频道属性超过上限
    RZGMSAttributeOperationErrorTooOften = 5,         //方法调用频率超过限制
    RZGMSAttributeOperationErrorUserNotFound = 6,     //未找到指定用户
    RZGMSAttributeOperationErrorTimeout = 7,          //属性操作超时。当前的超时设定为 5 秒
    RZGMSAttributeOperationErrorNotLoggedIn = 102,    //执行用户属性操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
typedef NS_ENUM(NSInteger, RZGMSQueryPeersOnlineErrorCode) {
    RZGMSQueryPeersOnlineErrorOk = 0,               //查询成功
    RZGMSQueryPeersOnlineErrorFailure = 1,          //查询失败
    RZGMSQueryPeersOnlineErrorInvalidArgument = 2,  //查询参数不合法
    RZGMSQueryPeersOnlineErrorRejected = 3,         //预留错误码
    RZGMSQueryPeersOnlineErrorTimeout = 4,          //服务器响应超时
    RZGMSQueryPeersOnlineErrorTooOften = 5,         //方法调用过于频繁。超过 10 次每 5 秒的上限。
    RZGMSQueryPeersOnlineErrorNotLoggedIn = 102,    //查询指定用户在线状态前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
typedef NS_ENUM(NSInteger, RZGMSPeerSubscriptionStatusErrorCode) {
    RZGMSPeerSubscriptionStatusErrorOk = 0,               //方法调用成功，或订阅退订操作成功
    RZGMSPeerSubscriptionStatusErrorFailure = 1,          //通用未知错误。订阅或退订操作失败
    RZGMSPeerSubscriptionStatusErrorInvalidArgument = 2,  //无效的输入参数
    RZGMSPeerSubscriptionStatusErrorRejected = 3,         //预留错误码
    RZGMSPeerSubscriptionStatusErrorTimeout = 4,          //服务器响应超时
    RZGMSPeerSubscriptionStatusErrorTooOften = 5,         //方法调用过于频繁
    RZGMSPeerSubscriptionStatusErrorOverflow = 6,         //订阅人数超过 512 人的上限
    RZGMSPeerSubscriptionStatusErrorNotLoggedIn = 102,    //本次操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
typedef NS_ENUM(NSInteger, RZGMSPeerSubscriptionOptions) {
    RZGMSPeerSubscriptionOnlineStatus = 0, //用户在线状态
    RZGMSPeerSubscriptionUserAttributes = 1 //用户属性
};

typedef NS_ENUM(NSInteger, RZGMSSendPeerMessageErrorCode) {
    RZGMSSendPeerMessageErrorOk = 0,               //对端已接收到点对点消息
    RZGMSSendPeerMessageErrorFailure = 1,          //点对点消息发送失败
    RZGMSSendPeerMessageErrorTimeout = 2,          //点对点消息发送超时
    RZGMSSendPeerMessageErrorPeerUnreachable = 3,  //接收者处于离线状态，无法接收点对点消息
    RZGMSSendPeerMessageErrorCachedByServer = 4,   //服务器已经缓存这条消息并将在用户上线后重新发送
    RZGMSSendPeerMessageErrorTooOften = 5,         //发送消息（点对点消息和频道消息一并计算在内）超过 60 次／秒的上限
    RZGMSSendPeerMessageErrorInvalidUserId = 6,    //用户 ID 无效
    RZGMSSendPeerMessageErrorInvalidMessage = 7,   //消息为 null 或超出 32 KB 的长度限制
    RZGMSSendPeerMessageErrorNotLoggedIn = 102,    //发送点对点消息前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
#pragma mark - invitation
typedef NS_ENUM(NSInteger, RZGMSInvitationApiCallErrorCode) {
    RZGMSInvitationApiCallErrorOk = 0,              //呼叫邀请相关 API 调用成功
    RZGMSInvitationApiCallErrorFailure = 1,         //呼叫邀请相关 API 调用失败：未知错误
    RZGMSInvitationApiCallErrorInvalidArgument = 2, //呼叫邀请相关 API 调用失败：参数错误
    RZGMSInvitationApiCallErrorInvalidState = 3,    //呼叫邀请相关 API 调用失败：状态错误
    RZGMSInvitationApiCallErrorPeerOffline = 4,     //呼叫邀请相关 API 调用失败：用户不在线
    RZGMSInvitationApiCallErrorWrongIdentity = 5,   //呼叫邀请相关 API 调用失败：非法身份调用
    RZGMSInvitationApiCallErrorNotLoggedIn = 102,   //呼叫邀请相关 API 调用失败：未登录
};
typedef NS_ENUM(NSInteger, RZGMSInvitationErrorCode) {
    RZGMSInvitationErrorCodeErrorOk = 0,                //呼叫邀请成功
    RZGMSInvitationErrorCodeErrorRemoteOffline = 1,     //呼叫邀请失败：对方不在线
    RZGMSInvitationErrorCodeErrorRemoteNoResponse = 2,  //呼叫邀请失败：服务器未返回任何数据
    RZGMSInvitationErrorCodeErrorExpire = 3,            //呼叫邀请失败：超时
    RZGMSInvitationErrorCodeErrorNotLoggedIn = 4,       //呼叫邀请失败：未登录
};
typedef NS_ENUM(NSInteger, RZGMSInvitationState) {
    RZGMSInvitationStateIdle = 0,     //初始状态
    RZGMSInvitationStateFailure = 1,  //呼叫失败
    RZGMSInvitationStateArrived = 2,  //呼叫到达
    RZGMSInvitationStateCanceled = 3, //呼叫被取消
    RZGMSInvitationStateAccepted = 4, //呼叫被接受
    RZGMSInvitationStateRefused = 5,  //呼叫被拒绝
};
#pragma mark - log
typedef NS_ENUM(NSInteger, RZGMSLogFilter) {
    RZGMSLogFilterOff = 0,           //关闭
    RZGMSLogFilterInfo = 1 << 0,     //普通
    RZGMSLogFilterWarn = 1 << 1,     //警告
    RZGMSLogFilterError = 1 << 2,    //错误
    RZGMSLogFilterCritical = 1 << 3, //严重
    RZGMSLogFilterMask = 0x1111,     //所有
};

#endif /* RZEnumerates_h */
