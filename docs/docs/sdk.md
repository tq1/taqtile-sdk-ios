##Obtaining the SDK

The first step is installing the SDK.

If one is using Cocoapods for dependency management, simply add the next line in your Podfile and run 'pod install' at the root folder of the project:

```
pod 'TQ1SDK', :git => 'https://github.com/tq1/taqtile-sdk-ios.git', :tag => '2.8.0'
```

Otherwise, clone the repository to your project folder and import the library by selecting your project's target and adding the library under the 'build phases' tab in 'Link Binaries with Libraries'.

P.S: `2.8.0` is just an example. You should check the repository for the latest realease.
