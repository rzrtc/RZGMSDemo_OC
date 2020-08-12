---
title: 呼叫邀请使用
---
通过[sdk](./feature-sdk.md)获取呼叫邀请实例

## 发起呼叫邀请
```objectivec
DbyGmsInvitation *invitation = [[DbyGmsInvitation alloc] initWithInviter:@"fromUserId" invitee:@"toUserId"];
[_invitationKit sendInvitation:invitation completion:^(DbyGmsInvitationApiCallErrorCode errorCode) {

}];
```

收到呼叫邀请后会通过[_invitationKit](./DbyGmsInvitationKit.md)的[delegate](./DbyGmsInvitationKit.md/#dbygmsinvitationdelegate)通知给你。
## 取消呼叫邀请
```objectivec
[_invitationKit cancelInvitation:invitation completion:^(DbyGmsInvitationApiCallErrorCode errorCode) {

}];
```

## 接受呼叫邀请
```objectivec
[_invitationKit acceptInvitation:invitation completion:^(DbyGmsInvitationApiCallErrorCode errorCode) {

}];
```

## 拒绝呼叫邀请
```objectivec
[_invitationKit refuseInvitation:invitation completion:^(DbyGmsInvitationApiCallErrorCode errorCode) {

}];
```
