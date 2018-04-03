//
//  SmartpushHit.h
//  SmartpushSDK
//
//  Created by William Hass on 7/26/15.
//  Copyright (c) 2015 Instad. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SmartpushHitField)
{
    SmartpushHitFieldPushId = 0,
    SmartpushHitFieldScreenName,
    SmartpushHitFieldCategory,
    SmartpushHitFieldLabel
};

@interface SmartpushHit : NSObject

- (void)setValue:(NSString *)value forField:(SmartpushHitField)field;
- (NSString *)getValueForField:(SmartpushHitField)field;
- (NSString *)stringForField:(SmartpushHitField)field;

- (id)instance;

@end
