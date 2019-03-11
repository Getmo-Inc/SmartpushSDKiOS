//
//  SmartpushNotificationTest.h
//  SmartpushSDK
//
//  Created by Rodrigo Busata on 12/09/17.
//  Copyright © 2017 Smartpush. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, NotificationTypeTest) {
    PushNormalTest = 0,
    PushEmojiTest,
    PushImageTest,
    PushGifTest,
    PushAudioTest,
    PushVideoTest,
    PushCarouselCoverflowTest,
    PushCarouselRotaryTest,
    PushCarouselCylinderTest,
    PushCarouselCylinderInvertedTest,
    PushCarouselLinearTest,
    PushCarouselStackTest,
    PushCarouselStackInvertedTest
};


@interface SmartpushNotificationTest : NSObject 

+ (void) requestTestNotificationBy: (NotificationTypeTest) type isProd:(BOOL) isProd completion:(void (^)(BOOL))completionBlock;

@end
