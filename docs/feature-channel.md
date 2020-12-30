---
title: channel 使用
---

通过[sdk](./feature-sdk.md)创建频道

## 加入频道
```objectivec
[_gmsChannel joinWithCompletion:^(RZGMSJoinChannelErrorCode errorCode) {
    if (errorCode == RZGMSJoinChannelErrorOk) {
        
    }
}];
```

## 离开频道
```objectivec
[_gmsChannel leaveWithCompletion:^(RZGMSLeaveChannelErrorCode errorCode) {
    if (errorCode == RZGMSLeaveChannelErrorOk) {
        
    }
}];
```

## 发送频道消息
```objectivec
RZGMSSendMessageOptions *options = [[RZGMSSendMessageOptions alloc] init];
options.enableOfflineMessaging = true;
[_gmsChannel sendMessage:message options:options completion:^(RZGMSSendChannelMessageErrorCode errorCode) {
    if (errorCode == RZGMSSendChannelMessageErrorOk) {

    }
}];
```

## 获取频道成员列表
```objectivec
[_gmsChannel getMembersWithCompletion:^(NSArray<RZGMSMember *> * _Nullable members, RZGMSGetMembersErrorCode errorCode) {
    if (errorCode == RZGMSGetMembersErrorOk && members) {

    }
}];
```
