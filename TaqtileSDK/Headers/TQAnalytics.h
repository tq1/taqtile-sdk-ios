
// Countly.h
//
// This code is provided under the MIT License.
//
// Please visit www.count.ly for more information.

#import <Foundation/Foundation.h>

/** TQAnalytics
 *  Handle analytical data and it's retrieval through periodic actions.
 */
@interface TQAnalytics : NSObject

/** recordSocial
 *  Records the social data (facebook) if an facebook session is initiated. It records the facebookId, gender and age of the user.
 */
- (void)recordSocial;

/** addBluetoohStateToConnectionQueue
 *  
 */
- (void)addBluetoohStateToConnectionQueue:(BOOL)state;

/** shared
 *  Return an instance of itself, initializating it if there is no TQAnalytics object. Since it's an shared object, it'll only create one.
 *
 * @return a TQAnalytics object
 */
+ (TQAnalytics *) shared;

///////////////////////////////////////////////////////////////////////////
/// @name event recording
///////////////////////////////////////////////////////////////////////////
/** recordEvent count
 *  Record an event's count, adding it to the previous count.
 *
 * @param event: The event's name
 * @param count: the count to be added
 */
- (void)recordEvent:(NSString *)event count:(int)count;

/** recordEvent segmentation count
 *  Record an event's count, adding it to the previous count.
 *
 * @param event: The event's name
 * @param count: the count to be added
 * @param segmentation: adicional information about the event
 */
- (void)recordEvent:(NSString *)event segmentation:(NSDictionary *)segmentation count:(int)count;

///////////////////////////////////////////////////////////////////////////
/// @name Custom data
///////////////////////////////////////////////////////////////////////////
/** addCustomData customData completion
 *  Add device's custom data at our API. Note that it'll override any existing data already added.
 *
 * @param customData: A NSDictionary containing a JSON representation of custom data to be added. Keys must be string and values can only be Strings, Integers or Doubles
 * @param completion: A block that is executed when the upload request has completed. The success block parameter indicates whether the data was uploaded or not.
 */
- (void)addCustomData:(NSDictionary *)customData completion:(void (^)(BOOL success))completion;

///////////////////////////////////////////////////////////////////////////
/// @name Custom data
///////////////////////////////////////////////////////////////////////////
/** addCustomData customData completion
 *  Add device's custom data at our API. Note that it'll override any existing data already added.
 *
 * @param customData: A NSDictionary containing a JSON representation of custom data to be added. Keys must be string and values can only be Strings, Integers or Doubles
 * @param keysToIgnore: An array of strings with the keys that should be ignored when adding the data filters. Data that is too sparse MUST be ignored, like User Ids for example
 * @param completion: A block that is executed when the upload request has completed. The success block parameter indicates whether the data was uploaded or not.
 */
- (void)addCustomData:(NSDictionary *)customData keysToIgnore:(NSArray *)keysToIgnore completion:(void (^)(BOOL success))completion;

/** updateSettings
*   Send current settings ("location enabled" and "push enabled") to api in order to update them.
*/
-(void)updateSettings;

///////////////////////////////////////////////////////////////////////////
/// @name Custom status
///////////////////////////////////////////////////////////////////////////
/** updateStatus pid status completion
 *  Add push notification's custom status at our API.
 *
 * @param pid: A string with the push notification id for which should be added the custom status.
 * @param status: A custom status name that was trigged by the push notification.
 * @param completion: A block that is executed when the upload request has completed. The success block parameter indicates whether the status was uploaded or not.
 */
- (void)updateStatus:(NSString *)pid status:(NSString *)status completion:(void (^)(BOOL success))completion;

///////////////////////////////////////////////////////////////////////////
/// @name Custom action
///////////////////////////////////////////////////////////////////////////
/** sendActionChoosen buttonChoosen pid completion
 *  Add push notification's custom status at our API.
 *
 * @param buttonChoosen: A custom action button choosen.
 * @param pid: A string with the push notification id for which should be added the custom status.
 * @param completion: A block that is executed when the upload request has completed. The success block parameter indicates whether the status was uploaded or not.
 */
- (void)sendActionChoosen:(NSString *)buttonChoosen pid:(NSString *)pid completion:(void (^)(BOOL success))completion;

///////////////////////////////////////////////////////////////////////////
/// @name Timer handles
///////////////////////////////////////////////////////////////////////////
/** start
 *  starts the timer for periodic actions.
 */
- (void)start;

/** suspend
 * suspends the timer.
 */
- (void)suspend;

/** suspend
 * resume the timer.
 */
- (void)resume;

/** exit
 * does nothing.
 */
- (void)exit;

@end


