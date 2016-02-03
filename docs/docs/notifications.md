##Handling incoming pushes

Basically there are two classes that handle push notifications: TQ1Inbox and TQ1InboxMessage, both described in 'TQ1Inbox.h'.

Just note that, since there should only exist one TQ1Inbox per app, the correct way to call those methods is by sending the message to the 'shared' return. The 'shared' method will take care of creating an inbox or returning the existing one.

```objectivec
//For example:
[[TQ1Inbox shared] getInboxMessage: @"1234"]
```

Also, one should create a class that handles how the app behaves when a push is received by implementing the TQDelegate protocol, defined in TQ1.h:

```objectivec
@protocol TQDelegate <NSObject>
  - (void)handleForegroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId;
  - (void)handleBackgroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId;
@end
```

When the push first arrives, the app may or may not be open, in background, etc; so it's necessary to implement the protocol *TQDelegate* and the *didFinishLaunchingWithOptions* event that will determinate the actions to take in each state.
In special, the TQProtocol will describe what happens when the app is open, and in its' implementation it will become necessary to get the received push (to display it, for example). In that case one should use the method *getInboxMessage* inside the protocol's implementation, since they do receive the received push's id:

```objectivec
- (void)handleBackgroundPushNotification:(NSDictionary *)userInfo pushId:(NSString *) pushId
{
    TQ1InboxMessage *receivedPush;
    //Code
    receivedPush = [[[TQ1Inbox] shared] getInboxMessage: pushId];
    //More code
}
```

##Handling all received pushes

Now, when there are already received pushes in the inbox and it's necessary to show those, the natural thing to do should be to get all read/unread pushes, and to do that call *getInboxMessages* on the inbox. That method takes a status to do the filtering. The possible status are defined in an enum in the header, but here they are:

```objectivec
typedef enum
{
  TQ1InboxMessageStatusUnread,
  TQ1InboxMessageStatusRead,
  TQ1InboxMessageStatusAll
} TQ1InboxMessageStatus;
```

And naturally, to get, let's say, unread pushes call *getInboxMessages*  with a TQ1InboxMessageStatusUnread parameter:

```objectivec
[[TQ1Inbox shared] getInboxMessages: TQ1InboxMessageStatusUnread]
```

And if you need the read pushes use TQ1InboxMessageStatusRead as the parameter, and to get all use the TQ1InboxMessageStatusAll parameter.

But if it's only necessary to get how many pushes there are in the inbox, there is no necessity to get all the pushes and then count them. In this case simply call *getInboxMessagesCount*. It's faster, it's better, it's cleaner. The method receives the same type of parameter as *getInboxMessages*:

```objectivec
[[TQ1Inbox shared] getInboxMessagesCount: TQ1InboxMessageStatusUnread]
```

Be warned, though, that this returns an "int", not an "NSInteger" nor an "NSNumber".

##Handling a single push

By now the app should be able to list all pushes. Finally, to handle a single push.
There's just a few things to do with a single push.
The first of them is to mark a push as read or unread. So in the view controller, there should be some code as:

```objectivec
if ([[TQ1Inbox shared] markAsRead:pushId]){
  //The push was marked!
}else{
  //The push was not marked...
}
```

The second is to delete the push. It deletes the push from the database:

```objectivec
if ([[TQ1Inbox shared] removeMessage:pushId]){
  //The push was deleted!
}else{
  //The push was not deleted...
}
```

And the third is to retrieve the pushes content. Since pushes and its' contents are not in the same table, it's necessary to retrieve it through the push:

```objectivec
[[TQ1Inbox shared] retrieveCustomContent:pushId completion:^(BOOL success, TQ1InboxMessage *message)
```

The first parameter is the push's id and the second is a block that receives if it was possible to retrieve the content and the TQ1InboxMessage with the retrieved content.

You can also tell the SDK to download the content as soon as the notification arrives via the method call:
```objectivec
[[TQ1Push shared] setDownloadAutomatic: true]
```

Keep in mind that this is only possible when the application is currently running in background. When the user clicks on the notification, you can check whether the content was already downloaded or not by verifying the `complete` field. In the latter case the content should be requested:

```objectivec
TQ1InboxMessage *notification;
if(!notification.complete)
{
  // Request content HERE
}
```

##Removing Multiple Notifications

There is a method available for removing all notifications specified by its `TQ1InboxMessageStatus`: *READ*, *UNREAD* or *ALL*.

```objectivec
[[TQ1Inbox shared] removeMessagesWithStatus: TQ1InboxMessageStatusAll]
```
