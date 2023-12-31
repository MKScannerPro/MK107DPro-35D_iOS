//
//  MKSDEasyShowView.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDEasyShowView : UIView

- (void)showText:(NSString *)text
       superView:(UIView *)superView
        animated:(BOOL)animated;

- (void)hidden;

@end

NS_ASSUME_NONNULL_END
