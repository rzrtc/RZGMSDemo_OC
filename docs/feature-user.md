---
title: 用户的一些操作
---

## 查询用户属性
```objc
[self.gmsKit getUserAttributes:self.userId completion:^(NSArray<RZGMSAttribute *> * _Nullable attributes, NSString * _Nonnull userId, RZGMSProcessAttributeErrorCode errorCode) {
    if (errorCode == RZGMSProcessAttributeErrorOk && attributes) {
        
    }
}];
```

## 设置用户属性
```objc
RZGMSAttribute *att1 = [[RZGMSAttribute alloc] init];
att1.key = @"color";
att1.value = @"red";

RZGMSAttribute *att2 = [[RZGMSAttribute alloc] init];
att2.key = @"time";
att2.value = @"2020-05-14";

NSArray *attributes = @[att1, att2];

[self.gmsKit setLocalUserAttributes:attributes completion:^(RZGMSProcessAttributeErrorCode errorCode) {
    
}];
```

## 查询用户状态
查询之前先要订阅
```objc
[self.gmsKit queryPeersOnlineStatus:@[@"123"] completion:^(NSArray<RZGMSPeerOnlineStatus *> *_Nonnull peerOnlineStatus, RZGMSQueryPeersOnlineErrorCode errorCode) {
    
}];
```

## 订阅用户状态
```objc
[self.gmsKit subscribePeersOnlineStatus:@[@"123"] completion:^(RZGMSPeerSubscriptionStatusErrorCode errorCode) {

}];
```

## 取消订阅用户状态
```objc
[self.gmsKit unsubscribePeersOnlineStatus:peers completion:^(RZGMSPeerSubscriptionStatusErrorCode errorCode) {

}];
```

## 发送点对点消息
发送文本消息
```objc
RZGMSMessage *message = [[RZGMSMessage alloc] initWithText:@"message_123"];
RZGMSSendMessageOptions *options = [[RZGMSSendMessageOptions alloc] init];
options.enableOfflineMessaging = true;
[self.gmsKit sendMessage:message toPeer:@"123" sendMessageOptions:options completion:^(RZGMSSendPeerMessageErrorCode errorCode) {

}];
```
发送二进制消息
```
NSData *data = [@"rawMessage_123" dataUsingEncoding:NSUTF8StringEncoding];
RZGMSRawMessage *message = [[RZGMSRawMessage alloc] initWithRawData:data];
RZGMSSendMessageOptions *options = [[RZGMSSendMessageOptions alloc] init];
options.enableOfflineMessaging = true;
[self.gmsKit sendMessage:message toPeer:@"123" sendMessageOptions:options completion:^(RZGMSSendPeerMessageErrorCode errorCode) {

}];
```

## 接受点对点消息
需要从[RZGMSKit](./RZGMSKit.md)的delegate中获取到。
```objc
- (void)rzGMSKit:(RZGMSKit *)kit messageReceived:(RZGMSMessage *)message fromPeer:(NSString *)peerId {
    NSLog(@"---peerId: %@, message: %@", peerId, message.text);
}
```
暂时不支持接收二进制消息。
