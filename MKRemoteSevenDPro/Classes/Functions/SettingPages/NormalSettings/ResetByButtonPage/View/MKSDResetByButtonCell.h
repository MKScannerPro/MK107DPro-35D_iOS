//
//  MKSDResetByButtonCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDResetByButtonCellModel : NSObject

@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, assign)BOOL selected;

@end

@protocol MKSDResetByButtonCellDelegate <NSObject>

- (void)sd_resetByButtonCellAction:(NSInteger)index;

@end

@interface MKSDResetByButtonCell : MKBaseCell

@property (nonatomic, weak)id <MKSDResetByButtonCellDelegate>delegate;

@property (nonatomic, strong)MKSDResetByButtonCellModel *dataModel;

+ (MKSDResetByButtonCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
