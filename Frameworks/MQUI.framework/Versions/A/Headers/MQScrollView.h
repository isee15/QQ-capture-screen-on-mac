//
//  MQScrollView.h
//  MacQQ
//
//  Created by zhuochen on 12-8-24.
//  Copyright (c) 2012年 Tencnet. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MQLayerView.h"

enum {
    MQHorizontalScroller = 0,
    MQVerticalScroller = 1
};
typedef NSUInteger MQScrollerMode;

@class MQScrollView;
@interface MQScroller : MQLayerView {
    MQScrollView *_parent;
    NSUInteger _knobSize;
    MQScrollerMode _mode;
    NSRect _knobRect;
    void *_info;
    
    BOOL _canShow;
    BOOL _isDragging;
    NSPoint _ptDrag;
    NSTrackingArea *_mouseTrack;
}
- (id) initwithKnobSize: (NSUInteger) knobSize;

@property (nonatomic, readonly) NSUInteger knobSize;
@property (nonatomic, readonly) MQScrollerMode mode;
@end

@interface MQScrollView : NSScrollView {
    MQScroller *_scrollerH;
    MQScroller *_scrollerV;
    BOOL _isScrolling;
    BOOL _disableScroller;
}

- (void) setCustomHorizontalScroller: (MQScroller *) scroller;
- (void) setCustomVerticalScroller: (MQScroller *) scroller;
- (void) disableCustomScroller: (BOOL) disable;
- (void) scrollBy: (NSSize) delta;
- (void) scrollToPoint: (NSPoint) point;
@end
