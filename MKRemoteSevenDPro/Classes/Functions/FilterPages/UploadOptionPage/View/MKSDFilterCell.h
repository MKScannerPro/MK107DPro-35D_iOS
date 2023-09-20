//
//  MKSDFilterCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDFilterCellModel : NSObject

/// cell标识符
@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, assign)NSInteger dataListIndex;

@property (nonatomic, strong)NSArray <NSString *>*dataList;

@end

@protocol MKSDFilterCellDelegate <NSObject>

- (void)sd_filterValueChanged:(NSInteger)dataListIndex index:(NSInteger)index;

@end

@interface MKSDFilterCell : MKBaseCell

@property (nonatomic, strong)MKSDFilterCellModel *dataModel;

@property (nonatomic, weak)id <MKSDFilterCellDelegate>delegate;

+ (MKSDFilterCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
