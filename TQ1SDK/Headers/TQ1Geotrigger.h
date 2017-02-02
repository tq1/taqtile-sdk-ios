//
//  TQ1Geotrigger.h
//  TQ1SDK
//
//  Created by Taqtile on 14/08/14.
//  Copyright (c) 2014 Taqtile. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TQGeoTriggerDelegate <NSObject>
@required
- (void)configure:(void (^)(void))completion;
- (void)start;
- (void)stop;
- (void)resume;
- (void)pause;
- (NSString *)getDeviceId;
@end

/** TQ1Geotrigger
 *  Simply commands when to start and when to stop the geotrigger service
 */
@interface TQ1Geotrigger: NSObject
/** shared
 *  Return an instance of itself, initializating it if there is no TQ1Geotrigger object. Since it's an shared object, it'll only create one.
 *
 * @return a TQ1Geotrigger object
 */
+(TQ1Geotrigger *) shared;

- (void)setManager: (id<TQGeoTriggerDelegate>)manager;

/** startGeotriggerService
 *  Starts the geotrigger service
 */
- (void)startGeotriggerService;

/** stopGeotriggerService
 *  Stops the geotrigger service
 */
- (void)stopGeotriggerService;


/** resumeGeotriggerService
 *  Starts the geotrigger service
 */
- (void)resumeGeotriggerService;

/** pauseGeotriggerService
 *  Stops the geotrigger service on iOS 8+ for the cases when location usage is only authorized when app is being used
 */
- (void)pauseGeotriggerService;

/** setGeonotificationActive
 *  set if geonotifications should be started according to user preferences
 */
-(void)setGeonotificationActive:(BOOL)geoNotification;

/** isGeonotificationActive
 *  return true is geonotifications are active and false otherwise
 */
-(BOOL)isGeonotificationActive;

/** requestGeofences
 *  gets all app Geofences
 *
 *  @returns an Geofences array
 */
- (void)requestGeofences:(int) page completion:(void (^)(NSArray *data))completion;

@end
