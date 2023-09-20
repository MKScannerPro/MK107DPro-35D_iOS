//
//  MKSDWifiSettingsBandCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.1.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDWifiSettingsBandCellModel : NSObject

@property (nonatomic, assign)NSInteger country;

@end

@protocol MKSDWifiSettingsBandCellDelegate <NSObject>

- (void)sd_wifiSettingsBandCell_countryChanged:(NSInteger)country;

@end

@interface MKSDWifiSettingsBandCell : MKBaseCell

@property (nonatomic, strong)MKSDWifiSettingsBandCellModel *dataModel;

@property (nonatomic, weak)id <MKSDWifiSettingsBandCellDelegate>delegate;

+ (MKSDWifiSettingsBandCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
