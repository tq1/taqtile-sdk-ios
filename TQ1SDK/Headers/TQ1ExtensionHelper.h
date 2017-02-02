//
//  TQ1ExtensionHelper.h
//  TQ1SDK
//
//  Created by Edmar Miyake on 12/3/13.
//  Copyright (c) 2013 Taqtile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

typedef enum
{
    TQ1InboxMessageTypePush,
    TQ1InboxMessageTypeHtml,
    TQ1InboxMessageTypeLink,
    TQ1InboxMessageTypeTag,
    TQ1InboxMessageTypePassbook,
    TQ1InboxMessageTypeYoutube
} TQ1InboxMessageType;

typedef enum
{
    TQ1InboxMessageStatusUnread,
    TQ1InboxMessageStatusRead,
    TQ1InboxMessageStatusAll
    
} TQ1InboxMessageStatus;


/** TQ1Inbox
 * Act as an inbox for pushes
 */
@interface TQ1ExtensionHelper : NSObject

///////////////////////////////////////////////////////////////////////////
/// @name methods
///////////////////////////////////////////////////////////////////////////
/** shared
 *  Return an instance of itself, initializating it if there is no TQ1ExtensionHelper object. Since it's an shared object, it'll only create one.
 *
 * @return a TQ1ExtensionHelper object
 */
+ (TQ1ExtensionHelper *)shared;

/** addPush
 *  Add the a push notification to the database *
 * @param push: Notification content to be added to the database
 * @param appGroup: the app group so extension and app will be able to share data
 *
 */
-(void) saveNotification: (UNMutableNotificationContent *)push appGroup:(NSString *)appGroup;



@end
