//
//  MKSDTestController.m
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import "MKSDTestController.h"

#import "Masonry.h"

#import "MKCustomUIAdopter.h"

#import "MKSDDeviceListController.h"

@interface MKSDTestController ()

@end

@implementation MKSDTestController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.defaultTitle = @"Remote gateway";
    self.leftButton.hidden = YES;
    UIButton *button = [MKCustomUIAdopter customButtonWithTitle:@"MK107D Pro-35D"
                                                         target:self
                                                         action:@selector(pushRemoteGatewayPage)];
    [self.view addSubview:button];
    [button mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(self.view.mas_centerX);
        make.width.mas_equalTo(180.f);
        make.centerY.mas_equalTo(self.view.mas_centerY);
        make.height.mas_equalTo(40.f);
    }];
}

- (void)pushRemoteGatewayPage {
    MKSDDeviceListController *vc = [[MKSDDeviceListController alloc] init];
    vc.connectServer = YES;
    [self.navigationController pushViewController:vc animated:YES];
}

@end
