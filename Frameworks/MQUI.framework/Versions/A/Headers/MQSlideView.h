//
//  MQSlideView.h
//  QQ4Mac
//
//  Created by Sampan on 8/20/11.
//  Copyright 2011 tencent. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class MQSlideView;
@class CATransition;

@protocol MQSlideViewDataSource <NSObject>

@required
- (NSInteger)numberOfViewsInSlideView;
- (NSView *)sildeView:(MQSlideView *)slideView viewForIndex:(NSInteger)index;

@end

@protocol MQSlideViewDelegate <NSObject>

@optional
- (void)slideView:(MQSlideView *)slideView didMoveFromIndex:(NSInteger)fromIndex;

@end

@interface MQSlideView : NSView
{
    NSInteger _viewsCount;
    NSInteger curViewIndex;
    BOOL autoRecycle;
    
    BOOL autoPlay;
    BOOL delayAnimation;
    CFTimeInterval timeInterval;
    NSTimer *_timer;
    CGFloat deltaScroll_;
    
    NSView *_curView;
    NSMutableArray *_allViews;
    
    id<MQSlideViewDataSource> dataSource;
    id<MQSlideViewDelegate> delegate;
}

@property (readonly, assign) NSInteger curViewIndex;
@property (readwrite, assign) BOOL autoRecycle;
@property (nonatomic, readwrite, assign) BOOL autoPlay;
@property (nonatomic, readwrite, assign) BOOL delayAnimation;
@property (readwrite, assign) CFTimeInterval timeInterval;
@property (nonatomic, readwrite, assign) id<MQSlideViewDataSource> dataSource;
@property (readwrite, assign) id<MQSlideViewDelegate> delegate;

- (void)reloadAll;

- (void)moveToNext;
- (void)moveToPrevious;
- (void)moveToIndex:(NSInteger)toIndex;
- (void)moveToIndex:(NSInteger)toIndex withAnimation:(CATransition *)animation;
- (NSView *)curView;

@end
