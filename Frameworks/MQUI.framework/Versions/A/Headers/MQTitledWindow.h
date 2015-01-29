//
//  MQTitledWindow.h
//  MQTest
//
//  Created by zhuochen on 11-11-3.
//  Copyright (c) 2011年 Tencent. All rights reserved.
//

#import <AppKit/AppKit.h>

//自定义拖动条
@interface MQCustomSplit : NSSplitView {
    NSImage *_imgSpliter;
    NSImage *_imgThumber;
    NSRect _spliterRect;
}

@property (nonatomic, retain) NSImage *imgSpliter;                      //拖动条背景图，可拉伸适应宽度或高度（由拖动条的类型决定，水平条拉伸宽度，垂直条拉伸高度）
@property (nonatomic, retain) NSImage *imgThumber;                      //拖动条拉手图，居中显示在背景图上

//为了响应双击splider拖动条事件，splider的delegte需要实现
//- (void) spliderViewReceivedDoubleClicked: (NSSplitView *)splitView;
//程序会自动检测代理是否实现了这个方法并加以调用
@end

//自定义TitleBar，可作为容器，可往里面添加任意控件
@interface MQCustomTitle : NSView {
    NSArray *_gradientColor;
    NSArray *_imgBackground;
}

@property (nonatomic, retain) NSArray *gradientColor;                   //Title渐变色设置，默认和系统的一致，分为两组（数字代表索引）：Active状态（0=渐变起始色，1=渐变终止色，2=边线色）；Inactive状态（3=渐变起始色，4=渐变终止色，5=边线色）
@property (nonatomic, retain) NSArray *imgBackground;                   //设置Title的背景图片，可拉伸；背景图为空时显示渐变Title

- (void) drawGradientTitle: (BOOL) actived inRect: (NSRect) rect;
- (void) drawImageBackgroundTitle: (BOOL) actived inRect: (NSRect) rect;
- (void) drawBottomBorderLine: (BOOL) actived inRect: (NSRect) rect;
@end

//自定义窗体，需要配合自定义TitleBar一起使用
@interface MQTitledWindow : NSWindow {
    MQCustomTitle *_windowTitle;
    BOOL _fullScreenSupported;
    CGFloat _windowTitleHeight;
    CGFloat _sysTitleHeight;
    
    NSColor *_backColor;
    NSUInteger _wndMask;
    NSImageView *_imgCover;
    NSView *_content;
    NSSize _sizeShrink;
    
    NSImage *_screenShot;
    BOOL _isAnimating;
    BOOL _isImageMode;
    NSRect _orgFrame;
    NSPoint _orgPosition;
    NSInteger _orgLevel;
}

@property (nonatomic, retain) IBOutlet MQCustomTitle *windowTitle;
@property (nonatomic) BOOL fullScreenSupported;                         //是否启用全屏功能，10.7以下设置无效
@property (nonatomic, readonly) BOOL isAnimating;
@property (nonatomic, readonly) BOOL isImageMode;

- (NSImage *) captureWindowScreenShot: (NSSize) imgSize;                //AutoReleased

- (BOOL) shrinkWindowTo: (NSSize) size alphaValue: (CGFloat) alpha animate: (BOOL) animate;
- (BOOL) expandWindowToOriginalFrame: (NSRect) frame withPosition: (NSPoint) position level: (NSInteger) level adjustVisible: (BOOL) adjust animate: (BOOL) animate;
- (BOOL) changeWindowCoverImageTo: (NSImage*) newImage withSize: (NSSize) size;
@end
