//
//  MQPull2RefreshScrollView.h
//  QQ4Mac
//
//  Created by Hugoyao on 12-03-09.
//  Copyright (c) 2011年 tencent. All rights reserved.

#import <AppKit/AppKit.h>

@protocol MQPull2RefreshDelegate <NSObject>

@optional
- (void)startLoading:(NSScrollView *)scrollView;
- (void)stopLoading:(NSScrollView *)scrollView;
- (void)viewBoundDidChange:(NSScrollView *)scrollView;

@end

@interface MQPull2RefreshScrollView : NSScrollView {
	BOOL isRefreshing;
    BOOL isRefreshingInLegacy; //滚轮鼠标也为其设置一个标志位，表示是否正在更新
    BOOL isEnd;
	
	NSView *_headerView;
    CGFloat _minimumScroll;
    
    id<MQPull2RefreshDelegate> _delegate;
    NSInteger curScrollerStyle;
}

@property (assign) id<MQPull2RefreshDelegate> delegate;
@property (assign) CGFloat minimumScroll;
@property (readonly) BOOL isRefreshing;
@property (readonly) BOOL isRefreshingInLegacy;

- (void)startLoading;
- (void)stopLoading;
- (CGFloat)headerHeight;

- (BOOL)overRefreshView;
- (void)createHeaderView:(NSView *)headerView;
- (void)viewBoundsChanged:(NSNotification*)notification;

@end
