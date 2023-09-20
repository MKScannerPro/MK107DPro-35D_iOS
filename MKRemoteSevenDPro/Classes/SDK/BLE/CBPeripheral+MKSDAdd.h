//
//  CBPeripheral+MKSDAdd.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface CBPeripheral (MKSDAdd)

/// R
@property (nonatomic, strong, readonly)CBCharacteristic *sd_manufacturer;

/// R
@property (nonatomic, strong, readonly)CBCharacteristic *sd_deviceModel;

/// R
@property (nonatomic, strong, readonly)CBCharacteristic *sd_hardware;

/// R
@property (nonatomic, strong, readonly)CBCharacteristic *sd_software;

/// R
@property (nonatomic, strong, readonly)CBCharacteristic *sd_firmware;

#pragma mark - custom

/// W/N
@property (nonatomic, strong, readonly)CBCharacteristic *sd_password;

/// N
@property (nonatomic, strong, readonly)CBCharacteristic *sd_disconnectType;

/// W/N
@property (nonatomic, strong, readonly)CBCharacteristic *sd_custom;

- (void)sd_updateCharacterWithService:(CBService *)service;

- (void)sd_updateCurrentNotifySuccess:(CBCharacteristic *)characteristic;

- (BOOL)sd_connectSuccess;

- (void)sd_setNil;

@end

NS_ASSUME_NONNULL_END
