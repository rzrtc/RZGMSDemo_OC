## Requirements

- iOS 9.0+

## Installation

### CocoaPods

[CocoaPods](https://cocoapods.org) 是iOS的一个依赖管理工具。使用它我们可以很方便的集成sdk, 在你的 `Podfile` 中添加这些配置:

```ruby
pod 'DbyGms'
```

## 使用
### demo运行
在有`podfile`的目录下，打开命令行，执行`pod install`。然后打开`.xcworkspace`。

### SDK 包含以下模块：
- [`GmsClient`](./docs/DbyGmsKit.md) sdk 实例
- [`GmsChannel`](./docs/DbyGmsChannel.md) 频道实例
- [`GmsInvitationManager`](./docs/DbyGmsInvitationKit.md) 邀请管理器
- [数据模型](./docs/DbyGmsModel.md) 
- [错误码和状态码](./docs/DbyGmsEnum.md)

## FAQ
- `Unable to find a pod with name, author, summary, or description matching "DbyGms"`
打开命令行工具，执行以下命令`rm -rf ~/Library/Caches/CocoaPods` `pod repo update`。

- 登录遇到了问题
请填写正确的appid和token。
```objc
[[DbyGmsKit alloc] initWithAppId:@"appid" delegate:self];
[dbyGmsKit loginByToken:token timeStamp:ts userId:uid completion:completion];
```

- 如何计算token
token 计算参考demo

## 注意事项


