//
//  MKSDDeviceDataPageCell.m
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import "MKSDDeviceDataPageCell.h"

#import "Masonry.h"

#import "MKMacroDefines.h"
#import "NSString+MKAdd.h"

@implementation MKSDDeviceDataPageCellModel

- (CGFloat)fetchCellHeight {
    CGSize size = [NSString sizeWithText:self.msg
                                 andFont:MKFont(13.f)
                              andMaxSize:CGSizeMake(kViewWidth - 2 * 15.f, MAXFLOAT)];
    return MAX(44.f, size.height + 20.f);
}

@end

@interface MKSDDeviceDataPageCell ()

@property (nonatomic, strong)UILabel *msgLabel;

@end

@implementation MKSDDeviceDataPageCell

+ (MKSDDeviceDataPageCell *)initCellWithTableView:(UITableView *)tableView {
    MKSDDeviceDataPageCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MKSDDeviceDataPageCellIdenty"];
    if (!cell) {
        cell = [[MKSDDeviceDataPageCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MKSDDeviceDataPageCellIdenty"];
    }
    return cell;
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        [self.contentView addSubview:self.msgLabel];
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
    CGSize size = [NSString sizeWithText:self.msgLabel.text
                                 andFont:self.msgLabel.font
                              andMaxSize:CGSizeMake(kViewWidth - 2 * 15.f, MAXFLOAT)];
    [self.msgLabel mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(15.f);
        make.right.mas_equalTo(-15.f);
        make.centerY.mas_equalTo(self.contentView.mas_centerY);
        make.height.mas_equalTo(size.height);
    }];
}

#pragma mark - setter
- (void)setDataModel:(MKSDDeviceDataPageCellModel *)dataModel {
    _dataModel = nil;
    _dataModel = dataModel;
    if (!_dataModel || ![_dataModel isKindOfClass:MKSDDeviceDataPageCellModel.class]) {
        return;
    }
    self.msgLabel.text = SafeStr(_dataModel.msg);
    [self setNeedsLayout];
}

#pragma mark - getter
- (UILabel *)msgLabel {
    if (!_msgLabel) {
        _msgLabel = [[UILabel alloc] init];
        _msgLabel.textColor = DEFAULT_TEXT_COLOR;
        _msgLabel.textAlignment = NSTextAlignmentLeft;
        _msgLabel.font = MKFont(13.f);
        _msgLabel.numberOfLines = 0;
    }
    return _msgLabel;
}

@end
