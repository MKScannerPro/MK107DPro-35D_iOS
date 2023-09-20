//
//  MKSDMqttServerLwtView.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDMqttServerLwtViewModel : NSObject

@property (nonatomic, assign)BOOL lwtStatus;

@property (nonatomic, assign)BOOL lwtRetain;

@property (nonatomic, assign)NSInteger lwtQos;

@property (nonatomic, copy)NSString *lwtTopic;

@property (nonatomic, copy)NSString *lwtPayload;

@end

@protocol MKSDMqttServerLwtViewDelegate <NSObject>

- (void)sd_lwt_statusChanged:(BOOL)isOn;

- (void)sd_lwt_retainChanged:(BOOL)isOn;

- (void)sd_lwt_qosChanged:(NSInteger)qos;

- (void)sd_lwt_topicChanged:(NSString *)text;

- (void)sd_lwt_payloadChanged:(NSString *)text;

@end

@interface MKSDMqttServerLwtView : UIView

@property (nonatomic, strong)MKSDMqttServerLwtViewModel *dataModel;

@property (nonatomic, weak)id <MKSDMqttServerLwtViewDelegate>delegate;

@end

NS_ASSUME_NONNULL_END
