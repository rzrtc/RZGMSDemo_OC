---
title: sdk 使用
---
## 创建 [DbyGmsKit](./DbyGmsKit.md) 实例
```objectivec
//换成你自己的appid
DbyGmsKit *dbyGmsKit = [[DbyGmsKit alloc] initWithAppId:@"123" delegate:self];
```

## 创建 [DbyGmsChannel](./DbyGmsChannel.md) 实例
```objectivec
DbyGmsChannel *gmsChannel = [self.dbyGmsKit createChannelWithId:@"channelId" delegate:self];
```

## 销毁 [DbyGmsChannel](./DbyGmsChannel.md) 实例
```objectivec
- (BOOL)destroyChannelWithId:(NSString *)channelId;
```

## 获取 [DbyGmsInvitationKit](./DbyGmsInvitationKit.md) 实例
```objectivec
- (DbyGmsInvitationKit *)getGmsInvitationKit;
```

## 登录
```objectivec
NSString *token = @"token"; //换成自己的token
NSDate *date = [NSDate date];
int64_t ts = (int64_t)(date.timeIntervalSince1970 * 1000);
[self.dbyGmsKit loginByToken:token timeStamp:ts userId:uid completion:^(DbyGmsLoginErrorCode errorCode) {
    if (errorCode == DbyGmsLoginErrorOk) {
        
    }
}];
```

## 登出
```objectivec
[self.dbyGmsKit logoutWithCompletion:^(DbyGmsLogoutErrorCode errorCode) {
    if (errorCode == DbyGmsLogoutErrorOk) {
    }
}];
```

## 更新token
```objectivec
- (void)renewToken:(NSString *)token timeStamp:(NSTimeInterval)timeStamp completion:(DbyGmsRenewTokenBlock)completionBlock;
```
