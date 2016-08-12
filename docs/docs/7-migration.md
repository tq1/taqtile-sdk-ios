# Migrating from V2 to V3

If you already have an app that implements TQ1 V2, migration should be very simple. We will assume that you use ESRI as the geolocation service, as V2 does not support TQG.

## Update deployment target
TQ1 V3 will work only from iOS 8 on, so, if your app has deployment target 7, you should update it both on Podfile and project configuration.

## Update the Pod

Update your Podfile, TQ1 pod declaration is probably like this one:

`pod 'TaqtileSDK',           :git => 'https://github.com/tq1/taqtile-sdk-ios.git', :tag => '2.9.1'`

Now, it should be like this:

`pod 'TQ1SDK',           :git => 'https://github.com/tq1/taqtile-sdk-ios.git', :tag => '3.2.0-esri'`

Just remember that you should adequate the version number according to your needs.

Once you try to build you will realize that it will break and some changes will have to be done.

## Replace "TaqtileSDK" occurences

As you might have already realized from the pod name, the package name is now TQ1SDK, so the imports will change too. It'll be from `#import <TaqtileSDK/TQ.h>` to `#import <TQ1SDK/TQ1.h>`

## Replace TQ with TQ1

Our old classes were named like `TQSomething`. All these classes are now `TQ1Something`. For example: `TQDelegate` should now be `TQ1Delegate`

## Change the start method

The old start method, that used to be called as:

`[[TQ shared] start:TQ1_APP_KEY withHost:TQ1_APP_HOST];`

Is now like this:

`[[TQ1 shared] startWithKey:TQ1_APP_KEY];`

You don't need to inform the host anymore, so you can simply get rid of this env var.

## GeotriggerSDK imports

If you use ESRI GeotriggerSDK and start it manually (using `AGSGTGeotriggerManager`) on your app, you will have to import it on the classes using it:

`#import <GeotriggerSDK/GeotriggerSDK.h>`
