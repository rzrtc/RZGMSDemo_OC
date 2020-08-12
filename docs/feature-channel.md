---
title: channel 使用
---

通过[sdk](./feature-sdk.md)创建频道

## 加入频道
```objectivec
[_gmsChannel joinWithCompletion:^(DbyGmsJoinChannelErrorCode errorCode) {
    if (errorCode == DbyGmsJoinChannelErrorOk) {
        
    }
}];
```

## 离开频道
```objectivec
[_gmsChannel leaveWithCompletion:^(DbyGmsLeaveChannelErrorCode errorCode) {
    if (errorCode == DbyGmsLeaveChannelErrorOk) {
        
    }
}];
```

## 发送频道消息
```objectivec
DbyGmsSendMessageOptions *options = [[DbyGmsSendMessageOptions alloc] init];
options.enableOfflineMessaging = true;
[_gmsChannel sendMessage:message options:options completion:^(DbyGmsSendChannelMessageErrorCode errorCode) {
    if (errorCode == DbyGmsSendChannelMessageErrorOk) {

    }
}];
```

## 获取频道成员列表
```objectivec
[_gmsChannel getMembersWithCompletion:^(NSArray<DbyGmsMember *> * _Nullable members, DbyGmsGetMembersErrorCode errorCode) {
    if (errorCode == DbyGmsGetMembersErrorOk && members) {

    }
}];
```
