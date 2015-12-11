//
//  TQ1Inbox.h
//  TQ1SDK
//
//  Created by Edmar Miyake on 12/3/13.
//  Copyright (c) 2013 Taqtile. All rights reserved.
//

#import <Foundation/Foundation.h>
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
/// @name methods
///////////////////////////////////////////////////////////////////////////
/** initWithPushId
 * instantiates an in-memory TQ1InboxMessage representing the push
 *
 * @param id: the referenced the push's id
 * @param alert: the referenced push's alert
 * @param content: the referenced push's content
 * @param type: which type of content the push holds (see enum defined)
 * @param status: the referenced push's status (see enum defined)
 * @param complete: the referenced push's complete parameter
 * @param timestamp: the referenced push's timestamp
 * @param customSentStatus: the referenced push's custom status
 * @param customAction: the referenced push's custom status
 *
 * @return
 *
 */
-(id)initWithPushId: (NSString *)id fenceId:(NSString *)fenceId alert:(NSString *)alert content:(NSString *)content type:(TQ1InboxMessageType)type status:(TQ1InboxMessageStatus)status complete:(BOOL)complete timestamp: (int) timestamp scheduled:(int) scheduled customStatus:(NSString *)customStatus customAction:(NSString *)customAction;
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
@interface TQ1Inbox : NSObject

///////////////////////////////////////////////////////////////////////////
/// @name methods
///////////////////////////////////////////////////////////////////////////
/** shared
*  Return an instance of itself, initializating it if there is no TQ1Inbox object. Since it's an shared object, it'll only create one.
*
* @return a TQ1Inbox object
*/
+ (TQ1Inbox *)shared;

/** addAlert
 *  Add an alert to the refenced push
 *
 * @param pushId: the referenced push's Id
 * @param alert: the alert to be added
 * @param action: the action if exists to be added
 *
 * @return whether the transaction was successful or not
 */
-(BOOL) addAlert: (NSString *)pushId fenceId: (NSString *)fenceId alert:(NSString *) alert action:(NSString *)customAction;

/** addAlert
 *  Add an alert to the refenced push
 *
 * @param pushId: the referenced push's Id
 * @param alert: the alert to be added
 *
 * @return whether the transaction was successful or not
 */
-(BOOL) addAlert: (NSString *)pushId alert:(NSString *) alert __attribute__((deprecated));

/** retrieveCustomContent
 *  Retrieves a certain push's content
 *
 * @param pushId: the referenced push's Id
 * @param completion: a block called after the content is retrieved that receives if the transaction was successful and the content itself
 */
-(void) retrieveCustomContent: (NSString*)pushId completion:(void (^)(BOOL success, TQ1InboxMessage *message))completion;

/** getInboxMessage
 *  Gets all the TQ1InboxMessages with a given status (see the enum defined)
 *
 * @param status: the status the message should have to be retrieved
 *
 * @return an array containing all the matching TQ1InboxMessages not ordered
 */
-(NSArray *)getInboxMessages:(TQ1InboxMessageStatus) status;

/** getInboxMessage
 *  Gets an specific push through it's identification
 *
 * @param pushId: the referenced push's Id
 *
 * @return a TQ1InboxMessage with all the push's information
 */
-(TQ1InboxMessage *) getInboxMessage:(NSString *)pushId;

/** getInboxMessageCount
 *  Gets the count of TQ1InboxMessages with a certain status. Faster than getInboxMessages if only the count is necessary.
 *
 * @param status: the status the TQ1InboxMessage should have to be counted
 *
 * @return the count as an int
 *
 * @warning since the return is an int, it cannot receive messages
 */
-(int)getInboxMessagesCount:(TQ1InboxMessageStatus) status;

/** markAsRead
 *  Change a certain push's status to 'already read' (see defined enum).
 *
 * @param pushId: the referenced push's id
 *
 * @return if the push was updated to 'already read' or not
 */
-(BOOL) markAsRead:(NSString *)pushId;

/** markAsUnread
 *  Change a certain push's status to 'not read' (see defined enum).
 *
 * @param pushId: the referenced push's id
 *
 * @return if the push was updated to 'not read' or not
 */
-(BOOL) markAsUnread: (NSString *)pushId;

/** removeMessagesWithStatus
 *  Removes multiple messages from the database
 *
 * @param status READ, UNREAD or ALL
 *
 * @return the number of rows affected by the deletion
 */
-(int) removeMessagesWithStatus: (TQ1InboxMessageStatus)status;

/** removeMessage
 *  Delete a certain push from the database.
 *
 * @param pushId: the referenced push's id
 *
 * @return if the push was deleted successfully or not
 */
-(BOOL)removeMessage:(NSString *)pushId;


/** addCustomStatus
 *  Add a custom status for the push in the database.
 *
 * @param pushId: the referenced push's id
 *
 * @param status: the referenced push's custom status
 *
 * @return if the push custom status was added or not
 */
-(BOOL)addCustomStatus:(NSString *)pushId status:(NSString *) status;



@end
