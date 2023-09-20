//
//  MKSDBleWifiSettingsBandCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDBleWifiSettingsBandCellModel : NSObject

@property (nonatomic, assign)NSInteger country;

@end

@protocol MKSDBleWifiSettingsBandCellDelegate <NSObject>

- (void)sd_bleWifiSettingsBandCell_countryChanged:(NSInteger)country;

@end

@interface MKSDBleWifiSettingsBandCell : MKBaseCell

@property (nonatomic, strong)MKSDBleWifiSettingsBandCellModel *dataModel;

@property (nonatomic, weak)id <MKSDBleWifiSettingsBandCellDelegate>delegate;

+ (MKSDBleWifiSettingsBandCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
