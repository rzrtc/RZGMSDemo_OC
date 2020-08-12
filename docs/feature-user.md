---
title: 用户的一些操作
---

## 查询用户属性
```objc
[self.gmsKit getUserAttributes:self.userId completion:^(NSArray<DbyGmsAttribute *> * _Nullable attributes, NSString * _Nonnull userId, DbyGmsProcessAttributeErrorCode errorCode) {
    if (errorCode == DbyGmsProcessAttributeErrorOk && attributes) {
        
    }
}];
```

## 设置用户属性
```objc
DbyGmsAttribute *att1 = [[DbyGmsAttribute alloc] init];
att1.key = @"color";
att1.value = @"red";

DbyGmsAttribute *att2 = [[DbyGmsAttribute alloc] init];
att2.key = @"time";
att2.value = @"2020-05-14";

NSArray *attributes = @[att1, att2];

[self.gmsKit setLocalUserAttributes:attributes completion:^(DbyGmsProcessAttributeErrorCode errorCode) {
    
}];
```

## 查询用户状态
查询之前先要订阅
```objc
[self.gmsKit queryPeersOnlineStatus:@[@"123"] completion:^(NSArray<DbyGmsPeerOnlineStatus *> *_Nonnull peerOnlineStatus, DbyGmsQueryPeersOnlineErrorCode errorCode) {
    
}];
```

## 订阅用户状态
```objc
[self.gmsKit subscribePeersOnlineStatus:@[@"123"] completion:^(DbyGmsPeerSubscriptionStatusErrorCode errorCode) {

}];
```

## 取消订阅用户状态
```objc
[self.gmsKit unsubscribePeersOnlineStatus:peers completion:^(DbyGmsPeerSubscriptionStatusErrorCode errorCode) {

}];
```

## 发送点对点消息
发送文本消息
```objc
DbyGmsMessage *message = [[DbyGmsMessage alloc] initWithText:@"message_123"];
DbyGmsSendMessageOptions *options = [[DbyGmsSendMessageOptions alloc] init];
options.enableOfflineMessaging = true;
[self.gmsKit sendMessage:message toPeer:@"123" sendMessageOptions:options completion:^(DbyGmsSendPeerMessageErrorCode errorCode) {

}];
```
发送二进制消息
```
NSData *data = [@"rawMessage_123" dataUsingEncoding:NSUTF8StringEncoding];
DbyGmsRawMessage *message = [[DbyGmsRawMessage alloc] initWithRawData:data];
DbyGmsSendMessageOptions *options = [[DbyGmsSendMessageOptions alloc] init];
options.enableOfflineMessaging = true;
[self.gmsKit sendMessage:message toPeer:@"123" sendMessageOptions:options completion:^(DbyGmsSendPeerMessageErrorCode errorCode) {

}];
```

## 接受点对点消息
需要从[DbyGmsKit](./DbyGmsKit.md)的delegate中获取到。
```objc
- (void)dbyGmsKit:(DbyGmsKit *)kit messageReceived:(DbyGmsMessage *)message fromPeer:(NSString *)peerId {
    NSLog(@"---peerId: %@, message: %@", peerId, message.text);
}
```
暂时不支持接收二进制消息。
