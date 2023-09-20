//
//  MKSDScanPageCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@class MKSDScanPageModel;
@interface MKSDScanPageCell : MKBaseCell

@property (nonatomic, strong)MKSDScanPageModel *dataModel;

+ (MKSDScanPageCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
