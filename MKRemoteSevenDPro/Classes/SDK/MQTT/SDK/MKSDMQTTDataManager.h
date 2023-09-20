//
//  MKSDMQTTDataManager.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MKSDServerConfigDefines.h"

#import "MKSDMQTTTaskID.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const MKSDMQTTSessionManagerStateChangedNotification;

extern NSString *const MKSDReceiveDeviceOnlineNotification;

extern NSString *const MKSDReceiveDeviceOTAResultNotification;

extern NSString *const MKSDReceiveDeviceNpcOTAResultNotification;

extern NSString *const MKSDReceiveDeviceResetByButtonNotification;

extern NSString *const MKSDReceiveDeviceUpdateEapCertsResultNotification;

extern NSString *const MKSDReceiveDeviceUpdateMqttCertsResultNotification;

extern NSString *const MKSDReceiveDeviceNetStateNotification;

extern NSString *const MKSDReceiveDeviceDatasNotification;

extern NSString *const MKSDReceiveGatewayDisconnectBXPButtonNotification;

extern NSString *const MKSDReceiveGatewayDisconnectDeviceNotification;

extern NSString *const MKSDReceiveGatewayConnectedDeviceDatasNotification;

extern NSString *const MKSDReceiveBxpButtonDfuProgressNotification;

extern NSString *const MKSDReceiveBxpButtonDfuResultNotification;


extern NSString *const MKSDReceiveDeviceOfflineNotification;

extern NSString *const MKSDReceivePowerDataNotification;

extern NSString *const MKSDReceiveEnergyDataNotification;

extern NSString *const MKSDReceiveLoadChangeNotification;

@protocol MKSDReceiveDeviceDatasDelegate <NSObject>

- (void)mk_sd_receiveDeviceDatas:(NSDictionary *)data;

@end

@interface MKSDMQTTDataManager : NSObject<MKSDServerManagerProtocol>

@property (nonatomic, weak)id <MKSDReceiveDeviceDatasDelegate>dataDelegate;

@property (nonatomic, assign, readonly)MKSDMQTTSessionManagerState state;

+ (MKSDMQTTDataManager *)shared;

+ (void)singleDealloc;

/// 当前app连接服务器参数
@property (nonatomic, strong, readonly, getter=currentServerParams)id <MKSDServerParamsProtocol>serverParams;

/// 当前用户有没有设置MQTT的订阅topic，如果设置了，则只能定于这个topic，如果没有设置，则订阅添加的设备的topic
@property (nonatomic, copy, readonly, getter=currentSubscribeTopic)NSString *subscribeTopic;

/// 当前用户有没有设置MQTT的订阅topic，如果设置了，则只能定于这个topic，如果没有设置，则订阅添加的设备的topic
@property (nonatomic, copy, readonly, getter=currentPublishedTopic)NSString *publishedTopic;

/// 将参数保存到本地，下次启动通过该参数连接服务器
/// @param protocol protocol
- (BOOL)saveServerParams:(id <MKSDServerParamsProtocol>)protocol;

/**
 清除本地记录的设置信息
 */
- (BOOL)clearLocalData;

#pragma mark - *****************************服务器交互部分******************************

/// 开始连接服务器，前提是必须服务器参数不能为空
- (BOOL)connect;

- (void)disconnect;

/**
 Subscribe the topic

 @param topicList topicList
 */
- (void)subscriptions:(NSArray <NSString *>*)topicList;

/**
 Unsubscribe the topic
 
 @param topicList topicList
 */
- (void)unsubscriptions:(NSArray <NSString *>*)topicList;

- (void)clearAllSubscriptions;

/// Send Data
/// @param data json
/// @param topic topic,1-128 Characters
/// @param macAddress macAddress,6字节16进制，不包含任何符号AABBCCDDEEFF
/// @param taskID taskID
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
- (void)sendData:(NSDictionary *)data
           topic:(NSString *)topic
      macAddress:(NSString *)macAddress
          taskID:(mk_sd_serverOperationID)taskID
        sucBlock:(void (^)(id returnData))sucBlock
     failedBlock:(void (^)(NSError *error))failedBlock;

/// Send Data
/// @param data json
/// @param topic topic,1-128 Characters
/// @param macAddress macAddress,6字节16进制，不包含任何符号AABBCCDDEEFF
/// @param taskID taskID
/// @param timeout 任务超时时间
/// @param sucBlock Success callback
/// @param failedBlock Failed callback
- (void)sendData:(NSDictionary *)data
           topic:(NSString *)topic
      macAddress:(NSString *)macAddress
          taskID:(mk_sd_serverOperationID)taskID
         timeout:(NSInteger)timeout
        sucBlock:(void (^)(id returnData))sucBlock
     failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
