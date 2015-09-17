//
//  TQ.h
//  TaqtileSDK
//
//  Created by Edmar Miyake on 11/20/13.
//  Copyright (c) 2013 Taqtile. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TQ_PLATFORM "ios"
#define TQ_SDK_VERSION @"3.0"
#define TQ_API_VERSION @"v3"

@protocol TQDelegate <NSObject>
- (void)handleForegroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId;
- (void)handleBackgroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId;
- (void)handleCustomActionWithIdentifier:(NSString *)identifier pushId:(NSString *)pushId;
@end

/** TQ
 *  Holds information about the device and the app. Also, handle the initial configuration.
 */
@interface TQ : NSObject

///////////////////////////////////////////////////////////////////////////
/// @name methods
///////////////////////////////////////////////////////////////////////////
/** shared
 *  Return an instance of itself, initializating it if there is no TQ object. Since it's an shared object, it'll only create one.
 * 
 * @return a TQ object
 */
+ (TQ *) shared;

/** appKey
 *  
 * Returns the appKey of the application the app is related to.
 *
 * @return an string representing the appKey
 */
+ (NSString *)appKey;

/** appHost
 *
 * Returns the host of the application the app is related to.
 *
 * @return host name in a string format
 */
+ (NSString *)appHost;

/** udid
 *
 * Returns the 'unique device id' of the device.
 *
 * @return the device udid.
 */
+ (NSString *)udid;

/** apiVersion
 *
 * Returns the server's API version.
 *
 * @return the server api version.
 */
+ (NSString *)apiVersion;

/** registerForRemoteNotificationTypes delegate
 *
 * Register the device to push notifications of the specified type
 *
 * @param types: constant indicating the push type
 *      @see https://developer.apple.com/library/ios/documentation/uikit/reference/UIApplication_Class/index.html#//apple_ref/c/tdef/UIRemoteNotificationType
 * @param delegate: any object that implements the TQDelegate protocol.
 *
 * @warning this method sends "trackRemoteNotifications" to TQ. See trackRemoteNotifications' warnings for more information
 */
- (void)registerForRemoteNotificationTypes: (int) types delegate:(id<TQDelegate>)delegate;

/**
 * @param automatic: when this flag is set to true, as soon as a remote notification arrives (considering app running in background), the content is downloaded and
 *   stored in local database. When false, the application is responsible for downloading this content when the user clicks on the message.
 */
- (void)setPushContentDowloadAutomatic: (BOOL) automatic;

/** trackRemoteNofitications
 *
 * @param delegate: any object that implements the TQDelegate protocol.
 *
 * @warning sending this message to TQ will substitute the given param with something else, and it's important to call this method before sending any messages to the given delegate so the app works.
 */
- (void)trackRemoteNofitications:(id<TQDelegate>)delegate;

/** start withHost andUDID
 *
 * Initial configuration for receiving push notifications. 
 *
 * @param appKey: the application's appkey in string format
 * @param udid: the device's udid in string format
 * @param appHost: the application's host in string format
 * @param apiVersion: the server's api version in string format
 *
 * @warning Not triggered if it is not in foreground
 */
- (void)start:(NSString *)appKey withHost:(NSString *)appHost;
- (void)start:(NSString *)appKey withHost:(NSString *)appHost andUDID: (NSString *)udid;
- (void)stop;
@end
