//
//  MKSDBleWifiSettingsCertCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/1/30.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDBleWifiSettingsCertCellModel : NSObject

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *fileName;

@end

@protocol MKSDBleWifiSettingsCertCellDelegate <NSObject>

- (void)sd_bleWifiSettingsCertPressed:(NSInteger)index;

@end

@interface MKSDBleWifiSettingsCertCell : MKBaseCell

@property (nonatomic, strong)MKSDBleWifiSettingsCertCellModel *dataModel;

@property (nonatomic, weak)id <MKSDBleWifiSettingsCertCellDelegate>delegate;

+ (MKSDBleWifiSettingsCertCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
