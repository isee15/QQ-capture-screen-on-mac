//
//  MQToolTips.h
//  MQTest
//
//  Created by zhuochen on 11-11-10.
//  Copyright (c) 2011年 Tencent. All rights reserved.
//

#import <AppKit/AppKit.h>
#import "MQUIKit.h"

@class MQToolTipsWindow;
typedef enum _MQToolTipsPositionType 
{
    MQToolTipsShowLowerRightBelowCursor = 0,                                         //在鼠标右下方显示ToolTips，position决定ToolTips在鼠标下方的相对位置
    MQToolTipsShowLowerLeftBelowCursor,                                              //在鼠标左下方显示ToolTips，position决定ToolTips在鼠标下方的相对位置
    MQToolTipsShowUpperRightAboveCursor,                                             //在鼠标右上方显示ToolTips，position决定ToolTips在鼠标上方的相对位置
    MQToolTipsShowUpperLeftAboveCursor,                                              //在鼠标左上方显示ToolTips，position决定ToolTips在鼠标上方的相对位置
    MQToolTipsShowLowerCenterBelowCursor,                                            //在鼠标正下方显示ToolTips，position决定ToolTips在鼠标下方的相对位置
    MQToolTipsShowUpperCenterAboveCursor,                                            //在鼠标正上方显示ToolTips，position决定ToolTips在鼠标上方的相对位置
    MQToolTipsShowRightCenterBesideCursor,
    MQToolTipsShowLeftCenterBesideCursor,
    MQToolTipsShowInPositionCenter,                                                  //在指定坐标处居中显示ToolTips，非showToolTipsAtPosition模式下，position为ToolTips的中心位置，采用控件坐标系；showToolTipsAtPosition模式下，以用户输入坐标为中心显示，采用屏幕坐标系
    MQToolTipsShowInOwnerLeftCenter,
    MQToolTipsShowInOwnerLeftCorner,
    MQToolTipsShowBelowOwnerCenter,
    MQToolTipsShowUpperOwnerCenter,
} MQToolTipsPositionType;

typedef enum _MQToolTipsRoundCornerType
{
    MQToolTipsRoundCornerNone = 0,                                                   //非圆角矩形
    MQToolTipsRoundCornerPI,                                                         //弧度为PI的圆角矩形
    MQToolTipsRoundCornerPI_2,                                                       //弧度为PI_2的圆角矩形
} MQToolTipsRoundCornerType;

@interface MQToolTips : NSResponder {
    NSTextStorage *_tipsString;
    NSColor *_backgroundColor;
    NSImage *_backgroundImage;
    NSSize _textInset;
    CGFloat _timeDlayShow;
    CGFloat _timeShowDuration;
    MQToolTipsPositionType _positionType;
    NSPoint _position;
    BOOL _autoCornerType;
    MQToolTipsRoundCornerType _cornerType;
    CGFloat _cornerRadius;
    
    NSTrackingArea *_trackArea;
    NSRect _trackRect;
    NSView *_owner;
    BOOL _userShow;
    NSPoint _userShowPosition;
    NSView *_userShowOwner;
    MQToolTipsWindow *_window;
    BOOL _hasShadow;
}

@property (nonatomic, readonly) NSTextStorage *tipsString;    
@property (nonatomic, readonly) NSView *owner;
@property (nonatomic, retain) NSColor *backgroundColor;                             //设置ToolTips的背景颜色，可指定透明度
@property (nonatomic, retain) NSImage *backgroundImage;                             //设置背景图片，背景图不为空就绘制背景图，否则绘制背景色
@property (nonatomic) NSSize textInset;                                             //内容显示的Inset值
@property (nonatomic) CGFloat timeDlayShow;                                         //当鼠标移动到触发区域后，显示ToolTips的延时时间
@property (nonatomic) CGFloat timeShowDuration;                                     //ToolTips显示后持续显示时间，设置0表示一直显示直到鼠标离开触发区域
@property (nonatomic) MQToolTipsPositionType positionType;                          //显示ToolTips的位置类型
@property (nonatomic) NSPoint position;                                             //ToolTips的显示位置，不同的位置类型position的含义不一样（参考相应的位置类型）
@property (nonatomic) BOOL autoCornerType;
@property (nonatomic) MQToolTipsRoundCornerType cornerType;
@property (nonatomic) CGFloat cornerRadius;
@property (nonatomic) BOOL hasShadow;

+ (void) showToolTipsString: (NSAttributedString *) tips atPoint: (NSPoint) posShow withBackColor: (NSColor *) color withPosType: (MQToolTipsPositionType) posType withDeltaPos: (NSPoint) deltaPos roundCorner: (BOOL) round withOwner: (NSView *)owner;
+ (void) showToolTipsString: (NSAttributedString *) tips atPoint: (NSPoint) posShow withBackImage: (NSImage *) image withPosType: (MQToolTipsPositionType) posType withDeltaPos: (NSPoint) deltaPos roundCorner: (BOOL) round withOwner: (NSView *)owner;
+ (void) hideToolTips;

- (BOOL) attachView: (NSView*) dest inRect: (NSRect) rect;
- (void) updateTrackArea: (NSRect) rect;
- (void) detach;

- (void) showToolTipsAtPosition: (NSPoint) pos withOwner: (NSView *)owner;
- (void) showToolTipsWithOwner: (NSView *)owner;
- (void) updateToolTips;
- (void) hideToolTips;

- (void) setToolTipsAttributedString: (NSAttributedString *) tips;
- (void) setToolTipsString: (NSString *) tips;
- (void) setToolTipsString: (NSString *) tips withFont: (NSFont *) font;
- (void) setToolTipsString: (NSString *) tips withFont: (NSFont *) font withColor: (NSColor *) color;

- (NSPoint) calculateWindowFrameOriginByWindowSize: (NSSize) size;
- (NSRect) calculateContentRect;
@end

@interface MQMultipleLinesToolTips : MQToolTips {
    CGFloat _contentWidth;
    NSTextAlignment _textAlign;
}

@property (nonatomic) CGFloat contentWidth;                                         //ToolTips的宽度
@property (nonatomic) NSTextAlignment textAlign;                                    //文本的对其方式
@end

@interface MQRichTextToolTips : MQToolTips {
    NSLayoutManager *_layout;
    NSTextContainer *_container;
    CGFloat _contentWidth;
    NSTextAlignment _textAlign;
    
    NSRect _contentRect;
}

@property (nonatomic) CGFloat contentWidth;                                         //ToolTips的宽度
@property (nonatomic) NSTextAlignment textAlign;                                    //文本的对其方式
@end
