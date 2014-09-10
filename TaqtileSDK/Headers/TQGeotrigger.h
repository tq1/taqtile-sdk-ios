//
//  TQGeotrigger.h
//  TaqtileSDK
//
//  Created by Taqtile on 14/08/14.
//  Copyright (c) 2014 Taqtile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GeotriggerSDK/GeotriggerSDK.h>

@interface TQGeotrigger : NSObject

+(TQGeotrigger *) shared;

-(void)startGeotriggerService:(NSString *)clientId withTags:(NSArray *)tags;
-(void)stopGeotriggerService:(NSString *)clientId withTags:(NSArray *)tags;

@end
