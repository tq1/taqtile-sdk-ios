
// Countly.h
//
// This code is provided under the MIT License.
//
// Please visit www.count.ly for more information.

#import <Foundation/Foundation.h>


@interface TQAnalytics : NSObject

+ (TQAnalytics *) shared;

- (void)start;
- (void)resume;
- (void)suspend;
- (void)exit;


- (void)recordEvent:(NSString *)event count:(int)count;
- (void)recordEvent:(NSString *)event segmentation:(NSDictionary *)segmentation count:(int)count;
- (void)recordSocial;
- (void)addBluetoohStateToConnectionQueue:(BOOL)state;

@end


