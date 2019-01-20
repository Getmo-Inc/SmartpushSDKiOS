//
//  SmartpushSDK.h
//  AnunciosPush
//
//  Created by William Hass on 7/27/14.
//  Copyright (c) 2014 William Hass. All rights reserved.
//  Version 2.2.1


#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "SmartpushHitCore.h"

@protocol SmartpushSDKDelegateCore <NSObject>

@optional

- (void)onPushAccepted:(NSDictionary *)push andOpenFromPush:(BOOL) openFromPush;
- (void)onPushAccepted:(NSDictionary *)push andOpenFromPush:(BOOL) openFromPush withUri:(NSString*) uri;

@end

@class UIUserNotificationSettings;

@interface SmartpushSDKCore : NSObject

extern NSString * const SmartpushSDKDeviceAddedNotification;
extern NSString * const SmartpushSDKUserInfoObtainedNotification;
extern NSString * const SmartpushSDKBlockUserNotification;

@property (strong, nonatomic) UIWindow *window;

+ (id)sharedInstance;

- (NSString *)getDeviceToken;

- (void)registerForPushNotifications;

- (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

- (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken;
- (void)didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings;

- (id)getDevice;
- (id)getUserInfo;
- (void)setValue:(NSString *)value forTag:(NSString *)key __deprecated_msg("use setString:foTag: instead.");

- (NSString *)getStringForTag:(NSString *)key;

- (void)setString:(NSString *)value forTag:(NSString *)key;
- (void)setArray:(NSArray *)array forTag:(NSString *)key;
- (void)setNumber:(NSNumber *)number forTag:(NSString *)key;
- (void)setBool:(BOOL)boolean forTag:(NSString *)key;
- (void)setDate:(NSDate*)date forTag:(NSString *)key;

- (void)delString:(NSString *)value forTag:(NSString *)key;
- (void)delArray:(NSArray *)array forTag:(NSString *)key;
- (void)delNumber:(NSNumber *)number forTag:(NSString *)key;
- (void)delBool:(BOOL)boolean forTag:(NSString *)key;
- (void)delDate:(NSDate*)date forTag:(NSString *)key;

- (void)delStringTag:(NSString *)key;
- (void)delArrayTag:(NSString *)key;
- (void)delNumberTag:(NSString *)key;
- (void)delBoolTag:(NSString *)key;
- (void)delDateTag:(NSString *)key;

- (void)nearestZoneWithLatitude:(double)latitude andLongitude:(double)longitude;
- (void)blockUser:(BOOL)block;
- (void)requestCurretUserInformation;
- (void)sendHit:(SmartpushHitCore*)smartpushHit;
- (void)sendHit:(SmartpushHitCore*)smartpushHit WithAction:(NSInteger) action;
- (void)checkHitQueue;

@property (weak, nonatomic) UIResponder<SmartpushSDKDelegateCore> * delegate;

@end
