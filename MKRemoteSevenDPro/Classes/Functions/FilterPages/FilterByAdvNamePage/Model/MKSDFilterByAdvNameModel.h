//
//  MKSDFilterByAdvNameModel.h
//  MKRemoteSevenDPro_Example
//
//  Created by aa on 2023/9/19.
//  Copyright © 2023 aadyx2007@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKSDFilterByAdvNameModel : NSObject

@property (nonatomic, assign)BOOL preciseMatch;

@property (nonatomic, assign)BOOL reverseFilter;

@property (nonatomic, strong)NSArray *dataList;

- (void)readDataWithSucBlock:(void (^)(void))sucBlock failedBlock:(void (^)(NSError *error))failedBlock;

- (void)configDataWithNameList:(NSArray <NSString *>*)nameList
                      sucBlock:(void (^)(void))sucBlock
                   failedBlock:(void (^)(NSError *error))failedBlock;

@end

NS_ASSUME_NONNULL_END
