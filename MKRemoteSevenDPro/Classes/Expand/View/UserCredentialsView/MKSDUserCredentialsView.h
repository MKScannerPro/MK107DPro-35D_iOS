//
//  MKSDUserCredentialsView.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDUserCredentialsViewModel : NSObject

@property (nonatomic, copy)NSString *userName;

@property (nonatomic, copy)NSString *password;

@end

@protocol MKSDUserCredentialsViewDelegate <NSObject>

- (void)sd_mqtt_userCredentials_userNameChanged:(NSString *)userName;

- (void)sd_mqtt_userCredentials_passwordChanged:(NSString *)password;

@end

@interface MKSDUserCredentialsView : UIView

@property (nonatomic, strong)MKSDUserCredentialsViewModel *dataModel;

@property (nonatomic, weak)id <MKSDUserCredentialsViewDelegate>delegate;

@end

NS_ASSUME_NONNULL_END
