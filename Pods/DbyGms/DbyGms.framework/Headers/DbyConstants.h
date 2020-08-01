//
//  DBYConstants.h
//  DBY-GMS
//
//  Created by 钟凡 on 2020/7/15.
//

#ifndef DBYConstants_h
#define DBYConstants_h

#import <Foundation/Foundation.h>

#define kDbyGmsBaseAddress @"http://tinderdev-sio-bj.duobeiyun.com:20080"
#define kCommand @"command"

#define kTimeoutSeconds 10

#define kTooManyRequests @"Too Many Requests"
#define kLoginFailInvalidAppId @"loginFail: InvalidAppId"
#define kLoginFailInvalidArgument @"loginFail: InvalidArgument"
#define kLoginFailInvalidToken @"loginFail: InvalidToken"
#define kLoginFailExpiredToken @"loginFail: ExpiredToken"
#define kLoginFailAuthFail @"loginFail: AuthFail"
#define kKickOff @"KickOff"
#define kServerDisconect @"Got Disconnect"
#define kClientDisconect @"Namespace leave"


#define userId_regex @"^[a-zA-Z0-9!#$%&()+\\-:;<=.>?@[\\\\]^_{}|~,\\s]{1,64}$"
#define channelId_regex @"^[a-zA-Z0-9!#$%&()+\\-:;<=.>?@[\\\\]^_{}|~,\\s]{1,64}$"
#define appId_regex @"\\S"
#define token_regex @"\\S{32,32}"

#endif /* DBYConstants_h */
