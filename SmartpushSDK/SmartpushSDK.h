//
//  SmartpushSDK.h
//  SmartpushSDK
//
//  Created by Rodrigo Busata on 10/08/17.
//  Copyright © 2017 Smartpush. All rights reserved.
//  Version 2.2

#import <UIKit/UIKit.h>
#import "SmartpushUser.h"
#import "SmartpushDevice.h"
#import "SmartpushHit.h"
#import "HitType.h"
#import "NotificationsCore.h"
#import "ExtraContentCore.h"

@protocol SmartpushSDKDelegate <NSObject>

@optional

- (void)onPushAccepted:(NSDictionary *)push andOpenFromPush:(BOOL) openFromPush;
- (void)onPushAccepted:(NSDictionary *)push andOpenFromPush:(BOOL) openFromPush withUri:(NSString*) uri;

@end

@class UIUserNotificationSettings, SmartpushUser;

@interface SmartpushSDK : NSObject

extern NSString * const SmartpushSDKDeviceAddedNotification;
extern NSString * const SmartpushSDKUserInfoObtainedNotification;
extern NSString * const SmartpushSDKBlockUserNotification;
extern NSString * const SmartpushSDKLastNotificationsObtainedNotification;
extern NSString * const SmartpushSDKUnreadNotificationsObtainedNotification;
extern NSString * const SmartpushSDKExtraContentObtainedNotification;

@property (strong, nonatomic) UIWindow *window;

- (NSString *)getDeviceToken;

- (void)registerForPushNotifications;

- (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

- (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken;
- (void)didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings;

+ (SmartpushSDK*)sharedInstance;

- (SmartpushDevice *)getDevice;
- (SmartpushUser *)getUserInfo;
- (NotificationsCore*)getLastNotifications;
- (NotificationsCore*)getUnreadNotifications;
- (ExtraContentCore*)getExtraContent;
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
- (void)requestLastNotifications;
- (void)requestUnreadNotifications;
- (void)sendHit:(SmartpushHit *)smartpushHit;
- (void)sendHit:(SmartpushHit *)smartpushHit WithAction:(HitType) action;
- (void)checkHitQueue;
- (void)markPushAsRead:(NSString *)pushId;
- (void)markAllAsRead;
- (void)requestExtraContentFor:(NSString *)pushId;

@property (weak, nonatomic) UIResponder<SmartpushSDKDelegate> * delegate;

@end
