//
//  EncryptUtil.m
//  以太优选
//
//  Created by 穆秋实 on 16/12/15.
//  Copyright © 2016年 EtherCap. All rights reserved.
//

#import "EncryptUtil.h"

@implementation EncryptUtil

- (NSString *)encryptString:(NSString *)str publicKey:(NSString *)pubKey{

    NSString* result = str;
    NSData *data = [RSA_Util encryptData:[str dataUsingEncoding:NSUTF8StringEncoding] publicKey:pubKey];
    if (data && [data length] > 0) {
        result = [self convertDataToHexStr:data];
    }
    return result;
}

- (NSString *)convertDataToHexStr:(NSData *)data {
    if (!self || [data length] == 0) {
        return @"";
    }
    NSMutableString *string = [[NSMutableString alloc] initWithCapacity:[data length]];
    
    [data enumerateByteRangesUsingBlock:^(const void *bytes, NSRange byteRange, BOOL *stop) {
        unsigned char *dataBytes = (unsigned char*)bytes;
        for (NSInteger i = 0; i < byteRange.length; i++) {
            NSString *hexStr = [NSString stringWithFormat:@"%x", (dataBytes[i]) & 0xff];
            if ([hexStr length] == 2) {
                [string appendString:hexStr];
            } else {
                [string appendFormat:@"0%@", hexStr];
            }
        }
    }];
    
    return string;
}


@end
