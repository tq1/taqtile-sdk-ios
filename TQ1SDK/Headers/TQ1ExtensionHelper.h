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


/** TQ1InboxMessage
 * Act as the push, storing it's message, contents, and other data
 */
@interface TQ1InboxMessage : NSObject
///////////////////////////////////////////////////////////////////////////
/// @name Properties
///////////////////////////////////////////////////////////////////////////
/**
 * The push's id in the database the TQ1InboxMessage is related to
 */
@property(readonly) NSString *id;

/**
 * The fence id that generated the push (empty string if normal push)
 */
@property(readonly) NSString *fenceId;


/**
 * Act as an inbox for pushes
 */
@property(readonly) NSString *alert;

/**
 * The push's content. It can be an tag, link or simple message
 */
@property(readonly) id content;

/**
 * The push's type. See the enum defined.
 */
@property(readonly) TQ1InboxMessageType type;

/**
 * If the push was read or not.
 */
@property(readonly) TQ1InboxMessageStatus status;

/**
 * If the push's data were all retrieved
 */
@property(readonly) BOOL complete;

/**
 * When the push was modified
 */
@property(readonly) int timestamp;

/**
 * Moment that the notification was scheduled at
 */
@property(readonly) int scheduled;

/**
 * The status already triggered with the push
 */
@property(readonly) NSString *customSentStatus;

/**
 * The customAction id for the push notification
 */
@property(readonly) NSString *customAction;

/** getCustomSentStatusList
 *  Get the custom status list that was already sent
 *
 * @return Array with the sent custom status
 */
-(NSArray*) getCustomSentStatusList;


/** isCustomStatusSent
 *  Verify if a status was already sent
 *
 * @param status: the referenced push's custom status
 *
 * @return whether there status was already sent or not
 */
-(BOOL) isCustomStatusSent: (NSString *)status;

@end

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
