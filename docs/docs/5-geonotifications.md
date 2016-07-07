# Working with TQ1 + TQG

Before going on, check [TQG docs](http://tqg-ios-sdk.readthedocs.io/en/master-ios/) on how to add it and setup in your project.

Once TQG is all set, you will need to "tell" TQ1 that you are using TQG. The first thing to do is to implement `TQGeotriggerDelegate` and `TQGeotrackerDelegate` interfaces. Here is an example where TQG is being used in these classes:

```objectivec
//TQGManager.h
#import <Foundation/Foundation.h>
#import <UIKit/UILocalNotification.h>
#import <UIKit/UIApplication.h>
#import "TQ1Geotrigger.h"
#import "TQGeolocationSDK-Swift.h"

@interface TQGManager: NSObject <TQGeoTriggerDelegate, TQGeoTrackerDelegate>

@end
```

```objectivec
//TQGManager.m
#import "TQGManager.h"

@implementation TQGManager

- (void)configure:(void (^)(void))completion
{
    [[TQGeoTracker sharedInstance] configure:@TQGKey triggerMode:TriggerModes.Both environment:TQEnvironments.Production];
    [[TQGeoTracker sharedInstance] setTriggerDelegate:self];
    completion();
}

- (void)start
{
    [[TQGeoTracker sharedInstance] start];
}

- (void)stop
{
    [[TQGeoTracker sharedInstance] stop];
}

- (void)resume
{
    [[TQGeoTracker sharedInstance] start];
}

- (void)pause
{
    [[TQGeoTracker sharedInstance] stop];
}

- (NSString *)getDeviceId
{
    return [[TQGeoTracker sharedInstance] getDeviceId];
}

- (void)TQGeoTrackerOnFenceTriggered:(TQGeoTracker *)tqGeoTracker fenceName:(NSString *)fenceName fenceId:(NSString *)fenceId type:(NSString *)type
{
    [[TQGeoTracker sharedInstance] log:[NSString stringWithFormat:@"OnFenceTriggered - fenceName: %@ fenceId: %@ type: %@", fenceName, fenceId, type]];

    //Send local notification
    UILocalNotification *notification = [[UILocalNotification alloc] init];
    notification.fireDate = [[NSDate alloc] init];
    notification.alertBody = [NSString stringWithFormat:@"fenceName: %@ fenceId: %@ type: %@", fenceName, fenceId, type];
    [[UIApplication sharedApplication] scheduleLocalNotification: notification];
}

@end
```

With these classes implemented, you can use its' methods to start TQG:
```objectivec
[[TQ1Geotrigger shared] setManager:[[TQGManager alloc] init]];
[[TQ1Geotrigger shared] startGeotriggerService];
```
