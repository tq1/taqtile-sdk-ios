
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
 * @param customData: A NSDictionary containing a JSON representation of custom data to be added.
 * @param completion: A block that is executed when the upload request has completed. The success block parameter indicates whether the data was uploaded or not.
 */
- (void)addCustomData:(NSDictionary *)customData completion:(void (^)(BOOL success))completion;

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


