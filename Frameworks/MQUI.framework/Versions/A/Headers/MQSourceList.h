//
//  MQSourceList.h
//  MQSourceList
//  QQ4Mac
//
//  Created by Hugoyao on 11-12-10.
//  Copyright 2011年 tencent. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "MQSourceListDelegate.h"
#import "MQSourceListDataSource.h"

#ifndef MAC_OS_X_VERSION_10_6
@protocol NSOutlineViewDelegate <NSObject> @end
@protocol NSOutlineViewDataSource <NSObject> @end
#endif

@interface MQSourceList: NSOutlineView <NSOutlineViewDelegate, NSOutlineViewDataSource>
{
	id <MQSourceListDelegate> _secondaryDelegate;		//Used to store the publicly visible delegate
	id <MQSourceListDataSource> _secondaryDataSource;	//Used to store the publicly visible data source
	
	NSSize _iconSize;									//The size of icons in the Source List. Defaults to 16x16
}
	
@property (nonatomic, assign) NSSize iconSize;
	
@property (assign) id<MQSourceListDataSource> dataSource;
@property (assign) id<MQSourceListDelegate> delegate;

- (NSUInteger)numberOfGroups;							//Returns the number of groups in the Source List
- (BOOL)isGroupItem:(id)item;							//Returns whether `item` is a group
- (BOOL)isGroupAlwaysExpanded:(id)group;				//Returns whether `group` is displayed as always expanded

- (BOOL)itemHasBadge:(id)item;							//Returns whether `item` has a badge
- (NSInteger)badgeValueForItem:(id)item;				//Returns the badge value for `item`

@end

