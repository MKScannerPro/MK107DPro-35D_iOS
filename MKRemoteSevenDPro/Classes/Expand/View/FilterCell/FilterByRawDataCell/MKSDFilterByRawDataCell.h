//
//  MKSDFilterByRawDataCell.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDFilterByRawDataCellModel : NSObject

/// 当前cell所在index
@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)NSString *msg;

/// 背景颜色，默认白色
@property (nonatomic, strong)UIColor *contentColor;

/// 当前过滤的数据类型，参考国际蓝牙组织对不同蓝牙数据类型的定义，1Byte
@property (nonatomic, copy)NSString *dataType;

/// 开始过滤的Byte索引
@property (nonatomic, copy)NSString *minIndex;

/// 截止过滤的Byte索引
@property (nonatomic, copy)NSString *maxIndex;

/// 当前过滤的内容
@property (nonatomic, copy)NSString *rawData;

/// 当前过滤内容(rawData是字符，长度乘以2就是当前输入的字节数)最大字节长度,默认29个字节长度
@property (nonatomic, assign)NSInteger rawDataMaxBytes;

@property (nonatomic, copy)NSString *dataTypePlaceHolder;

@property (nonatomic, copy)NSString *minTextFieldPlaceHolder;

@property (nonatomic, copy)NSString *maxTextFieldPlaceHolder;

@property (nonatomic, copy)NSString *rawTextFieldPlaceHolder;

/// 校验当前的参数是否符合业务需求
- (BOOL)validParamsSuccess;

@end

typedef NS_ENUM(NSInteger, mk_sd_filterRawAdvDataTextType) {
    mk_sd_filterRawAdvDataTextTypeDataType,            //过滤类型输入框内容发生改变
    mk_sd_filterRawAdvDataTextTypeMinIndex,            //开始过滤的Byte索引输入框发生改变
    mk_sd_filterRawAdvDataTextTypeMaxIndex,            //截止过滤的Byte索引输入框发生改变
    mk_sd_filterRawAdvDataTextTypeRawDataType,         //过滤内容输入框发生改变
};

@protocol MKSDFilterByRawDataCellDelegate <NSObject>

/// 输入框内容发生改变
/// @param textType 哪个输入框发生改变了
/// @param index 当前cell所在的row
/// @param textValue 当前textField内容
- (void)sd_rawFilterDataChanged:(mk_sd_filterRawAdvDataTextType)textType
                          index:(NSInteger)index
                      textValue:(NSString *)textValue;

@end

@interface MKSDFilterByRawDataCell : MKBaseCell

@property (nonatomic, strong)MKSDFilterByRawDataCellModel *dataModel;

@property (nonatomic, weak)id <MKSDFilterByRawDataCellDelegate>delegate;

+ (MKSDFilterByRawDataCell *)initCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
