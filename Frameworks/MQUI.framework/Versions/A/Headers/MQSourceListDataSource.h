//
//  MQSourceListDataSource.h
//  QQ4Mac
//
//  Created by Hugoyao on 11-12-10.
//  Copyright 2011年 tencent. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class MQSourceList;

@protocol MQSourceListDataSource <NSObject>

@required
- (NSUInteger)sourceList:(MQSourceList*)sourceList numberOfChildrenOfItem:(id)item;
- (id)sourceList:(MQSourceList*)aSourceList child:(NSUInteger)index ofItem:(id)item;
- (id)sourceList:(MQSourceList*)aSourceList objectValueForItem:(id)item;
- (BOOL)sourceList:(MQSourceList*)aSourceList isItemExpandable:(id)item;

@optional
- (void)sourceList:(MQSourceList*)aSourceList setObjectValue:(id)object forItem:(id)item;

- (BOOL)sourceList:(MQSourceList*)aSourceList itemHasBadge:(id)item;
- (NSInteger)sourceList:(MQSourceList*)aSourceList badgeValueForItem:(id)item;
- (NSColor*)sourceList:(MQSourceList*)aSourceList badgeTextColorForItem:(id)item;
- (NSColor*)sourceList:(MQSourceList*)aSourceList badgeBackgroundColorForItem:(id)item;

- (BOOL)sourceList:(MQSourceList*)aSourceList itemHasIcon:(id)item;
- (NSImage*)sourceList:(MQSourceList*)aSourceList iconForItem:(id)item;
- (NSImage*)sourceList:(MQSourceList*)aSourceList iconForItemSelected:(id)item;

//The rest of these methods are basically "wrappers" for the NSOutlineViewDataSource methods
- (id)sourceList:(MQSourceList*)aSourceList itemForPersistentObject:(id)object;
- (id)sourceList:(MQSourceList*)aSourceList persistentObjectForItem:(id)item;

- (BOOL)sourceList:(MQSourceList*)aSourceList writeItems:(NSArray *)items toPasteboard:(NSPasteboard *)pboard;
- (NSDragOperation)sourceList:(MQSourceList*)sourceList validateDrop:(id < NSDraggingInfo >)info proposedItem:(id)item proposedChildIndex:(NSInteger)index;
- (BOOL)sourceList:(MQSourceList*)aSourceList acceptDrop:(id < NSDraggingInfo >)info item:(id)item childIndex:(NSInteger)index;
- (NSArray *)sourceList:(MQSourceList*)aSourceList namesOfPromisedFilesDroppedAtDestination:(NSURL *)dropDestination forDraggedItems:(NSArray *)items;

@end
