//
//  MKSDSystemTimeCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDSystemTimeCellModel : NSObject

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, copy)NSString *buttonTitle;

@end

@protocol MKSDSystemTimeCellDelegate <NSObject>

- (void)sd_systemTimeButtonPressed:(NSInteger)index;

@end

@interface MKSDSystemTimeCell : MKBaseCell

@property (nonatomic, strong)MKSDSystemTimeCellModel *dataModel;

@property (nonatomic, weak)id <MKSDSystemTimeCellDelegate>delegate;

+ (MKSDSystemTimeCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
