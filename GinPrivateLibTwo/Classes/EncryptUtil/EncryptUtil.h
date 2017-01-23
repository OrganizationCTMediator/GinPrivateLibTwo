//
//  EncryptUtil.h
//  以太优选
//
//  Created by 穆秋实 on 16/12/15.
//  Copyright © 2016年 EtherCap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RSA_Util.h"

@interface EncryptUtil : NSObject
- (NSString *)encryptString:(NSString *)str publicKey:(NSString *)pubKey;
@end
