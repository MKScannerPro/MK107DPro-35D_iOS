//
//  MKSDFilterNormalTextFieldCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19..
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

#import <MKCustomUIModule/MKTextField.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDFilterNormalTextFieldCellModel : NSObject

@property (nonatomic, assign)NSInteger index;

/// 左侧msg
@property (nonatomic, copy)NSString *msg;

/// 当前textField的值
@property (nonatomic, copy)NSString *textFieldValue;

/// textField的占位符
@property (nonatomic, copy)NSString *textPlaceholder;

/// 当前textField的输入类型
@property (nonatomic, assign)mk_textFieldType textFieldType;

/// textField的最大输入长度,对于textFieldType == mk_uuidMode无效
@property (nonatomic, assign)NSInteger maxLength;

@end

@protocol MKSDFilterNormalTextFieldCellDelegate <NSObject>

- (void)mk_sd_filterNormalTextFieldValueChanged:(NSString *)text index:(NSInteger)index;

@end

@interface MKSDFilterNormalTextFieldCell : MKBaseCell

@property (nonatomic, strong)MKSDFilterNormalTextFieldCellModel *dataModel;

@property (nonatomic, weak)id <MKSDFilterNormalTextFieldCellDelegate>delegate;

+ (MKSDFilterNormalTextFieldCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
