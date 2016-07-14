//
//  SADeviceInfo.h
//  ShingleAnalytics
//
//  Created by Edmar Miyake on 9/23/13.
//  Copyright (c) 2013 Taqtile. All rights reserved.
//

#import <Foundation/Foundation.h>

/** TQ1DeviceInfo
 *  Holds all the pertinent information about the device.
 */
@interface TQ1DeviceInfo : NSObject

///////////////////////////////////////////////////////////////////////////
/// @name device information
///////////////////////////////////////////////////////////////////////////

/** udid
* @return device's udid
*/
+ (NSString *)udid;

/** device
 * @return device's plataform
 */
+ (NSString *)device;

/** osVersion
 * @return device's os' version
 */
+ (NSString *)osVersion;

/** platform
 * @return device's platform
 */
+ (NSString *)platform;

/** platformVersion
 * @return device's platform's version
 */
+ (NSString *)platformVersion;

/** carrier
 * @return device's carrier (Claro, Tim, etc)
 */
+ (NSString *)carrier;

/** resolution
 * @return device resolution
 */
+ (NSString *)resolution;

/** locale
 * @return device's locale
 */
+ (NSString *)locale;

/** locationEnabled
 * @return wether the user's given permission for location services
 */
+ (BOOL)locationEnabled;

/** pushEnabled
 * @return wether the user's given permission for push services
 */
+ (BOOL)pushEnabled;

/** metrics
 * @return a string formatted in a hash-fashion (@"{key: value}", for example) for the metrics: device, osVersion, carrier, resoution, locale, and
 * app version
 */
+ (NSString *)metrics;

/** settings
 * @return a string formatted in a hash-fashion (@"{key: value}", for example) for the metrics: pushEnabled and locationEnabled
 */
+ (NSString *)settings;

/** appVersion
 * @return the appVersion as a string
 */
+ (NSString *)appVersion;

/** deviceToken
 * @return the device's device token if it was already set, otherwise it returns nil
 */
+ (NSString *)deviceToken;

/** lastLocation
 * @return the last location update in the form (latitude, longitude) unix_time.
 */
+ (NSString *)lastLocation;

@end
