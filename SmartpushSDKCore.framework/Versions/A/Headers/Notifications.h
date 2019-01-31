//
//  Notifications.h
//  SmartpushSDKCore
//
//  Created by Carlos Correa on 21/01/19.
//  Copyright © 2019 Instad. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Notifications : NSObject

@property NSString *pushid;
@property NSString *clicked;
@property NSString *payload;
@property NSString *extra;
@property NSString *createdAt;
@property NSString *sentAt;

- (id)initWithJSON:(NSString *)jsonResponse;

@end

