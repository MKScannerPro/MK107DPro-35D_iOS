//
//  MKSDFilterByBeaconModel.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19..
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MKSDFilterByBeaconDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKSDFilterByBeaconModel : NSObject

- (instancetype)initWithPageType:(mk_sd_filterByBeaconPageType)pageType;

@property (nonatomic, assign)BOOL isOn;

@property (nonatomic, copy)NSString *uuid;

@property (nonatomic, copy)NSString *minMajor;

@property (nonatomic, copy)NSString *maxMajor;

@property (nonatomic, copy)NSString *minMinor;

@property (nonatomic, copy)NSString *maxMinor;

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

- (void)configDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
