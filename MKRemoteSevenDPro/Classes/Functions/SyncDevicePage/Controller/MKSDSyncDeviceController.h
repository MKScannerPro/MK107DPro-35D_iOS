//
//  MKSDSyncDeviceController.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2025/3/7.
//  Copyright © 2025 aadyx2007@163.com. All rights reserved.
//

#import <MKBaseModuleLibrary/MKBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class MKSDDeviceModel;
@interface MKSDSyncDeviceController : MKBaseViewController

@property (nonatomic, strong)NSArray <MKSDDeviceModel *>*deviceList;

@property (nonatomic, copy)NSString *token;

@end

NS_ASSUME_NONNULL_END
