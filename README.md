##How-to

Here it's described same methods and constants that have to be defined/implemented, others that are important and its' use in the app in general.
The format used is:
	
	@ [class_name]:
	- [methods_referenced]

###Record events

	@ TQAnalytics:
	- (void)recordEvent:(NSString *)event count:(int)count;
	- (void)recordEvent:(NSString *)event segmentation:(NSDictionary *)segmentation count:(int)count;

Used to record informations about the event, for example wich event happened, it's count, segmentation.
The ones implemented must be those that register only count and the other that registers count and segmntation.

Segmentaion is extra information about the event. In essence it can be anything.

###Receive push notifications

	@ TQ:
	- (void)handleForegroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId;
	- (void)handleBackgroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId;

Both methods handle how the app behaves when a push hits the device. Normally, they'd describe the app being open and showing the the pushs or showing the new push

###Retrieve custom content

	@ TQInbox:
	-(void) retrieveCustomContent: (NSString*)pushId completion:(void (^)(BOOL success))completion;

Each push is imbued with some extra content, which can be in the form of a tag, a link or simply a message.
TQInbox, representing the push, calls retrieveCustomContent to get it's custom content that is not splicitly contained within itself, but only represented as an id to the real content.
The params are pretty straightforward: the push's id and a completion block.

###Start TQ

	@ TQ:
	- (void)start:(NSString *)appKey withHost:(NSString *)appHost;
	- (void)start:(NSString *)appKey withHost:(NSString *)appHost andUDID: (NSString *)udid;

Start a connection with the server.

###Start Geotrigger Service
	
	@ TQGeotriggerService:
	-(void)startGeotriggerService:(NSString *)clientId withTags:(NSArray *)tags;

Usually called at the app start, it can be called to start the geotrigger service at any convenient time.

###Constants

	@ Constants:
	#define SA_APP_HOST
	#define SA_APP_KEY
	#define ARCGIS_CLIENT_ID
	#define DEFAULT_KEY_GEONOTIFICATIONS
	#define DEFAULT_KEY_USER_NAME
	#define DEFAULT_KEY_USER_EMAIL
	#define DEFAULT_KEY_USER_IMAGE_URL
	#define DEFAULT_TRACKING_PROFILE 
	#define DEFAULT_DEVICE_TAGS

All constants have to be defined for the app to work properly. Its' names should be all self-explanatory.

###More

 - [https://count.ly/resources/reference/features](https://count.ly/resources/reference/features)
 - [https://github.com/Esri/geotrigger-sdk-ios](https://github.com/Esri/geotrigger-sdk-ios)
 - [https://github.com/Esri/geotrigger-sdk-android](https://github.com/Esri/geotrigger-sdk-android)