//
//  MKSDFilterByTagModel.m
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import "MKSDFilterByTagModel.h"

#import "MKMacroDefines.h"

#import "MKSDDeviceModeManager.h"

#import "MKSDMQTTInterface.h"

@interface MKSDFilterByTagModel ()

@property (nonatomic, strong)dispatch_queue_t readQueue;

@property (nonatomic, strong)dispatch_semaphore_t semaphore;

@end

@implementation MKSDFilterByTagModel

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock {
    dispatch_async(self.readQueue, ^{
        if (![self readFilterByTag]) {
            [self operationFailedBlockWithMsg:@"Read Filter Tag Error" block:failedBlock];
            return;
        }
        moko_dispatch_main_safe(^{
            if (sucBlock) {
                sucBlock();
            }
        });
    });
}

- (void)configDataWithTagIDList:(NSArray <NSString *>*)tagIDList
                       sucBlock:(void (^)(void))sucBlock
                    failedBlock:(void (^)(NSError *error))failedBlock {
    dispatch_async(self.readQueue, ^{
        if (![self configFilterByTag:tagIDList]) {
            [self operationFailedBlockWithMsg:@"Setup failed!" block:failedBlock];
            return;
        }
        moko_dispatch_main_safe(^{
            if (sucBlock) {
                sucBlock();
            }
        });
    });
}

#pragma mark - interface
- (BOOL)readFilterByTag {
    __block BOOL success = NO;
    [MKSDMQTTInterface sd_readFilterBXPTagWithMacAddress:[MKSDDeviceModeManager shared].macAddress topic:[MKSDDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        success = YES;
        self.isOn = ([returnData[@"data"][@"switch_value"] integerValue] == 1);
        self.precise = ([returnData[@"data"][@"precise"] integerValue] == 1);
        self.reverse = ([returnData[@"data"][@"reverse"] integerValue] == 1);
        if (ValidArray(returnData[@"data"][@"tagid"])) {
            self.tagIDList = returnData[@"data"][@"tagid"];
        }
        dispatch_semaphore_signal(self.semaphore);
    } failedBlock:^(NSError * _Nonnull error) {
        dispatch_semaphore_signal(self.semaphore);
    }];
    dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
    return success;
}

- (BOOL)configFilterByTag:(NSArray <NSString *>*)tagList {
    __block BOOL success = NO;
    [MKSDMQTTInterface sd_configFilterByTag:self.isOn preciseMatch:self.precise reverseFilter:self.reverse tagIDList:tagList macAddress:[MKSDDeviceModeManager shared].macAddress topic:[MKSDDeviceModeManager shared].subscribedTopic sucBlock:^(id  _Nonnull returnData) {
        success = YES;
        dispatch_semaphore_signal(self.semaphore);
    } failedBlock:^(NSError * _Nonnull error) {
        dispatch_semaphore_signal(self.semaphore);
    }];
    dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
    return success;
}

#pragma mark - private method
- (void)operationFailedBlockWithMsg:(NSString *)msg block:(void (^)(NSError *error))block {
    moko_dispatch_main_safe(^{
        NSError *error = [[NSError alloc] initWithDomain:@"filterTagParams"
                                                    code:-999
                                                userInfo:@{@"errorInfo":msg}];
        block(error);
    })
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
        _readQueue = dispatch_queue_create("filterTagQueue", DISPATCH_QUEUE_SERIAL);
    }
    return _readQueue;
}

@end
