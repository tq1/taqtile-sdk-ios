//
//  TQ1Geotrigger.h
//  TQ1SDK
//
//  Created by Taqtile on 14/08/14.
//  Copyright (c) 2014 Taqtile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GeotriggerSDK/GeotriggerSDK.h>

/** TQ1Geotrigger
 *  Simply commands when to start and when to stop the geotrigger service
 */
@interface TQ1Geotrigger : NSObject
/** shared
 *  Return an instance of itself, initializating it if there is no TQ1Geotrigger object. Since it's an shared object, it'll only create one.
 *
 * @return a TQ1Geotrigger object
 */
+(TQ1Geotrigger *) shared;

/** configureWithClientId and Tags
 * Initialize Geotrigger constants
 *
 * @param clientId: the client Id
 * @param tags: An optional list of tags to be set on the device after it registers itself
 * @see https://developers.arcgis.com/geotrigger-service/ios-reference/Classes/AGSGTGeotriggerManager.html#//api/name/setupWithClientId:trackingProfile:registerForRemoteNotifications:isProduction:tags:completion:
 */
- (void) configureWithClientId:(NSString *)clientId andTags:(NSArray *)tags andCompletionHandler:(void (^)(void))completionHandler;

/** startGeotriggerService
 *  Starts the geotrigger service
 */
- (void) startGeotriggerService;

/** stopGeotriggerService
 *  Stops the geotrigger service
 */
- (void) stopGeotriggerService;

/** startGeotriggerService clientId withTags
 *  Starts the geotrigger service
 *  You should use instead the no arguments version of this method and ensure that this is called after the configure method
 *
 * @param clientID: the client ID
 * @param tags: An optional list of tags to be set on the device after it registers itself
 * @see https://developers.arcgis.com/geotrigger-service/ios-reference/Classes/AGSGTGeotriggerManager.html#//api/name/setupWithClientId:trackingProfile:registerForRemoteNotifications:isProduction:tags:completion:
 */
-(void)startGeotriggerService:(NSString *)clientId withTags:(NSArray *)tags __deprecated;

/** stopGeotriggerService clientId withTags
 *  Stops the geotrigger service
 *  You should use instead the no arguments version of this method and ensure that this is called after the configure method
 *
 * @param clientID: the client ID
 * @param tags: An optional list of tags to be set on the device after it stops
 */
-(void)stopGeotriggerService:(NSString *)clientId withTags:(NSArray *)tags __deprecated;


/** resumeGeotriggerService
 *  Starts the geotrigger service
 *
  */
- (void)resumeGeotriggerService;

/** pauseGeotriggerService
 *  Stops the geotrigger service on iOS 8+ for the cases when location usage is only authorized when app is being used
 *
 */
-(void)pauseGeotriggerService;

/** trackingId
 *  gets the registered track id to the device
 *
 * @return a string representing the track id
 */
+(NSString *)trackingId;

/** requestGeofences
 *  gets all app Geofences
 *
 * @returns an Geofences array
 */
-(void) requestGeofences:(int) page completion:(void (^)(NSArray *data))completion;

@end
