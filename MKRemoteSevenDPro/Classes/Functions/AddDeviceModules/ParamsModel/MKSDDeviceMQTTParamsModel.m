//
//  MKSDDeviceMQTTParamsModel.m
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import "MKSDDeviceMQTTParamsModel.h"

#import "MKSDDeviceModel.h"

static MKSDDeviceMQTTParamsModel *paramsModel = nil;
static dispatch_once_t onceToken;

@implementation MKSDDeviceMQTTParamsModel

+ (MKSDDeviceMQTTParamsModel *)shared {
    dispatch_once(&onceToken, ^{
        if (!paramsModel) {
            paramsModel = [MKSDDeviceMQTTParamsModel new];
        }
    });
    return paramsModel;
}

+ (void)sharedDealloc {
    paramsModel = nil;
    onceToken = 0;
}

#pragma mark - getter
- (MKSDDeviceModel *)deviceModel {
    if (!_deviceModel) {
        _deviceModel = [[MKSDDeviceModel alloc] init];
    }
    return _deviceModel;
}

@end
