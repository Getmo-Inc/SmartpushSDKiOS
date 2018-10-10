//
//  NotificationService.h
//  SmartpushNotificationExtension
//
//  Created by Rodrigo Busata on 14/08/17.
//  Copyright © 2017 Smartpush. All rights reserved.
//

#import <UserNotifications/UserNotifications.h>

@interface SmartpushNotificationService : UNNotificationServiceExtension

+ (void) requestTestNotification: (NSInteger) type isProd:(BOOL) isProd completion:(void (^)(BOOL))completionBlock;

@end

