//
//  SmartpushSDK.m
//  SmartpushSDK
//
//  Created by Rodrigo Busata on 04/09/17.
//  Copyright © 2017 Smartpush. All rights reserved.
//
#import "SmartpushSDKCore/SmartpushSDKCore.h"

#import "SmartpushSDK.h"
#import "SmartpushDevice.h"

@implementation SmartpushSDK

+ (SmartpushSDK*)sharedInstance {
    static SmartpushSDK *sharedMyManager;
    static dispatch_once_t token;
    dispatch_once(&token, ^{
        sharedMyManager = [[self alloc] init];
    });
    return sharedMyManager;
}

- (void) setDelegate:(id) delegate {
    _delegate = delegate;
    [(SmartpushSDKCore*)[SmartpushSDKCore sharedInstance] setDelegate:delegate];
}

- (NSString *)getDeviceToken{
    return [[SmartpushSDKCore sharedInstance] getDeviceToken];
}

- (void)registerForPushNotifications {
    [[SmartpushSDKCore sharedInstance] registerForPushNotifications];
}

- (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [[SmartpushSDKCore sharedInstance] didFinishLaunchingWithOptions:launchOptions];
}

- (void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    [[SmartpushSDKCore sharedInstance] didFailToRegisterForRemoteNotificationsWithError:error];
}

- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo {
    [[SmartpushSDKCore sharedInstance] didReceiveRemoteNotification:userInfo];
}

- (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken {
    [[SmartpushSDKCore sharedInstance] didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}

- (void)didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings {
    [[SmartpushSDKCore sharedInstance] didRegisterUserNotificationSettings:notificationSettings];
}

- (SmartpushDevice *)getDevice {
    return [[SmartpushSDKCore sharedInstance] getDevice];
}
- (SmartpushUser *)getUserInfo {
    return [[SmartpushSDKCore sharedInstance] getUserInfo];
}

- (void)setValue:(NSString *)value forTag:(NSString *)key __deprecated_msg("use setString:foTag: instead.") {
    [[SmartpushSDKCore sharedInstance] setValue:value forKey:key];
}

- (void)setString:(NSString *)value forTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] setString:value forTag:key];
}

- (void)setArray:(NSArray *)array forTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] setArray:array forTag:key];
}

- (void)setNumber:(NSNumber *)number forTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] setNumber:number forTag:key];
}

- (void)setBool:(BOOL)boolean forTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] setBool:boolean forTag:key];
}

- (void)setDate:(NSDate*)date forTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] setDate:date forTag:key];
}

- (void)delString:(NSString *)value forTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] delString:value forTag:key];
}

- (void)delArray:(NSArray *)array forTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] delArray:array forTag:key];
}

- (void)delNumber:(NSNumber *)number forTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] delNumber:number forTag:key];
}

- (void)delBool:(BOOL)boolean forTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] delBool:boolean forTag:key];
}

- (void)delDate:(NSDate*)date forTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] delDate:date forTag:key];
}

- (void)delStringTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] delStringTag:key];
}

- (void)delArrayTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] delArrayTag:key];
}

- (void)delNumberTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] delNumberTag:key];
}

- (void)delBoolTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] delBoolTag:key];
}

- (void)delDateTag:(NSString *)key {
    [[SmartpushSDKCore sharedInstance] delDateTag:key];
}

- (void)nearestZoneWithLatitude:(double)latitude andLongitude:(double)longitude {
    [[SmartpushSDKCore sharedInstance] nearestZoneWithLatitude:latitude andLongitude:longitude];
}

- (void)blockUser:(BOOL)block {
    [[SmartpushSDKCore sharedInstance] blockUser:block];
}

- (void)requestCurretUserInformation {
    [[SmartpushSDKCore sharedInstance] requestCurretUserInformation];
}

- (void)sendHit:(SmartpushHit *)smartpushHit {
    [[SmartpushSDKCore sharedInstance] sendHit:smartpushHit];
}

- (void)sendHit:(SmartpushHit *)smartpushHit WithAction:(HitType) action {
    [[SmartpushSDKCore sharedInstance] sendHit:smartpushHit WithAction:action];
}

- (void)checkHitQueue {
    [[SmartpushSDKCore sharedInstance] checkHitQueue];
}

@end
