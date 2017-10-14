//
//  SmartpushNotificationTest.h
//  SmartpushSDK
//
//  Created by Rodrigo Busata on 12/09/17.
//  Copyright © 2017 Smartpush. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, NotificationType) {
    PushNormal = 0,
    PushEmoji,
    PushImage,
    PushGif,
    PushAudio,
    PushVideo,
    PushCarouselCoverflow,
    PushCarouselRotary,
    PushCarouselCylinder,
    PushCarouselCylinderInverted,
    PushCarouselLinear,
    PushCarouselStack,
    PushCarouselStackInverted
};


@interface SmartpushNotificationTest : NSObject 

+ (void) requestTestNotificationBy: (NotificationType) type completion:(void (^)(BOOL))completionBlock;

@end
