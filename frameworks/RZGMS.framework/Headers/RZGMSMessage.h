//
//  RZGMSMessage.h
//  RZ-GMS
//
//  Created by 钟凡 on 2020/7/15.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    RZGMSMessageTypeUndefined = 0,
    RZGMSMessageTypeText = 1,
    RZGMSMessageTypeRaw = 2,
} RZGMSMessageType;

NS_ASSUME_NONNULL_BEGIN

@interface RZGMSMessage : NSObject

@property (nonatomic, assign, readonly) RZGMSMessageType type;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, assign) long long serverReceivedTs;
@property (nonatomic, assign, readonly) BOOL isOfflineMessage;

- (instancetype _Nonnull)initWithText:(NSString *_Nonnull)text;

@end


@interface RZGMSRawMessage : RZGMSMessage

@property (nonatomic, nonnull) NSData *rawData;

- (instancetype _Nonnull)initWithRawData:(NSData *_Nonnull)data;

@end

NS_ASSUME_NONNULL_END
