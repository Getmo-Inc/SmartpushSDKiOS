//
//  SmartpushHit.m
//  SmartpushSDK
//
//  Created by William Hass on 7/26/15.
//  Copyright (c) 2015 Instad. All rights reserved.
//

#import "SmartpushHit.h"
#import "SmartpushSDKCore/SmartpushHitCore.h"

@interface SmartpushHit()

@property SmartpushHitCore* hitCore;
@end

@implementation SmartpushHit

- (id)init {
    _hitCore = [SmartpushHitCore init];
    return self;
}

-(void)setValue:(NSString *)value forField:(SmartpushHitField)field {
    [_hitCore setValue:value forField:field];
}

- (NSString *)stringForField:(SmartpushHitField)field {
    return [_hitCore stringForField:field];
}

- (NSString *)getValueForField:(SmartpushHitField)field {
    return [_hitCore getValueForField:field];
}

@end
