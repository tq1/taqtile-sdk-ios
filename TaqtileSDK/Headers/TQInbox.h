//
//  TQInbox.h
//  TaqtileSDK
//
//  Created by Edmar Miyake on 12/3/13.
//  Copyright (c) 2013 Taqtile. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum
{
	TQInboxMessageTypePush,
	TQInboxMessageTypeHtml,
	TQInboxMessageTypeLink,
	TQInboxMessageTypeTag,
	TQInboxMessageTypePassbook,
	TQInboxMessageTypeYoutube
} TQInboxMessageType;

typedef enum
{
	TQInboxMessageStatusUnread,
	TQInboxMessageStatusRead,
	TQInboxMessageStatusAll
	
} TQInboxMessageStatus;


/** TQInboxMessage
 * Act as the push, storing it's message, contents, and other data
 */
@interface TQInboxMessage : NSObject

///////////////////////////////////////////////////////////////////////////
/// @name methods
///////////////////////////////////////////////////////////////////////////
/** initWithPushId
 * instantiates an in-memory TQInboxMessage representing the push
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
-(id)initWithPushId: (NSString *)id fenceId:(NSString *)fenceId alert:(NSString *)alert content:(NSString *)content type:(TQInboxMessageType)type status:(TQInboxMessageStatus)status complete:(BOOL)complete timestamp: (int) timestamp customStatus:(NSString *)customStatus customAction:(NSString *)customAction;
///////////////////////////////////////////////////////////////////////////
/// @name Properties
///////////////////////////////////////////////////////////////////////////
/**
 * The push's id in the database the TQInboxMessage is related to
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
@property(readonly) TQInboxMessageType type;

/**
 * If the push was read or not.
 */
@property(readonly) TQInboxMessageStatus status;

/**
 * If the push's data were all retrieved
 */
@property(readonly) BOOL complete;

/**
 * When the push was modified
 */
@property(readonly) int timestamp;


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

/** TQInbox
 * Act as an inbox for pushes
 */
@interface TQInbox : NSObject

///////////////////////////////////////////////////////////////////////////
/// @name methods
///////////////////////////////////////////////////////////////////////////
/** shared
*  Return an instance of itself, initializating it if there is no TQInbox object. Since it's an shared object, it'll only create one.
*
* @return a TQInbox object
*/
+ (TQInbox *)shared;

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
-(void) retrieveCustomContent: (NSString*)pushId completion:(void (^)(BOOL success, TQInboxMessage *message))completion;

/** getInboxMessage
 *  Gets all the TQInboxMessages with a given status (see the enum defined)
 *
 * @param status: the status the message should have to be retrieved
 *
 * @return an array containing all the matching TQInboxMessages not ordered
 */
-(NSArray *)getInboxMessages:(TQInboxMessageStatus) status;

/** getInboxMessage
 *  Gets an specific push through it's identification
 *
 * @param pushId: the referenced push's Id
 *
 * @return a TQInboxMessage with all the push's information
 */
-(TQInboxMessage *) getInboxMessage:(NSString *)pushId;

/** getInboxMessageCount
 *  Gets the count of TQInboxMessages with a certain status. Faster than getInboxMessages if only the count is necessary.
 *
 * @param status: the status the TQInboxMessage should have to be counted
 *
 * @return the count as an int
 *
 * @warning since the return is an int, it cannot receive messages
 */
-(int)getInboxMessagesCount:(TQInboxMessageStatus) status;

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

/** removeMessage
 *  Delete a certain push from the database.
 *
 * @param pushId: the referenced push's id
 *
 * @return if the push was deleted successfully or not
 */
-(BOOL)removeMessage:(NSString *)pushId timestamp:(int) timestamp;


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
