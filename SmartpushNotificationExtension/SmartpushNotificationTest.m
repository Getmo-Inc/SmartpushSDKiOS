//
//  SmartpushNotificationTest.m
//  SmartpushSDK
//
//  Created by Rodrigo Busata on 12/09/17.
//  Copyright © 2017 Smartpush. All rights reserved.
//


#import "SmartpushNotificationTest.h"
#import <SmartpushSDKCore/SmartpushNotificationService.h>

@implementation SmartpushNotificationTest 

+ (void) requestTestNotificationBy: (NotificationType) type isProd:(BOOL) isProd completion:(void (^)(BOOL))completionBlock {
    [SmartpushNotificationService requestTestNotification:type isProd: isProd completion:completionBlock];
}

@end
