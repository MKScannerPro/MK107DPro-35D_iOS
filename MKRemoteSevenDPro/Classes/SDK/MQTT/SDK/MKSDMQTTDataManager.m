//
//  MKSDMQTTDataManager.m
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import "MKSDMQTTDataManager.h"

#import "MKMacroDefines.h"

#import "MKSDMQTTServerManager.h"

#import "MKSDMQTTOperation.h"

NSString *const MKSDMQTTSessionManagerStateChangedNotification = @"MKSDMQTTSessionManagerStateChangedNotification";

NSString *const MKSDReceiveDeviceOnlineNotification = @"MKSDReceiveDeviceOnlineNotification";
NSString *const MKSDReceiveDeviceNetStateNotification = @"MKSDReceiveDeviceNetStateNotification";
NSString *const MKSDReceiveDeviceOTAResultNotification = @"MKSDReceiveDeviceOTAResultNotification";
NSString *const MKSDReceiveDeviceNpcOTAResultNotification = @"MKSDReceiveDeviceNpcOTAResultNotification";
NSString *const MKSDReceiveDeviceResetByButtonNotification = @"MKSDReceiveDeviceResetByButtonNotification";
NSString *const MKSDReceiveDeviceUpdateEapCertsResultNotification = @"MKSDReceiveDeviceUpdateEapCertsResultNotification";
NSString *const MKSDReceiveDeviceUpdateMqttCertsResultNotification = @"MKSDReceiveDeviceUpdateMqttCertsResultNotification";

NSString *const MKSDReceiveDeviceDatasNotification = @"MKSDReceiveDeviceDatasNotification";
NSString *const MKSDReceiveGatewayDisconnectBXPButtonNotification = @"MKSDReceiveGatewayDisconnectBXPButtonNotification";
NSString *const MKSDReceiveGatewayDisconnectDeviceNotification = @"MKSDReceiveGatewayDisconnectDeviceNotification";
NSString *const MKSDReceiveGatewayConnectedDeviceDatasNotification = @"MKSDReceiveGatewayConnectedDeviceDatasNotification";

NSString *const MKSDReceiveBxpButtonDfuProgressNotification = @"MKSDReceiveBxpButtonDfuProgressNotification";
NSString *const MKSDReceiveBxpButtonDfuResultNotification = @"MKSDReceiveBxpButtonDfuResultNotification";

NSString *const MKSDReceiveDeviceOfflineNotification = @"MKSDReceiveDeviceOfflineNotification";

NSString *const MKSDReceivePowerDataNotification = @"MKSDReceivePowerDataNotification";
NSString *const MKSDReceiveEnergyDataNotification = @"MKSDReceiveEnergyDataNotification";

NSString *const MKSDReceiveLoadChangeNotification = @"MKSDReceiveLoadChangeNotification";


static MKSDMQTTDataManager *manager = nil;
static dispatch_once_t onceToken;

@interface MKSDMQTTDataManager ()

@property (nonatomic, strong)NSOperationQueue *operationQueue;

@end

@implementation MKSDMQTTDataManager

- (instancetype)init {
    if (self = [super init]) {
        [[MKSDMQTTServerManager shared] loadDataManager:self];
    }
    return self;
}

+ (MKSDMQTTDataManager *)shared {
    dispatch_once(&onceToken, ^{
        if (!manager) {
            manager = [MKSDMQTTDataManager new];
        }
    });
    return manager;
}

+ (void)singleDealloc {
    [[MKSDMQTTServerManager shared] removeDataManager:manager];
    onceToken = 0;
    manager = nil;
}

#pragma mark - MKSDServerManagerProtocol
- (void)sd_didReceiveMessage:(NSDictionary *)data onTopic:(NSString *)topic {
    if (!ValidDict(data) || !ValidNum(data[@"msg_id"]) || !ValidStr(data[@"device_info"][@"mac"])) {
        return;
    }
    NSInteger msgID = [data[@"msg_id"] integerValue];
    NSString *macAddress = data[@"device_info"][@"mac"];
    //无论是什么消息，都抛出该通知，证明设备在线
    [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveDeviceOnlineNotification
                                                        object:nil
                                                      userInfo:@{@"macAddress":macAddress}];
    if (msgID == 3004) {
        //上报的网络状态
        NSDictionary *resultDic = @{
            @"macAddress":macAddress,
            @"data":data[@"data"]
        };
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveDeviceNetStateNotification
                                                            object:nil
                                                          userInfo:resultDic];
        return;
    }
    if (msgID == 3007) {
        //固件升级结果
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveDeviceOTAResultNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3014) {
        //设备通过按键恢复出厂设置
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveDeviceResetByButtonNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3018) {
        //NCP固件升级结果
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveDeviceNpcOTAResultNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3022) {
        //EAP证书更新结果
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveDeviceUpdateEapCertsResultNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3032) {
        //MQTT证书更新结果
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveDeviceUpdateMqttCertsResultNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3070) {
        //扫描到的数据
        if ([self.dataDelegate respondsToSelector:@selector(mk_sd_receiveDeviceDatas:)]) {
            [self.dataDelegate mk_sd_receiveDeviceDatas:data];
        }
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveDeviceDatasNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3082) {
        //电量数据
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceivePowerDataNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3084) {
        //电能数据
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveEnergyDataNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3086) {
        //负载检测
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveLoadChangeNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3108) {
        //网关与已连接的BXP-Button设备断开了链接，非主动断开
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveGatewayDisconnectBXPButtonNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3203) {
        //BXP-Button升级进度
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveBxpButtonDfuProgressNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3204) {
        //BXP-Button升级结果
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveBxpButtonDfuResultNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3302) {
        //网关与已连接的蓝牙设备断开了链接，非主动断开
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveGatewayDisconnectDeviceNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3311) {
        //网关接收到已连接的蓝牙设备的数据
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveGatewayConnectedDeviceDatasNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    if (msgID == 3999) {
        //遗嘱，设备离线
        [[NSNotificationCenter defaultCenter] postNotificationName:MKSDReceiveDeviceOfflineNotification
                                                            object:nil
                                                          userInfo:data];
        return;
    }
    @synchronized(self.operationQueue) {
        NSArray *operations = [self.operationQueue.operations copy];
        for (NSOperation <MKSDMQTTOperationProtocol>*operation in operations) {
            if (operation.executing) {
                [operation didReceiveMessage:data onTopic:topic];
                break;
            }
        }
    }
}

- (void)sd_didChangeState:(MKSDMQTTSessionManagerState)newState {
    [[NSNotificationCenter defaultCenter] postNotificationName:MKSDMQTTSessionManagerStateChangedNotification object:nil];
}

#pragma mark - public method
- (NSString *)currentSubscribeTopic {
    return [MKSDMQTTServerManager shared].serverParams.subscribeTopic;
}

- (NSString *)currentPublishedTopic {
    return [MKSDMQTTServerManager shared].serverParams.publishTopic;
}

- (id<MKSDServerParamsProtocol>)currentServerParams {
    return [MKSDMQTTServerManager shared].currentServerParams;
}

- (BOOL)saveServerParams:(id <MKSDServerParamsProtocol>)protocol {
    return [[MKSDMQTTServerManager shared] saveServerParams:protocol];
}

- (BOOL)clearLocalData {
    return [[MKSDMQTTServerManager shared] clearLocalData];
}

- (BOOL)connect {
    return [[MKSDMQTTServerManager shared] connect];
}

- (void)disconnect {
    if (self.operationQueue.operations.count > 0) {
        [self.operationQueue cancelAllOperations];
    }
    [[MKSDMQTTServerManager shared] disconnect];
}

- (void)subscriptions:(NSArray <NSString *>*)topicList {
    [[MKSDMQTTServerManager shared] subscriptions:topicList];
}

- (void)unsubscriptions:(NSArray <NSString *>*)topicList {
    [[MKSDMQTTServerManager shared] unsubscriptions:topicList];
}

- (void)clearAllSubscriptions {
    [[MKSDMQTTServerManager shared] clearAllSubscriptions];
}

- (MKSDMQTTSessionManagerState)state {
    return [MKSDMQTTServerManager shared].state;
}

- (void)sendData:(NSDictionary *)data
           topic:(NSString *)topic
      macAddress:(NSString *)macAddress
          taskID:(mk_sd_serverOperationID)taskID
        sucBlock:(void (^)(id returnData))sucBlock
     failedBlock:(void (^)(NSError *error))failedBlock {
    MKSDMQTTOperation *operation = [self generateOperationWithTaskID:taskID
                                                               topic:topic
                                                          macAddress:macAddress
                                                                data:data
                                                            sucBlock:sucBlock
                                                         failedBlock:failedBlock];
    if (!operation) {
        return;
    }
    [self.operationQueue addOperation:operation];
}

- (void)sendData:(NSDictionary *)data
           topic:(NSString *)topic
      macAddress:(NSString *)macAddress
          taskID:(mk_sd_serverOperationID)taskID
         timeout:(NSInteger)timeout
        sucBlock:(void (^)(id returnData))sucBlock
     failedBlock:(void (^)(NSError *error))failedBlock {
    MKSDMQTTOperation *operation = [self generateOperationWithTaskID:taskID
                                                               topic:topic
                                                          macAddress:macAddress
                                                                data:data
                                                            sucBlock:sucBlock
                                                         failedBlock:failedBlock];
    if (!operation) {
        return;
    }
    operation.operationTimeout = timeout;
    [self.operationQueue addOperation:operation];
}

#pragma mark - private method

- (MKSDMQTTOperation *)generateOperationWithTaskID:(mk_sd_serverOperationID)taskID
                                              topic:(NSString *)topic
                                        macAddress:(NSString *)macAddress
                                               data:(NSDictionary *)data
                                           sucBlock:(void (^)(id returnData))sucBlock
                                        failedBlock:(void (^)(NSError *error))failedBlock {
    if (!ValidDict(data)) {
        [self operationFailedBlockWithMsg:@"The data sent to the device cannot be empty" failedBlock:failedBlock];
        return nil;
    }
    if (!ValidStr(topic) || topic.length > 128) {
        [self operationFailedBlockWithMsg:@"Topic error" failedBlock:failedBlock];
        return nil;
    }
    if ([MKMQTTServerManager shared].managerState != MKMQTTSessionManagerStateConnected) {
        [self operationFailedBlockWithMsg:@"MTQQ Server disconnect" failedBlock:failedBlock];
        return nil;
    }
    __weak typeof(self) weakSelf = self;
    MKSDMQTTOperation *operation = [[MKSDMQTTOperation alloc] initOperationWithID:taskID macAddress:macAddress commandBlock:^{
        [[MKSDMQTTServerManager shared] sendData:data topic:topic sucBlock:nil failedBlock:nil];
    } completeBlock:^(NSError * _Nonnull error, id  _Nonnull returnData) {
        __strong typeof(self) sself = weakSelf;
        if (error) {
            moko_dispatch_main_safe(^{
                if (failedBlock) {
                    failedBlock(error);
                }
            });
            return ;
        }
        if (!returnData) {
            [sself operationFailedBlockWithMsg:@"Request data error" failedBlock:failedBlock];
            return ;
        }
        moko_dispatch_main_safe(^{
            if (sucBlock) {
                sucBlock(returnData);
            }
        });
    }];
    return operation;
}

- (void)operationFailedBlockWithMsg:(NSString *)message failedBlock:(void (^)(NSError *error))failedBlock {
    NSError *error = [[NSError alloc] initWithDomain:@"com.moko.RGMQTTDataManager"
                                                code:-999
                                            userInfo:@{@"errorInfo":message}];
    moko_dispatch_main_safe(^{
        if (failedBlock) {
            failedBlock(error);
        }
    });
}

#pragma mark - getter
- (NSOperationQueue *)operationQueue{
    if (!_operationQueue) {
        _operationQueue = [[NSOperationQueue alloc] init];
        _operationQueue.maxConcurrentOperationCount = 1;
    }
    return _operationQueue;
}

@end
