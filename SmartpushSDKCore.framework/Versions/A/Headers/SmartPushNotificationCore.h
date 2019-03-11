//
//  SmartPushNotificationCore.h
//  SmartpushSDKCore
//
//  Created by Carlos Correa on 19/02/19.
//  Copyright © 2019 Instad. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SmartPushNotificationCore : NSObject

@property NSString *title;
@property NSString *body;
@property NSString *category;
@property NSString *carouselType;
@property NSString *mutableContent;
@property NSString *mediaUrl;
@property NSArray *banners;

@end
