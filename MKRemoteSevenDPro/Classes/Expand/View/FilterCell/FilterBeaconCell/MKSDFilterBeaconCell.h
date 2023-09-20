//
//  MKSDFilterBeaconCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19..
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDFilterBeaconCellModel : NSObject

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, copy)NSString *minValue;

@property (nonatomic, copy)NSString *maxValue;

@end

@protocol MKSDFilterBeaconCellDelegate <NSObject>

- (void)mk_sd_beaconMinValueChanged:(NSString *)value index:(NSInteger)index;

- (void)mk_sd_beaconMaxValueChanged:(NSString *)value index:(NSInteger)index;

@end

@interface MKSDFilterBeaconCell : MKBaseCell

@property (nonatomic, strong)MKSDFilterBeaconCellModel *dataModel;

@property (nonatomic, weak)id <MKSDFilterBeaconCellDelegate>delegate;

+ (MKSDFilterBeaconCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
