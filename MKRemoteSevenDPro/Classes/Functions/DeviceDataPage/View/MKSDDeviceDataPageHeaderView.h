//
//  MKSDDeviceDataPageHeaderView.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDDeviceDataPageHeaderViewModel : NSObject

@property (nonatomic, assign)BOOL isOn;

@end

@protocol MKSDDeviceDataPageHeaderViewDelegate <NSObject>

- (void)sd_updateLoadButtonAction;

- (void)sd_scannerStatusChanged:(BOOL)isOn;

- (void)sd_manageBleDeviceAction;

@end

@interface MKSDDeviceDataPageHeaderView : UIView

@property (nonatomic, strong)MKSDDeviceDataPageHeaderViewModel *dataModel;

@property (nonatomic, weak)id <MKSDDeviceDataPageHeaderViewDelegate>delegate;

- (void)updateTotalNumbers:(NSInteger)numbers;

@end

NS_ASSUME_NONNULL_END
