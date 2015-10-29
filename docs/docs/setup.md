Include in your project:

  1. The [Taqtile-SDK-ios - https://github.com/tq1/taqtile-sdk-ios](https://github.com/tq1/taqtile-sdk-ios)

Remember that you should not have a dependency on the GeotriggerSDK, as it might be fixed in an older version which can impact how the SDK works

##Cocoapods

If your application uses pods, this step is easy.
All you have to do is include the pod in your application's podfile:

```ruby
source 'https://github.com/indigotech/Specs.git'

target "yourTargetName" do
  pod 'TQ1SDK'
end
```
run *pod install* in your application and there you go.

##Other options

Clone the project (or download as zip) from git@github.com:tq1/taqtile-sdk-ios.git to your  project's path, import the headers inside the 'headers' folder and link your project's binary to the library.
To do that last part, select your project's target -> Build Phases tab -> drag and drop libTaqtile.SDK.a to 'Link binary to libraries'.

##Configuring it
To make possible for the user to receive pushes, first it's necessary to make some configuration. To do it, set the TQ's required configurations:

```objectivec
[[TQ shared] start:APP_KEY withHost:APP_HOST];
[[TQ shared] trackRemoteNofitications:someDelegate];
```

  - APP_KEY: is the identification of the application the app refers to in the TQ1 API.
  - APP_HOST:  url the TQ1 points to.
  - CLASS: the class that will be delegated to when a push comes.

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

##iOS 9 (beta) Considerations

  - Use Xcode `6.4`

  - Geotrigger SDK 1.1.0 may behave oddly and not trigger (works on already installed apps though)

  - When using Xcode 7, it will force you to use https, so it won't work the way it's implemented today. What can be done is to add an exception. See the [this link](http://ste.vn/2015/06/10/configuring-app-transport-security-ios-9-osx-10-11/)
