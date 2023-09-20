//
//  MKSDDeviceInfoModel.m
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/1/31.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import "MKSDDeviceInfoModel.h"

#import "MKMacroDefines.h"

#import "MKSDDeviceModeManager.h"

#import "MKSDMQTTInterface.h"

@interface MKSDDeviceInfoModel ()

@property (nonatomic, strong)dispatch_queue_t readQueue;

@property (nonatomic, strong)dispatch_semaphore_t semaphore;

@end

@implementation MKSDDeviceInfoModel

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock {
    dispatch_async(self.readQueue, ^{
        if (![self readDeviceInfo]) {
            [self operationFailedBlockWithMsg:@"Read Data Error" block:failedBlock];
            return;
        }
        moko_dispatch_main_safe(^{
            sucBlock();
        });
    });
}

#pragma mark - interface
- (BOOL)readDeviceInfo {
    __block BOOL success = NO;
    [MKSDMQTTInterface sd_readDeviceInfoWithMacAddress:[MKSDDeviceModeManager shared].macAddress topic:[MKSDDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        success = YES;
        self.deviceName = returnData[@"data"][@"device_name"];
        self.productMode = returnData[@"data"][@"product_model"];
        self.manu = returnData[@"data"][@"company_name"];
        self.hardware = returnData[@"data"][@"hardware_version"];
        self.software = returnData[@"data"][@"software_version"];
        
        self.firmware = returnData[@"data"][@"firmware_version"];
        self.btMac = returnData[@"data"][@"ble_mac"];
        self.bleVersion = returnData[@"data"][@"sl_ble_version"];
        self.wifiStaMac = [MKSDDeviceModeManager shared].macAddress;
        dispatch_semaphore_signal(self.semaphore);
    } failedBlock:^(NSError * _Nonnull error) {
        dispatch_semaphore_signal(self.semaphore);
    }];
    dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
    return success;
}

- (void)operationFailedBlockWithMsg:(NSString *)msg block:(void (^)(NSError *error))block {
    moko_dispatch_main_safe(^{
        NSError *error = [[NSError alloc] initWithDomain:@"deviceInformation"
                                                    code:-999
                                                userInfo:@{@"errorInfo":msg}];
        block(error);
    });
}

#pragma mark - getter
- (dispatch_semaphore_t)semaphore {
    if (!_semaphore) {
        _semaphore = dispatch_semaphore_create(0);
    }
    return _semaphore;
}

- (dispatch_queue_t)readQueue {
    if (!_readQueue) {
        _readQueue = dispatch_queue_create("deviceInfoParamsQueue", DISPATCH_QUEUE_SERIAL);
    }
    return _readQueue;
}

@end
