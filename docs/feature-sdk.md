---
title: sdk 使用
---
## 创建 [RZGMSKit](./RZGMSKit.md) 实例
```objectivec
//换成你自己的appid
RZGMSKit *rzGMSKit = [[RZGMSKit alloc] initWithAppId:@"123" delegate:self];
```

## 创建 [RZGMSChannel](./RZGMSChannel.md) 实例
```objectivec
RZGMSChannel *gmsChannel = [self.rzGMSKit createChannelWithId:@"channelId" delegate:self];
```

## 销毁 [RZGMSChannel](./RZGMSChannel.md) 实例
```objectivec
- (BOOL)destroyChannelWithId:(NSString *)channelId;
```

## 获取 [RZGMSInvitationKit](./RZGMSInvitationKit.md) 实例
```objectivec
- (RZGMSInvitationKit *)getGMSInvitationKit;
```

## 登录
```objectivec
NSString *token = @"token"; //换成自己的token
NSDate *date = [NSDate date];
int64_t ts = (int64_t)(date.timeIntervalSince1970 * 1000);
[self.rzGMSKit loginByToken:token timeStamp:ts userId:uid completion:^(RZGMSLoginErrorCode errorCode) {
    if (errorCode == RZGMSLoginErrorOk) {
        
    }
}];
```

## 登出
```objectivec
[self.rzGMSKit logoutWithCompletion:^(RZGMSLogoutErrorCode errorCode) {
    if (errorCode == RZGMSLogoutErrorOk) {
    }
}];
```

## 更新token
```objectivec
- (void)renewToken:(NSString *)token timeStamp:(NSTimeInterval)timeStamp completion:(RZGMSRenewTokenBlock)completionBlock;
```
