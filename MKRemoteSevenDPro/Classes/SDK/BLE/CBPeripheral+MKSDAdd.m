//
//  CBPeripheral+MKSDAdd.m
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import "CBPeripheral+MKSDAdd.h"

#import <objc/runtime.h>

static const char *sd_manufacturerKey = "sd_manufacturerKey";
static const char *sd_deviceModelKey = "sd_deviceModelKey";
static const char *sd_hardwareKey = "sd_hardwareKey";
static const char *sd_softwareKey = "sd_softwareKey";
static const char *sd_firmwareKey = "sd_firmwareKey";

static const char *sd_passwordKey = "sd_passwordKey";
static const char *sd_disconnectTypeKey = "sd_disconnectTypeKey";
static const char *sd_customKey = "sd_customKey";

static const char *sd_passwordNotifySuccessKey = "sd_passwordNotifySuccessKey";
static const char *sd_disconnectTypeNotifySuccessKey = "sd_disconnectTypeNotifySuccessKey";
static const char *sd_customNotifySuccessKey = "sd_customNotifySuccessKey";

@implementation CBPeripheral (MKSDAdd)

- (void)sd_updateCharacterWithService:(CBService *)service {
    NSArray *characteristicList = service.characteristics;
    if ([service.UUID isEqual:[CBUUID UUIDWithString:@"180A"]]) {
        //设备信息
        for (CBCharacteristic *characteristic in characteristicList) {
            if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"2A24"]]) {
                objc_setAssociatedObject(self, &sd_deviceModelKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"2A26"]]) {
                objc_setAssociatedObject(self, &sd_firmwareKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"2A27"]]) {
                objc_setAssociatedObject(self, &sd_hardwareKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"2A28"]]) {
                objc_setAssociatedObject(self, &sd_softwareKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"2A29"]]) {
                objc_setAssociatedObject(self, &sd_manufacturerKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }
        }
        return;
    }
    if ([service.UUID isEqual:[CBUUID UUIDWithString:@"AA00"]]) {
        //自定义
        for (CBCharacteristic *characteristic in characteristicList) {
            if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA00"]]) {
                objc_setAssociatedObject(self, &sd_passwordKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA01"]]) {
                objc_setAssociatedObject(self, &sd_disconnectTypeKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }else if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA03"]]) {
                objc_setAssociatedObject(self, &sd_customKey, characteristic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            }
            [self setNotifyValue:YES forCharacteristic:characteristic];
        }
        return;
    }
}

- (void)sd_updateCurrentNotifySuccess:(CBCharacteristic *)characteristic {
    if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA00"]]) {
        objc_setAssociatedObject(self, &sd_passwordNotifySuccessKey, @(YES), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        return;
    }
    if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA01"]]) {
        objc_setAssociatedObject(self, &sd_disconnectTypeNotifySuccessKey, @(YES), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        return;
    }
    if ([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"AA03"]]) {
        objc_setAssociatedObject(self, &sd_customNotifySuccessKey, @(YES), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        return;
    }
}

- (BOOL)sd_connectSuccess {
    if (![objc_getAssociatedObject(self, &sd_customNotifySuccessKey) boolValue] || ![objc_getAssociatedObject(self, &sd_passwordNotifySuccessKey) boolValue] || ![objc_getAssociatedObject(self, &sd_disconnectTypeNotifySuccessKey) boolValue]) {
        return NO;
    }
    if (!self.sd_hardware || !self.sd_firmware) {
        return NO;
    }
    if (!self.sd_password || !self.sd_disconnectType || !self.sd_custom) {
        return NO;
    }
    return YES;
}

- (void)sd_setNil {
    objc_setAssociatedObject(self, &sd_manufacturerKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &sd_deviceModelKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &sd_hardwareKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &sd_softwareKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &sd_firmwareKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    objc_setAssociatedObject(self, &sd_passwordKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &sd_disconnectTypeKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &sd_customKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    objc_setAssociatedObject(self, &sd_passwordNotifySuccessKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &sd_disconnectTypeNotifySuccessKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, &sd_customNotifySuccessKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

#pragma mark - getter

- (CBCharacteristic *)sd_manufacturer {
    return objc_getAssociatedObject(self, &sd_manufacturerKey);
}

- (CBCharacteristic *)sd_deviceModel {
    return objc_getAssociatedObject(self, &sd_deviceModelKey);
}

- (CBCharacteristic *)sd_hardware {
    return objc_getAssociatedObject(self, &sd_hardwareKey);
}

- (CBCharacteristic *)sd_software {
    return objc_getAssociatedObject(self, &sd_softwareKey);
}

- (CBCharacteristic *)sd_firmware {
    return objc_getAssociatedObject(self, &sd_firmwareKey);
}

- (CBCharacteristic *)sd_password {
    return objc_getAssociatedObject(self, &sd_passwordKey);
}

- (CBCharacteristic *)sd_disconnectType {
    return objc_getAssociatedObject(self, &sd_disconnectTypeKey);
}

- (CBCharacteristic *)sd_custom {
    return objc_getAssociatedObject(self, &sd_customKey);
}

@end
