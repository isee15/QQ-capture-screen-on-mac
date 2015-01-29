//
//  MQTableViewCell.h
//  MacQQ
//
//  Created by zhuochen on 12-8-28.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MQLayerView.h"

@class MQTableViewLayoutMgr;
@interface MQTableViewCell : MQLayerView
{
    MQTableViewLayoutMgr *_layoutMgr;
    BOOL _selected;
    NSInteger _index;
    
    NSImage *_icon;
}

@property (nonatomic, readonly) MQTableViewLayoutMgr *layoutMgr;
@property (nonatomic, assign) BOOL selected;
@property (nonatomic, readonly) NSInteger index;
@property (nonatomic, retain) NSImage *icon;

- (id) initWithLayoutManager: (MQTableViewLayoutMgr *) layoutMgr;
- (void) update;
- (void) updateSelected;
- (void) setCellIndex: (NSInteger) index;
@end
