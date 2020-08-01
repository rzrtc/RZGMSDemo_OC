//
//  DbyGmsResult.h
//  DBY-GMS
//
//  Created by 钟凡 on 2020/6/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DbyGmsResult : NSObject

@property (nonatomic, copy, nullable) NSString *errorString;
@property (nonatomic, assign) int code;
@property (nonatomic, copy) NSDictionary *response;

+ (DbyGmsResult *)resultWithArray:(NSArray *)array;

@end

NS_ASSUME_NONNULL_END
