//
//  MKSDDeviceListCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MKSDDeviceListCellDelegate <NSObject>

/**
 删除
 
 @param index 所在index
 */
- (void)sd_cellDeleteButtonPressed:(NSInteger)index;

@end

@class MKSDDeviceListModel;
@interface MKSDDeviceListCell : MKBaseCell

@property (nonatomic, weak)id <MKSDDeviceListCellDelegate>delegate;

@property (nonatomic, strong)MKSDDeviceListModel *dataModel;

+ (MKSDDeviceListCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
