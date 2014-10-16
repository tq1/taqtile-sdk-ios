//
//  SADeviceInfo.h
//  ShingleAnalytics
//
//  Created by Edmar Miyake on 9/23/13.
//  Copyright (c) 2013 Taqtile. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TQDeviceInfo : NSObject

+ (NSString *)udid;
+ (NSString *)device;
+ (NSString *)osVersion;
+ (NSString *)carrier;
+ (NSString *)resolution;
+ (NSString *)locale;
+ (NSString *)locationEnabled;
+ (NSString *) pushEnabled;
+ (NSString *)metrics;
+ (NSString *)settings;

@end