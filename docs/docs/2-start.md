# Start TQ1

## Preparing the AppDelegate
The first thing to do is to make your `AppDelegate` implement the `TQDelegate` interface, so it will be able to handle push notifications.

To make possible for the user to receive pushes, first it's necessary to make some configuration. To do it, set the TQ's required configurations, like in the following example:

```objectivec
@interface AppDelegate : UIResponder <UIApplicationDelegate, TQ1Delegate>
```

Once you add the `TQDelegate`an error will appear, that is because you have to implement the following `TQDelegate`  methods:

```objectivec
-(void)handleBackgroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *)pushId
{
}

-(void)handleForegroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *)pushId
{
}

-(void)handleCustomActionWithIdentifier:(NSString *)identifier pushId:(NSString *)pushId
{
}
```

They will be explained later on the [push notifications section](4-notifications.md).

## Start method

```objectivec
[[TQ1 shared] startWithKey:AppKey];
[[TQ1 shared] trackRemoteNofitications:self];
```

  - AppKey: the app identifier that will be used by our server. In order to get it, check the [setup section](1-setup.md).

The first method will send the device information to our server and the second one will inform `TQ1 SDK` that this class will handle the push notifications. Note that, ideally `trackRemoteNofitications` should be run at the start of `didFinishLaunching` application method so the sdk can receive the necessary messages.

## Register for remote notifications

In order to receive notifications, you will have to register your application. In order to do this you can follow the [iOS documentation](https://developer.apple.com/library/ios/documentation/NetworkingInternet/Conceptual/RemoteNotificationsPG/Chapters/IPhoneOSClientImp.html), or simply do like the example below:

```objectivec
//Inside didFinishLaunching you will setup the notification settings
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  //Starting TQ1
  [[TQ1 shared] startWithKey:key andEnvironment:Development];
  [[TQ1 shared] trackRemoteNofitications:self];

  [[UIApplication sharedApplication] registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil]];

  return YES;
}

```

With this configuration, the app may:
  - badge its icon upon a notification being received
  - play a sound upon a notification being received
  - display an alert upon a notification being received

You need also to implement:

```objectivec
- (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings
{
    [[NSNotificationCenter defaultCenter]
     postNotificationName:@"notification.alert.registered"
     object:notificationSettings];
    [[UIApplication sharedApplication] registerForRemoteNotifications];
}
```

Once this is done, when you run the app TQ1 will automatically detect that you've registered for remote notifications and will send the device token to the server (you can check the logs, there should be a request to TQ1 with the words `device-token`).
