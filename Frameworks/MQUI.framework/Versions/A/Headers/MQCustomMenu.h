//
//  MQCustomMenu.h
//  CustomMenu
//
//  Created by zhuo chen on 12-3-15.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <AppKit/AppKit.h>
@class  MQCustomMenuView;

@interface MQCustomMenuItem : NSView {
    NSInteger _index;
    BOOL _hilighted;
    BOOL _dummy;
    NSTrackingArea *_mouseTrack;
    SEL _action;
    SEL _insertNewlineAction;
    id _target;
}

@property (nonatomic, assign) NSInteger index;
@property (nonatomic, assign) BOOL hilighted;
@property (nonatomic, assign) BOOL dummy;
@property (nonatomic, assign) SEL action;
@property (nonatomic, assign) SEL insertNewlineAction;
@property (nonatomic, assign) id target;

- (id) initItemWithSize: (NSSize) size;
@end

@protocol MQCustomMenuDelegate;

@interface MQCustomMenu : NSPanel {
    NSObject<MQCustomMenuDelegate> *_menuDelegate;
    NSWindow *_parent;
    MQCustomMenuView *_contentMenuView;
    BOOL isShonwing;
}
@property (nonatomic, assign) NSObject<MQCustomMenuDelegate> *menuDelegate;
@property (nonatomic, retain) NSColor *backColor;
@property (nonatomic, retain) NSColor *selColor;
@property (nonatomic, retain) NSColor *borderColor;
@property (nonatomic, assign) float borderWidth;
@property (nonatomic, assign) BOOL isAllRoundConer;

- (void) showMenuInWindow: (NSWindow*) parent location: (NSPoint) pos;
- (void) hideMenu;
- (void) reloadAllItem;
- (void) hilightItemMoveUp;
- (void) hilightItemMoveDown;
- (void) performActionOnHilightItem;
- (BOOL) isShowing;
@end

@protocol MQCustomMenuDelegate <NSObject>

- (NSUInteger) itemCountOfMenu: (MQCustomMenu *) menu;
- (MQCustomMenuItem *) itemOfMenu: (MQCustomMenu *) menu atIndex: (NSInteger) index;

@end