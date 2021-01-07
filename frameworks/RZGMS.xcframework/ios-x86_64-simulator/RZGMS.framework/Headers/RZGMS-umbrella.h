#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "RZGMSChannel.h"
#import "RZGMSInvitationKit.h"
#import "RZGMSKit.h"
#import "RZChannelMemberCount.h"
#import "RZEnumerates.h"
#import "RZGMSAttribute.h"
#import "RZGMSChannelAttributeOptions.h"
#import "RZGMSMember.h"
#import "RZGMSMessage.h"
#import "RZGMSPeerOnlineStatus.h"
#import "RZGMSResult.h"
#import "RZGMSSendMessageOptions.h"

FOUNDATION_EXPORT double RZGMSVersionNumber;
FOUNDATION_EXPORT const unsigned char RZGMSVersionString[];

