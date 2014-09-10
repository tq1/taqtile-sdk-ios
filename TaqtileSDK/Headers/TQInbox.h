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



@interface TQInboxMessage : NSObject

-(id)initWithPushId: (NSString *)id alert:(NSString *)alert content:(id)content type:(TQInboxMessageType)type status:(TQInboxMessageStatus)status complete:(BOOL)complete timestamp: (int) timestamp;


@property(readonly) NSString *id;
@property(readonly) NSString *alert;
@property(readonly) id content;
@property(readonly) TQInboxMessageType type;
@property(readonly) TQInboxMessageStatus status;
@property(readonly) BOOL complete;
@property(readonly) int timestamp;

@end


@interface TQInbox : NSObject

+ (TQInbox *)shared;
-(BOOL) addAlert: (NSString *)pushId alert:(NSString *) alert;
-(void) retrieveCustomContent: (NSString*)pushId completion:(void (^)(BOOL success))completion;
-(NSArray *)getInboxMessages:(TQInboxMessageStatus) status;
-(TQInboxMessage *) getInboxMessage:(NSString *)pushId;
-(int)getInboxMessagesCount:(TQInboxMessageStatus) status;
-(BOOL) markAsRead:(NSString *)pushId;
-(BOOL) markAsUnread: (NSString *)pushId;
-(BOOL)removeMessage:(NSString *)pushId;



@end
