//
//  SmartpushNotification.m
//  SmartpushSDK
//
//  Created by Carlos Correa on 19/02/19.
//  Copyright © 2019 Smartpush. All rights reserved.
//

#import "SmartpushNotification.h"
#import "SmartpushSDKCore/SmartPushNotificationCore.h"

@interface SmartpushNotification()

@property SmartPushNotificationCore* notificationCore;

@end

@implementation SmartpushNotification

- (id)init {
    _notificationCore = [SmartPushNotificationCore new];
    return self;
}

-(id)instance {
    return _notificationCore;
}

@end
