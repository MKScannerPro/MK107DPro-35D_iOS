//
//  MKSDFilterEditSectionHeaderView.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDFilterEditSectionHeaderViewModel : NSObject

/// sectionHeader所在index
@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *msg;

@property (nonatomic, strong)UIColor *contentColor;

@end

@protocol MKSDFilterEditSectionHeaderViewDelegate <NSObject>

/// 加号点击事件
/// @param index 所在index
- (void)mk_sd_filterEditSectionHeaderView_addButtonPressed:(NSInteger)index;

/// 减号点击事件
/// @param index 所在index
- (void)mk_sd_filterEditSectionHeaderView_subButtonPressed:(NSInteger)index;

@end

@interface MKSDFilterEditSectionHeaderView : UITableViewHeaderFooterView

@property (nonatomic, strong)MKSDFilterEditSectionHeaderViewModel *dataModel;

@property (nonatomic, weak)id <MKSDFilterEditSectionHeaderViewDelegate>delegate;

+ (MKSDFilterEditSectionHeaderView *)initHeaderViewWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
