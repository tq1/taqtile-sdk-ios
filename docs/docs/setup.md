# SDK Project

You must edit application's main Podfile. The project used can change depending on the geotrigger service used. Below you can find guidance for both possiblities.

# TQG Geotrigger Service

```ruby
target :yourTarget do
  pod 'TQ1SDK', :git => 'https://github.com/tq1/taqtile-sdk-ios.git', :tag => '3.0.13-no-tracking'
  pod 'TQGeolocationSDK', '1.2.0'
end
```

# ESRI Geotrigger Service

```ruby
target :yourTarget do
  pod 'TQ1SDK', :git => 'https://github.com/tq1/taqtile-sdk-ios.git', :tag => '3.0.13-esri'
  pod 'GeotriggerSDK', '1.2.1'
end
```

In all cases, you must create a class that implements the interface `TQGeoTriggerDelegate` and pass it during initialization.