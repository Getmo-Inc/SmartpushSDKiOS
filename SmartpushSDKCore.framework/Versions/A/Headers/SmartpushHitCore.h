//
//  SmartpushHitCore.h
//  SmartpushSDK
//
//  Created by William Hass on 7/26/15.
//  Copyright (c) 2015 Instad. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SmartpushHitCore : NSObject

@property NSInteger action;

- (void)setValue:(NSString *)value forField:(NSUInteger)field;
- (NSString *)getValueForField:(NSUInteger)field;
- (NSString *)stringForField:(NSUInteger)field;

@end
