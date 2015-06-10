##Starting up

Not much to it, just start the geotrigger manager so it's possible for the user to receive pushes from the geofences:
```objectivec
[[TQGeotrigger shared] startGeotriggerService:ARCGIS_CLIENT_ID withTags:DEFAULT_DEVICE_TAGS];
```

Where:

  - ARCGIS_CLIENT_ID: the application id to access the ESRI server
  - DEFAULT_DEVICE_TAGS: an array with the initial device tags

And to stop it:

```
[[TQGeotrigger shared] stopGeotriggerService:ARCGIS_CLIENT_ID withTags:DEFAULT_DEVICE_TAGS];
```

##Getting app geofences

In order to get all geofences that are registered for the application on TQ1 server, you use:

```objectivec
[[TQGeotrigger shared] requestGeofences:0 completion:^(NSArray *data)
{
  //You method here
}];
```
The number you pass is the page, each page brings 20 geofences. If there is no Geofences or there is less than 20, then it is the last page. The variable `data` is an Array of `NSDictionaries` and you should handle it inside the completion block.

##Other references
For more information, go [here](https://developers.arcgis.com/geotrigger-service/ios-reference/Classes/AGSGTGeotriggerManager.html)
