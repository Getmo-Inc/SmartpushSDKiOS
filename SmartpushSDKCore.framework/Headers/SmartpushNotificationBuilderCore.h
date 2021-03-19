//
//  SmartpushNotificationBuilderCore.h
//  SmartpushSDKCore
//
//  Created by Carlos Correa on 06/03/19.
//  Copyright © 2019 Instad. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmartPushNotificationCore.h"
#import <UserNotifications/UserNotifications.h>

@interface SmartpushNotificationBuilderCore : NSObject

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *body;
@property (nonatomic, strong) NSString *category;
@property (nonatomic, strong) NSString *carouselType;
@property (nonatomic, strong) NSString *mutableContent;
@property (nonatomic, strong) NSString *mediaUrl;
@property (nonatomic, strong) NSArray *banners;

- (void) build;

@end
