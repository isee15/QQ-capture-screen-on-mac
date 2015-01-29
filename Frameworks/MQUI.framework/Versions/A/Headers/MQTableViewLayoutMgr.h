//
//  MQTableViewLayoutMgr.h
//  MacQQ
//
//  Created by zhuochen on 12-8-29.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MQTableViewCell;
@class MQTableView;
@interface MQTableViewLayoutMgr : NSObject
{
    MQTableView *_tableView;
    NSUInteger _rowHeight;
    NSUInteger _leftGap;
    NSUInteger _topGap;
    MQTableViewLayoutMgr *_relation;
    MQTableViewCell *_dummyCell;
    BOOL _disableRelation;
}

@property (nonatomic, assign) MQTableView *tableView;
@property (nonatomic, assign) NSUInteger rowHeight;
@property (nonatomic, assign) NSUInteger leftGap;
@property (nonatomic, assign) NSUInteger topGap;
@property (nonatomic, assign) MQTableViewLayoutMgr *relation;

- (NSUInteger) minVisibleHeight;
- (NSRect) cellRectAtIndex: (NSUInteger) index;
- (void) disableRelation: (BOOL) disable;

- (void) beginAddTableViewCell: (NSUInteger) total;
- (void) addTableViewCell: (MQTableViewCell *) cell;
- (void) endAddTableViewCell;

- (BOOL) insertCell: (MQTableViewCell *) cell atIndex: (NSUInteger) index completionBlock:(void (^)(void))block;
- (BOOL) moveCellFrom: (NSUInteger) fromIndex to: (NSUInteger) toIndex completionBlock:(void (^)(void))block;
- (BOOL) deleteCellAtIndex: (NSUInteger) index completionBlock:(void (^)(void))block;

- (BOOL) insertDummyCell: (MQTableViewCell *) cell atIndex: (NSUInteger) index completionBlock:(void (^)(void))block;
- (BOOL) realizeDummyCellWithCompletionBlock:(void (^)(void))block;
- (BOOL) cancelDummyCellWithCompletionBlock:(void (^)(void))block;
@end
