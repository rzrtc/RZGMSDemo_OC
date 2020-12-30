---
title: RZGMSInvitationKit
description: "认真通信 GMS - iOS 呼叫邀请 API 参考文档"
---
## Invitation
### sendInvitation
| 参数       | 描述                                                              |
| ---------- | ----------------------------------------------------------------- |
| invitation | [RZGMSInvitation](#) 实例                        |
| completion | [RZGMSInvitationSendBlock](#rzgmsinvitationsendblock)，错误码 [RZGMSInvitationApiCallErrorCode](./RZGMSEnum.md/#rzgmsinvitationapicallerrorcode) |

### cancelInvitation
| 参数       | 描述                                                                |
| ---------- | ------------------------------------------------------------------- |
| invitation | [RZGMSInvitation](#) 实例                          |
| completion | [RZGMSInvitationCancelBlock]()，错误码 [RZGMSInvitationApiCallErrorCode](./RZGMSEnum.md/#) |

### acceptInvitation
| 参数       | 描述                                                                |
| ---------- | ------------------------------------------------------------------- |
| invitation | [RZGMSInvitation](#) 实例                          |
| completion | [RZGMSInvitationAcceptBlock]()，错误码 [RZGMSInvitationApiCallErrorCode](./RZGMSEnum.md/#) |

### refuseInvitation
| 参数       | 描述                                                                |
| ---------- | ------------------------------------------------------------------- |
| invitation | [RZGMSInvitation](#) 实例                          |
| completion | [RZGMSInvitationRefuseBlock]()，错误码 [RZGMSInvitationApiCallErrorCode](./RZGMSEnum.md/#) |

## RZGMSInvitationDelegate

### invitationFailed
```objectivec
- (void)gmsInvitationKit:(RZGMSInvitationKit *_Nonnull)invitationKit invitationFailed:(RZGMSInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [RZGMSInvitationKit](#) 实例 |
| invitation    | [RZGMSInvitation](./RZGMSModel.md/#rzgmsinvitation) 实例 |

### invitationArrived
```objectivec
- (void)gmsInvitationKit:(RZGMSInvitationKit *_Nonnull)invitationKit invitationArrived:(RZGMSInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [RZGMSInvitationKit](#) 实例 |
| invitation    | [RZGMSInvitation](./RZGMSModel.md/#rzgmsinvitation) 实例    |

### invitationCanceled
```objectivec
- (void)gmsInvitationKit:(RZGMSInvitationKit *_Nonnull)invitationKit invitationCanceled:(RZGMSInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [RZGMSInvitationKit](#) 实例 |
| invitation    | [RZGMSInvitation](./RZGMSModel.md/#rzgmsinvitation) 实例    |

### invitationAccept
```objectivec
- (void)gmsInvitationKit:(RZGMSInvitationKit *_Nonnull)invitationKit invitationAccept:(RZGMSInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [RZGMSInvitationKit](#) 实例 |
| invitation    | [RZGMSInvitation](./RZGMSModel.md/#rzgmsinvitation) 实例    |

### invitationRefused
```objectivec
- (void)gmsInvitationKit:(RZGMSInvitationKit *_Nonnull)invitationKit invitationRefused:(RZGMSInvitation *_Nonnull)invitation;
```
| 参数          | 描述                                            |
| ------------- | ----------------------------------------------- |
| invitationKit | [RZGMSInvitationKit](#)实例 |
| invitation    | [RZGMSInvitation](./RZGMSModel.md/#rzgmsinvitation) 实例 |

## Block
### RZGMSInvitationSendBlock
```objectivec
typedef void (^RZGMSInvitationSendBlock)(RZGMSInvitationApiCallErrorCode errorCode);
```
### RZGMSInvitationAcceptBlock
```objectivec
typedef void (^RZGMSInvitationAcceptBlock)(RZGMSInvitationApiCallErrorCode errorCode);
```
### RZGMSInvitationRefuseBlock
```objectivec
typedef void (^RZGMSInvitationRefuseBlock)(RZGMSInvitationApiCallErrorCode errorCode);
```
### RZGMSInvitationCancelBlock
```objectivec
typedef void (^RZGMSInvitationCancelBlock)(RZGMSInvitationApiCallErrorCode errorCode);
```
