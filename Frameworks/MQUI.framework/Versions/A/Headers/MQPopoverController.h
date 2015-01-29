//
//  MQPopoverController.h
//
//  Created by Sampan on 10/21/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    MQPopoverArrowDirectionLeft         = NSMinXEdge,   //箭头向左
    MQPopoverArrowDirectionDown         = NSMinYEdge,   //箭头向下
    MQPopoverArrowDirectionRight        = NSMaxXEdge,   //箭头向右
    MQPopoverArrowDirectionUp           = NSMaxYEdge,   //箭头向上
    MQPopoverArrowDirectionLeftTop      = 4,            //箭头向左，且在上端
    MQPopoverArrowDirectionLeftBottom   = 5,            //箭头向左，且在下端
    MQPopoverArrowDirectionRightTop     = 6,            //箭头向右，且在上端
    MQPopoverArrowDirectionRightBottom  = 7,            //箭头向右，且在下端
    MQPopoverArrowDirectionUpLeft       = 8,            //箭头向上，且在左边
    MQPopoverArrowDirectionUpRight      = 9,            //箭头向上，且在右边
    MQPopoverArrowDirectionDownLeft     = 10,           //箭头向下，且在左边
    MQPopoverArrowDirectionDownRight    = 11            //箭头向下，且在右边
}MQPopoverArrowDirection;

typedef enum {
    MQPopoverDefaultStyle = 1, //默认风格
    MQPopoverCustomStyle = 2,   //自定义风格，由viewController完全控制
    MQPopoverNonactivatingStyle = 0x100, //点击面板是否激活程序
}MQPopoverStyle;

typedef enum {
    MQPopoverNoneAnimationStyle             = 0,    //无动画效果
    MQPopoverCustomAnimationStyle           = 1,    //用户自定义动画
    MQPopoverAlphaAnimationStyle            = 2,    //alpha渐变动画
    MQPopoverAlphaTransformAnimationStyle   = 3,    //alpha渐变加放大缩小动画
}MQPopoverAnimationStyle;


@protocol MQPopoverControllerDelegate;
@class MQPopoverWindow;

@interface MQPopoverController : NSObject {
    id<MQPopoverControllerDelegate> _delegate;
    NSSize _contentSize;
    BOOL _closesWhenPopoverResignsKey;
    BOOL _closesWhenApplicationBecomesInactive;
    BOOL _asChildWindow;
    BOOL _nonactiveApp;
    
    NSViewController *_contentViewController;
    
    MQPopoverWindow *_popoverWindow;
    NSView *_positionView;
    NSPoint _screenPoint;
    NSPoint _viewPoint;
    NSRect _positionRect;
    
    //鼠标事件监听
    id _eventMonitor;
    
    //动画效果处理
    MQPopoverAnimationStyle _animationStyle;
    CAAnimation *_showAnimation;
    CAAnimation *_closeAnimation;
    NSRect _originalWidowFrame;
    NSView *_oldContentView;
    NSImageView *_animationView;
    
    float alphaTransformAnimationStyleDuration;
}

#pragma mark -
#pragma mark Properties
/** MQPopoverAlphaTransformAnimationStyle 动画的持续时间 **/
@property (nonatomic, assign) float alphaTransformAnimationStyleDuration;

/** The delegate of the MQPopoverController object (should conform to the MQPopoverControllerDelegate protocol) */
@property (nonatomic, assign) id<MQPopoverControllerDelegate> delegate;

/** 设置popover的背景色 */
@property (nonatomic, retain) NSColor *backgroundColor;

/** 设置border的颜色 */
@property (nonatomic, retain) NSColor *borderColor;

/** 设置border的宽度 */
@property (nonatomic) CGFloat borderWidth;

/** 设置popover箭头的默认值 @see MQPopoverArrowDirection */
@property (readonly) MQPopoverArrowDirection arrowDirection;

/** popover内容区域（通常就是viewController指向的view的size），通常会在设置了viewController之后自动计算，也可以手动指定. */
@property (nonatomic, assign) NSSize contentSize;

/** 设置是否在popover失去焦点时自动关闭. 默认为YES */
@property (nonatomic, assign) BOOL closesWhenPopoverResignsKey;

/** 设置是否在程序切换至后台的时候自动关闭popover. 默认为NO */
@property (nonatomic, assign) BOOL closesWhenApplicationBecomesInactive;

/** popover内容区域的viewController */
@property (nonatomic, assign) NSViewController *contentViewController;

/** popover所依附的view，如果没有popover则返回nil */
@property (readonly) NSView *positionView;

/** 设置箭头四边位置的范围，默认就是positionview的bounds */
@property (nonatomic, assign) NSRect positionRect;

/** popover的内部window */
@property (readonly) NSWindow *popoverWindow;

/** 返回popover是否显示 */
@property (readonly) BOOL popoverIsVisible;

/** 返回经过自动调整后箭头位置的偏移 */
@property (nonatomic, assign) NSPoint arrowOffsetPoint;

/** 设置popover window中border与contentview的距离 */
@property (nonatomic, assign) CGFloat viewMargin;

/** 设置是否显示箭头 */
@property (nonatomic, assign) BOOL drawsArrow;

/** 设置箭头与positionView的距离 */
@property (nonatomic, assign) CGFloat distance;

/** 设置是否让箭头占据四个角的圆角的位置 */
@property (nonatomic, assign) BOOL drawRoundCornerBesideArrow;

/** 设置四个圆角的弧度 */
@property (nonatomic, assign) CGFloat cornerRadius;

/** 设置箭头的底部宽度 */
@property (nonatomic, assign) CGFloat arrowWidth;

/** 设置箭头的高度 */
@property (nonatomic, assign) CGFloat arrowHeight;

/** 设置动画类型 */
@property (nonatomic, assign) MQPopoverAnimationStyle animationStyle;

/** 设置展示动画 */
@property (nonatomic, retain) CAAnimation *showAnimation;

/** 设置关闭动画 */
@property (nonatomic, retain) CAAnimation *closeAnimation;

#pragma mark -
#pragma mark Methods

/**
 初始化popovercontroller，注意这里的viewController应该已经设置了contentView.
 @param viewController the content view controller 
 @param useCustomeFrameView 是否使用自定义Frameview，是则popover不会去绘制边框和背景色，完全由viewController控制，同时忽略默认样式的宏；否则使用默认的样式.
 @returns a new instance of MQPopoverController
 */
- (id)initWithContentViewController:(NSViewController*)viewController useStyle:(MQPopoverStyle)popoverStyle;

/**
 弹出popover window.
 @param point 箭头的默认顶点坐标，基于positionview的坐标系
 @param positionView popover依附的positionview
 @param direction 默认的箭头方向，如果允许选择最佳显示位置，代码会重新计算箭头的方向.
 */
- (void)showPopoverAtPoint:(NSPoint)point inView:(NSView*)positionView preferredArrowDirection:(MQPopoverArrowDirection)direction;

/**
 弹出popover window.
 @param point 箭头的默认顶点坐标，基于positionview的坐标系
 @param positionView popover依附的positionview
 @param direction 默认的箭头方向，如果允许选择最佳显示位置，代码会重新计算箭头的方向.
 @param anchors 设置是否popover window是否跟随positionview的位置改变而动.
 @param asChildWindow 设置是否将popover window添加为positionview的window的子window；诸如系统statusbar之类的地方不应该设为子window，否则会出现在mission control中.
 @param chooseBestPosition 设置是否自动计算最佳显示位置
 */
- (void)showPopoverAtPoint:(NSPoint)point inView:(NSView*)positionView preferredArrowDirection:(MQPopoverArrowDirection)direction anchorsToPositionView:(BOOL)anchors asChildWindow:(BOOL)asChildWindow chooseBestPosition:(BOOL)autoChoose;

/**
 刷新content view，外部谨慎调用此方法.
 */
- (void)refreshContentView;

/** 
 根据屏幕坐标选择最佳的显示位置和箭头方向，修改的偏移量在arrowOffsetPoint中纪录。
 */
- (void)recalculateAndResetArrowDirection;

/**
 关闭popover，除非 -popoverShouldClose: 委托返回NO 
 @param sender the object that sent this message
 */
- (IBAction)closePopover:(id)sender;

/**
 最终真正关闭popover的代码
 @param sender the object that sent this message
 */
- (IBAction)forceClosePopover:(id)sender;

/**
 设置popoverwindow是否能成为keywindow
 **/
- (void)setCanBecomeKeyWindow:(BOOL)bFlag;
@end

@protocol MQPopoverControllerDelegate <NSObject>
@optional
/**
 回调是否允许关闭popover window.
 @param popover @class MQPopoverController对象
 @returns YES关闭，NO阻止popover关闭
 */
- (BOOL)popoverShouldClose:(MQPopoverController*)popover;

/**
 在弹出popover window前触发回调
 @param popover @class MQPopoverController对象
 */
- (void)popoverWillShow:(MQPopoverController*)popover;

/**
 在弹出popover window后触发回调（动画结束后）
 @param popover @class MQPopoverController对象
 */
- (void)popoverDidShow:(MQPopoverController*)popover;

/**
 在popover window关闭前触发回调
 @param popover @class MQPopoverController对象
 */
- (void)popoverWillClose:(MQPopoverController*)popover;

/**
 在popover window关闭前触发回调（动画结束后）
 @param popover @class MQPopoverController对象
 */
- (void)popoverDidClose:(MQPopoverController*)popover;

/**
 在重新计算箭头方向后触发回调
 @param popover @class MQPopoverController对象
 @param fromDirection 之前的箭头方向（传入的默认方向）
 @param toDirection 修正最佳显示后的箭头方向
 */
- (void)popover:(MQPopoverController *)popover arrowDirectionWillChangedFrom:(MQPopoverArrowDirection)fromDirection toDirection:(MQPopoverArrowDirection)toDirection;

/**
 在重新计算箭头位置后触发回调
 @param popover @class MQPopoverController对象
 @param offset 新箭头位置相对于默认位置的偏移
 */
- (void)popover:(MQPopoverController *)popover arrowOffsetDidChanged:(NSPoint)offset;

/**
 确定了popover的弹出位置后，在显示popoverwindow之前，如果需要动画触发回调
 @param popover @class MQPopoverController对象
 */
- (void)popoverPrepareShowAnimates:(MQPopoverController *)popover;

/**
 在popoverwindow显示时开始动画
 @param popover @class MQPopoverController对象
 */
- (void)popoverStartShowAnimates:(MQPopoverController *)popover;

/**
 在关闭popover之前，如果需要动画触发回调
 @param popover @class MQPopoverController对象
 */
- (void)popoverPrepareCloseAnimates:(MQPopoverController *)popover;

/**
 在popover关闭时开始动画
 @param popover @class MQPopoverController对象
 */
- (void)popoverStartCloseAnimates:(MQPopoverController *)popover;

/**
 popover的keyDown事件处理
 @param theEvent KeyDown事件
 */
- (void)popoverKeyDown:(NSEvent *)theEvent;

@end
