//
//  DbyLog.h
//  DbyGms
//
//  Created by 钟凡 on 2020/7/30.
//

#import <Foundation/Foundation.h>
#import "DbyEnumerates.h"

NS_ASSUME_NONNULL_BEGIN

@interface DbyLog : NSObject

@property (nonatomic, assign) DbyGmsLogFilter logFilter;
@property (nonatomic, copy) NSString *logFilePath;

+ (instancetype)shared;

- (void)error:(NSString *)format, ...;
- (void)critical:(NSString *)format, ...;
- (void)warn:(NSString *)format, ...;
- (void)info:(NSString *)format, ...;

@end

NS_ASSUME_NONNULL_END
