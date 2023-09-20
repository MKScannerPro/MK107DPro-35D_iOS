//
//  MKSDButtonFirmwareCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDButtonFirmwareCellModel : NSObject

/// cell唯一识别号
@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *leftMsg;

@property (nonatomic, copy)NSString *rightMsg;

@property (nonatomic, copy)NSString *rightButtonTitle;

@end

@protocol MKSDButtonFirmwareCellDelegate <NSObject>

- (void)sd_buttonFirmwareCell_buttonAction:(NSInteger)index;

@end

@interface MKSDButtonFirmwareCell : MKBaseCell

@property (nonatomic, strong)MKSDButtonFirmwareCellModel *dataModel;

@property (nonatomic, weak)id <MKSDButtonFirmwareCellDelegate>delegate;

+ (MKSDButtonFirmwareCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
