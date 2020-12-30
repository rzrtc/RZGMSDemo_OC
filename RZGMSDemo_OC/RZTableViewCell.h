//
//  RZTableViewCell.h
//  RZGMSDemo_OC
//
//  Created by 钟凡 on 2020/8/1.
//  Copyright © 2020 认真通信. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface RZTableViewCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UILabel *nameLabel;
@property (weak, nonatomic) IBOutlet UILabel *valueLabel;


@end

NS_ASSUME_NONNULL_END
