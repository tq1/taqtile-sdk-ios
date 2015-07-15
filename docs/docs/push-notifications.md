##Classes

Basically there are two classes that handle push notifications: TQInbox and TQInboxMessage, both described in 'TQInbox.h'.

###TQInboxMessage

TQInboxMessage represents a push, holding all its informations, but by itself it can't do anything.

```objectivec
@interface TQInboxMessage : NSObject
-(id)initWithPushId: (NSString *)id alert:(NSString *)alert content:(id)content type:(TQInboxMessageType)type status:(TQInboxMessageStatus)status complete:(BOOL)complete timestamp: (int) timestamp;

@property(readonly) NSString *id;
@property(readonly) NSString *alert;
@property(readonly) id content;
@property(readonly) TQInboxMessageType type;
@property(readonly) TQInboxMessageStatus status;
@property(readonly) BOOL complete;
@property(readonly) int timestamp;
@property(readonly) NSString fenceId;

@end
```

##TQInbox

The TQInbox class is a representation of a push notification inbox and describes methods to manipulate said pushes, like: getting a certain push, marking pushes as read, deleting pushes from the inbox, etc.

```objectivec
@interface TQInbox : NSObject
  +(TQInbox *)shared;
  -(BOOL) addAlert: (NSString *)pushId alert:(NSString *) alert;

  -(void) retrieveCustomContent: (NSString*)pushId completion:(void (^)(BOOL success, TQInboxMessage *message))completion;

  -(NSArray *)getInboxMessages:(TQInboxMessageStatus) status;

  -(TQInboxMessage *) getInboxMessage:(NSString *)pushId;

  -(int)getInboxMessagesCount:(TQInboxMessageStatus) status;

  -(BOOL) markAsRead:(NSString *)pushId;

  -(BOOL) markAsUnread: (NSString *)pushId;

  -(BOOL)removeMessage:(NSString *)pushId;

@end
```

Just note that, since there should only exist one TQInbox per app, the correct way to call those methods is by sending the message to the 'shared' return. The 'shared' method will take care of creating an inbox or returning the existing one.

```objectivec
//For example:
[[TQInbox shared] getInboxMessage: @"1234"]
```

Also, one should create a class that handles how the app behaves when a push is received by implementing the TQDelegate protocol, defined in TQ.h:

```objectivec
@protocol TQDelegate <NSObject>
  - (void)handleForegroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId;
  - (void)handleBackgroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId;
@end
```

##Handling incoming pushes
When the push first arrives, the app may or may not be open, in background, etc; so it's necessary to implement the protocol *TQDelegate* and the *didFinishLaunchingWithOptions* event that will determinate the actions to take in each state.
In special, the TQProtocol will describe what happens when the app is open, and in its' implementation it will become necessary to get the received push (to display it, for example). In that case one should use the method *getInboxMessage* inside the protocol's implementation, since they do receive the received push's id:

```objectivec
- (void)handleBackgroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId
{
    TQInboxMessage *receivedPush;
    //Code
    receivedPush = [[[TQInbox] shared] getInboxMessage: pushId];
    //More code
}
```

##Handling all received pushes

Now, when there are already received pushes in the inbox and it's necessary to show those, the natural thing to do should be to get all read/unread pushes, and to do that call *getInboxMessages* on the inbox. That method takes a status to do the filtering. The possible status are defined in an enum in the header, but here they are:

```objectivec
typedef enum
{
  TQInboxMessageStatusUnread,
  TQInboxMessageStatusRead,
  TQInboxMessageStatusAll
} TQInboxMessageStatus;
```

And naturally, to get, let's say, unread pushes call *getInboxMessages*  with a TQInboxMessageStatusUnread parameter:

```objectivec
[[TQInbox shared] getInboxMessages: TQInboxMessageStatusUnread]
```

And if you need the read pushes use TQInboxMessageStatusRead as the parameter, and to get all use the TQInboxMessageStatusAll parameter.

But if it's only necessary to get how many pushes there are in the inbox, there is no necessity to get all the pushes and then count them. In this case simply call *getInboxMessagesCount*. It's faster, it's better, it's cleaner. The method receives the same type of parameter as *getInboxMessages*:

```objectivec
[[TQInbox shared] getInboxMessagesCount: TQInboxMessageStatusUnread]
```

Be warned, though, that this returns an "int", not an "NSInteger" nor an "NSNumber".

##Handling a single push

By now the app should be able to list all pushes. Finally, to handle a single push.
There's just a few things to do with a single push.
The first of them is to mark a push as read or unread. So in the view controller, there should be some code as:

```objectivec
if ([[TQInbox shared] markAsRead:pushId]){
  //The push was marked!
}else{
  //The push was not marked...
}
```

The second is to delete the push. It deletes the push from the database:

```objectivec
if ([[TQInbox shared] removeMessage:pushId]){
  //The push was deleted!
}else{
  //The push was not deleted...
}
```

And the third is to retrieve the pushes content. Since pushes and its' contents are not in the same table, it's necessary to retrieve it through the push:

```objectivec
[[TQInbox shared] retrieveCustomContent:pushId completion:^(BOOL success, TQInboxMessage *message)
```

The first parameter is the push's id and the second is a block that receives if it was possible to retrieve the content and the TQInboxMessage with the retrieved content.

You can also tell the SDK to download the content as soon as the notification arrives via the method call:
```objectivec
[[TQPush shared] setDownloadAutomatic: true]
```

Keep in mind that this is only possible when the application is currently running in background. When the user clicks on the notification, you can check whether the content was already downloaded or not by verifying the `complete` field. In the latter case the content should be requested:

```objectivec
TQInboxMessage *notification;
if(!notification.complete)
{
  // Request content HERE
}
```

##Removing Multiple Notifications

There is a method available for removing all notifications specified by its `TQInboxMessageStatus`: *READ*, *UNREAD* or *ALL*.

```objectivec
[[TQInbox shared] removeMessagesWithStatus: TQInboxMessageStatusAll]
```
