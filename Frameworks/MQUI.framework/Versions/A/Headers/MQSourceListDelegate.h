//
//  MQSourceListDelegate.h
//  QQ4Mac
//
//  Created by Hugoyao on 11-12-10.
//  Copyright 2011年 tencent. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class MQSourceList;

@protocol MQSourceListDelegate <NSObject>

@optional
//Extra methods
- (BOOL)sourceList:(MQSourceList*)aSourceList isGroupAlwaysExpanded:(id)group;
- (NSMenu*)sourceList:(MQSourceList*)aSourceList menuForEvent:(NSEvent*)theEvent item:(id)item;

//Basically NSOutlineViewDelegate wrapper methods
- (BOOL)sourceList:(MQSourceList*)aSourceList shouldSelectItem:(id)item;
- (NSIndexSet*)sourceList:(MQSourceList*)aSourceList selectionIndexesForProposedSelection:(NSIndexSet *)proposedSelectionIndexes;

- (BOOL)sourceList:(MQSourceList*)aSourceList shouldEditItem:(id)item;

- (BOOL)sourceList:(MQSourceList*)aSourceList shouldTrackCell:(NSCell *)cell forItem:(id)item;

- (BOOL)sourceList:(MQSourceList*)aSourceList shouldExpandItem:(id)item;
- (BOOL)sourceList:(MQSourceList*)aSourceList shouldCollapseItem:(id)item;

- (CGFloat)sourceList:(MQSourceList*)aSourceList heightOfRowByItem:(id)item;

- (NSCell*)sourceList:(MQSourceList*)aSourceList willDisplayCell:(id)cell forItem:(id)item;
- (NSCell*)sourceList:(MQSourceList*)aSourceList dataCellForItem:(id)item;

@end

@interface NSObject (MQSourceListNotifications)

//Selection
- (void)sourceListSelectionIsChanging:(NSNotification *)notification;
- (void)sourceListSelectionDidChange:(NSNotification *)notification;

//Item expanding/collapsing
- (void)sourceListItemWillExpand:(NSNotification *)notification;
- (void)sourceListItemDidExpand:(NSNotification *)notification;
- (void)sourceListItemWillCollapse:(NSNotification *)notification;
- (void)sourceListItemDidCollapse:(NSNotification *)notification;

- (void)sourceListDeleteKeyPressedOnRows:(NSNotification *)notification;


@end

//MQSourceList delegate notifications
extern NSString * const MQSLSelectionIsChangingNotification;
extern NSString * const MQSLSelectionDidChangeNotification;
extern NSString * const MQSLItemWillExpandNotification;
extern NSString * const MQSLItemDidExpandNotification;
extern NSString * const MQSLItemWillCollapseNotification;
extern NSString * const MQSLItemDidCollapseNotification;
extern NSString * const MQSLDeleteKeyPressedOnRowsNotification;

