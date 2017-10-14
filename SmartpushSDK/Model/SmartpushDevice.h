//
//  AddDeviceResponse.h
//  AnunciosPush
//
//  Created by William Hass on 8/7/14.
//  Copyright (c) 2014 William Hass. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SmartpushDevice : NSObject

@property NSString *alias;
@property NSString *hwid;
@property double balance;

@end
