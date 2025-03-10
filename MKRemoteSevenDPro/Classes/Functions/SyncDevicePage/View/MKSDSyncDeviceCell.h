//
//  MKSDSyncDeviceCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2025/3/7.
//  Copyright © 2025 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

#import "MKSDDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKSDSyncDeviceCellModel : MKSDDeviceModel

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, assign)BOOL selected;

@end

@protocol MKSDSyncDeviceCellDelegate <NSObject>

- (void)sd_syncDeviceCell_selected:(BOOL)selected index:(NSInteger)index;

@end

@interface MKSDSyncDeviceCell : MKBaseCell

@property (nonatomic, strong)MKSDSyncDeviceCellModel *dataModel;

@property (nonatomic, weak)id <MKSDSyncDeviceCellDelegate>delegate;

+ (MKSDSyncDeviceCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
