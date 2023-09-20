//
//  Target_ScannerPro_107DPro_Module.m
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import "Target_ScannerPro_107DPro_Module.h"

#import "MKSDDeviceListController.h"

@implementation Target_ScannerPro_107DPro_Module

- (UIViewController *)Action_MKScannerPro_107DPro_DeviceListPage:(NSDictionary *)params {
    MKSDDeviceListController *vc = [[MKSDDeviceListController alloc] init];
    vc.connectServer = YES;
    return vc;
}

@end
