//
//  SmartpushNotificationBuilder.h
//  SmartpushSDK
//
//  Created by Carlos Correa on 06/03/19.
//  Copyright © 2019 Smartpush. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SmartpushNotificationBuilder : NSObject

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *body;
@property (nonatomic, strong) NSString *category;
@property (nonatomic, strong) NSString *carouselType;
@property (nonatomic, strong) NSString *mutableContent;
@property (nonatomic, strong) NSString *mediaUrl;
@property (nonatomic, strong) NSArray *banners;

- (void) build;

- (id)instance;

@end

