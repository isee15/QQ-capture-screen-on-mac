//
//  MQDragManager.h
//  MQUI
//
//  Created by Qiyu Tan on 10/26/11.
//  Copyright (c) 2011 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MQDragWindow;

@interface MQDragManager : NSObject
{
    NSWindow *_oldWindow;
    NSWindow *_draggingWindow;
    NSImage *_draggingImage;
    NSPoint _startPoint;
    NSPoint _startOrigin;
}

+ (id)sharedInstance;

@property(nonatomic, readonly) NSImage *dragImage;

//开始拖动操作
//@image 拖动缩略图
//@point 鼠标所在点
//@offset 缩略图左上角与鼠标间的距离
- (void)startDragWithImage:(NSImage*)image atPoint:(NSPoint)point imageOffset:(NSPoint)offset;

//更新鼠标位置
- (void)moveToPoint:(NSPoint)point;

//在拖动过程中更换缩略图
- (NSImage*)replaceDragImage:(NSImage*)image animated:(BOOL)animated;

//结束拖动
- (void)endDrag;

@end
