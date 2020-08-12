---
title: DbyGmsInvitationKit
description: "多贝云 Gms - iOS 呼叫邀请 API 参考文档"
---
## Invitation
### sendInvitation
| 参数       | 描述                                                              |
| ---------- | ----------------------------------------------------------------- |
| invitation | [DbyGmsInvitation](#) 实例                        |
| completion | [DbyGmsInvitationSendBlock](#dbygmsinvitationsendblock)，错误码 [DbyGmsInvitationApiCallErrorCode](./DbyGmsEnum.md/#dbygmsinvitationapicallerrorcode) |

### cancelInvitation
| 参数       | 描述                                                                |
| ---------- | ------------------------------------------------------------------- |
| invitation | [DbyGmsInvitation](#) 实例                          |
| completion | [DbyGmsInvitationCancelBlock]()，错误码 [DbyGmsInvitationApiCallErrorCode](./DbyGmsEnum.md/#) |

### acceptInvitation
| 参数       | 描述                                                                |
| ---------- | ------------------------------------------------------------------- |
| invitation | [DbyGmsInvitation](#) 实例                          |
| completion | [DbyGmsInvitationAcceptBlock]()，错误码 [DbyGmsInvitationApiCallErrorCode](./DbyGmsEnum.md/#) |

### refuseInvitation
| 参数       | 描述                                                                |
| ---------- | ------------------------------------------------------------------- |
| invitation | [DbyGmsInvitation](#) 实例                          |
| completion | [DbyGmsInvitationRefuseBlock]()，错误码 [DbyGmsInvitationApiCallErrorCode](./DbyGmsEnum.md/#) |

## DbyGmsInvitationDelegate

### invitationFailed
```objectivec
- (void)gmsInvitationKit:(DbyGmsInvitationKit *_Nonnull)invitationKit invitationFailed:(DbyGmsInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [DbyGmsInvitationKit](#) 实例 |
| invitation    | [DbyGmsInvitation](./DbyGmsModel.md/#dbygmsinvitation) 实例 |

### invitationArrived
```objectivec
- (void)gmsInvitationKit:(DbyGmsInvitationKit *_Nonnull)invitationKit invitationArrived:(DbyGmsInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [DbyGmsInvitationKit](#) 实例 |
| invitation    | [DbyGmsInvitation](./DbyGmsModel.md/#dbygmsinvitation) 实例    |

### invitationCanceled
```objectivec
- (void)gmsInvitationKit:(DbyGmsInvitationKit *_Nonnull)invitationKit invitationCanceled:(DbyGmsInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [DbyGmsInvitationKit](#) 实例 |
| invitation    | [DbyGmsInvitation](./DbyGmsModel.md/#dbygmsinvitation) 实例    |

### invitationAccept
```objectivec
- (void)gmsInvitationKit:(DbyGmsInvitationKit *_Nonnull)invitationKit invitationAccept:(DbyGmsInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [DbyGmsInvitationKit](#) 实例 |
| invitation    | [DbyGmsInvitation](./DbyGmsModel.md/#dbygmsinvitation) 实例    |

### invitationRefused
```objectivec
- (void)gmsInvitationKit:(DbyGmsInvitationKit *_Nonnull)invitationKit invitationRefused:(DbyGmsInvitation *_Nonnull)invitation;
```
| 参数          | 描述                                            |
| ------------- | ----------------------------------------------- |
| invitationKit | [DbyGmsInvitationKit](#)实例 |
| invitation    | [DbyGmsInvitation](./DbyGmsModel.md/#dbygmsinvitation) 实例 |

## Block
### DbyGmsInvitationSendBlock
```objectivec
typedef void (^DbyGmsInvitationSendBlock)(DbyGmsInvitationApiCallErrorCode errorCode);
```
### DbyGmsInvitationAcceptBlock
```objectivec
typedef void (^DbyGmsInvitationAcceptBlock)(DbyGmsInvitationApiCallErrorCode errorCode);
```
### DbyGmsInvitationRefuseBlock
```objectivec
typedef void (^DbyGmsInvitationRefuseBlock)(DbyGmsInvitationApiCallErrorCode errorCode);
```
### DbyGmsInvitationCancelBlock
```objectivec
typedef void (^DbyGmsInvitationCancelBlock)(DbyGmsInvitationApiCallErrorCode errorCode);
```
