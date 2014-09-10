//
//  TQ.h
//  TaqtileSDK
//
//  Created by Edmar Miyake on 11/20/13.
//  Copyright (c) 2013 Taqtile. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TQDelegate <NSObject>
- (void)handleForegroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId;
- (void)handleBackgroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId;
@end


@interface TQ : NSObject


+ (TQ *) shared;

+ (NSString *)appKey;
+ (NSString *)appHost;
+ (NSString *)udid;

- (void)start:(NSString *)appKey withHost:(NSString *)appHost;
- (void)start:(NSString *)appKey withHost:(NSString *)appHost andUDID: (NSString *)udid;
- (void)registerForRemoteNotificationTypes: (int) types delegate:(id<TQDelegate>)delegate;
- (void)trackRemoteNofitications:(id<TQDelegate>)delegate;
@end
