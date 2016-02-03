# Start TQ1

First, pass an instance of your `TQGeoTriggerDelegate` class before starting:

```objectivec
[[TQ1Geotrigger shared] setManager:[[YourGeotriggerClass alloc] init]];
```

To make possible for the user to receive pushes, first it's necessary to make some configuration. To do it, set the TQ's required configurations:

```objectivec
[[TQ1 shared] startWithKey:key];
[[TQ1 shared] trackRemoteNofitications:self];
```

  - key: is the identification of the application the app refers to in the TQ1 API.

Also, it's possible to configure how the incoming pushes will inform the user it came:

```objectivec
[[UIApplication sharedApplication] registerForRemoteNotificationTypes:
         (UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert)];
```

With this configuration, the app may:
  - badge its icon upon a notification being received
  - play a sound upon a notification being received
  - display an alert upon a notification being received

There is also another method:

```objectivec
- (void)registerForRemoteNotificationTypes: (int) types delegate:(id<TQDelegate>)delegate;
```

all it does is the same as *trackRemoteNofitications* followed by *registerForRemoteNotificationTypes* with a little more: it checks the device's version to adapt the code to avoid deprecated methods. It's preferable to run the latter than running the other two together.

And before ending this section, two little warnings:

  - ideally *trackRemoteNofitications* should be run at the start of *didFinishLaunching* so the sdk can receive the necessary messages.

  - after running the above, the application's delegate will be replaced with another delegate at runtime, so it'll not be possible to access it the normal way. But all the messages passed to the new delegate will reach your delegate, so don't worry.

##Geotrigger
Not much to it, just start the geotrigger manager so it's possible for the user to receive pushes from the geofences:

```objectivec
[[TQ1Geotrigger shared] startGeotriggerService];
```

And to stop it:

```
[[TQ1Geotrigger shared] stopGeotriggerService];
```
