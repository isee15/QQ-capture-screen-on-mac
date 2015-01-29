//
//  MQTableView.h
//  MacQQ
//
//  Created by zhuochen on 12-8-28.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MQTableViewCell.h"
#import "MQTableViewLayoutMgr.h"

@protocol MQTableViewDatasource;

@interface MQTableView : MQLayerView
{
    id<MQTableViewDatasource> _datasource;
    NSUInteger _numberOfRows;
    MQTableViewLayoutMgr *_layoutMgr;
    
    NSInteger _selIndex;
    MQTableViewCell *_draggingCell;
}

@property(nonatomic, assign) id<MQTableViewDatasource> datasource;
@property(nonatomic, retain) MQTableViewLayoutMgr *layoutMgr;
@property(nonatomic, assign) NSInteger selIndex;

//重新加载所有数据
- (void)reloadData;
- (void)sortCells;
- (MQTableViewCell *) cellForEvent: (NSEvent *) theEvent;
- (MQTableViewCell *) cellForPoint: (NSPoint) point;
- (void) updateSelectedCell: (BOOL) selected;

@end

@protocol MQTableViewDatasource <NSObject>

- (NSInteger)numberOfRows:(MQTableView *)tableView;
- (MQTableViewCell *)tableView:(MQTableView *)tableView cellForRowAtIndex:(NSUInteger) index;

@end