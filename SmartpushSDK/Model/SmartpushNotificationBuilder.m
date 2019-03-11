//
//  SmartpushNotificationBuilder.m
//  SmartpushSDK
//
//  Created by Carlos Correa on 06/03/19.
//  Copyright © 2019 Smartpush. All rights reserved.
//

#import "SmartpushNotificationBuilder.h"
#import "SmartpushSDKCore/SmartpushNotificationBuilderCore.h"

@interface SmartpushNotificationBuilder()

@property SmartpushNotificationBuilderCore* notificationCore;

@end

@implementation SmartpushNotificationBuilder

- (id)init {
    _notificationCore = [SmartpushNotificationBuilderCore new];
    return self;
}

- (void)setTitle:(NSString *)title {
    [_notificationCore setTitle:title];
}

- (void)setBody:(NSString *)body {
    [_notificationCore setBody:body];
}

- (void)setCategory:(NSString *)category{
    [_notificationCore setCategory:category];
}

- (void)setCarouselType:(NSString *)carouselType{
    [_notificationCore setCarouselType:carouselType];
}

- (void)setMutableContent:(NSString *)mutableContent{
    [_notificationCore setMutableContent:mutableContent];
}

- (void)setMediaUrl:(NSString *)mediaUrl{
    [_notificationCore setMediaUrl:mediaUrl];
}

- (void)setBanners:(NSArray *)banners {
    [_notificationCore setBanners:banners];
}

-(id)instance {
    return _notificationCore;
}

- (void) build {
    [_notificationCore build];
}


@end
