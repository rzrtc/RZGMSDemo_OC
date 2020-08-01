//
//  DbyGmsMessage.h
//  DBY-Gms
//
//  Created by 钟凡 on 2020/7/15.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    DbyGmsMessageTypeUndefined = 0,
    DbyGmsMessageTypeText = 1,
    DbyGmsMessageTypeRaw = 2,
} DbyGmsMessageType;

NS_ASSUME_NONNULL_BEGIN

@interface DbyGmsMessage : NSObject

@property (nonatomic, assign, readonly) DbyGmsMessageType type;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, assign) long long serverReceivedTs;
@property (nonatomic, assign, readonly) BOOL isOfflineMessage;

- (instancetype _Nonnull)initWithText:(NSString *_Nonnull)text;

@end


@interface DbyGmsRawMessage : DbyGmsMessage

@property (nonatomic, nonnull) NSData *rawData;

- (instancetype _Nonnull)initWithRawData:(NSData *_Nonnull)data;

@end

NS_ASSUME_NONNULL_END
