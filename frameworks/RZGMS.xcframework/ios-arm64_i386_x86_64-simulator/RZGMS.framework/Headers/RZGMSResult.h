//
//  RZGMSResult.h
//  RZ-GMS
//
//  Created by 钟凡 on 2020/6/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RZGMSResult : NSObject

@property (nonatomic, copy, nullable) NSString *errorString;
@property (nonatomic, assign) int code;
@property (nonatomic, copy) NSDictionary *response;
//请求失败，ack 过期仍未收到
@property (nonatomic, assign, readonly, getter=isAckTimeout) BOOL ackTimeout;
+ (RZGMSResult *)resultWithArray:(NSArray *)array;

@end

NS_ASSUME_NONNULL_END
