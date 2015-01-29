//
//  CScreenshot.h
//  snip
//
//  Created by yan guang on 12-6-20.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "protocolSettingDelegate.h"

enum GrabType {
    OnlyGrabSelection = 0x1,
    OnlyGrabArea = 0x2,
    OnlyGrabWindow = 0x4,
    OnlyGrabWindowAndArea = 0x6,
    GrabWindowAndSelection = 0x7
}; 

extern NSString *QMSavePathChangeNotification;
extern NSString *QMWindowLevelChangeNotification;
extern NSString *QMScreenshotCompleteNotification; //不管截屏还是取消

// CScreenshot，管理截屏的window，每次创建，就启动一次截屏；同一时刻，只能存在一个实例

// CScreenshot非常独立 与 CSetting配置 没联系，除了要保存文件，但是没有指明路径的情况

//内存管理上：
//   自己创建，自己释放
//

@interface CScreenshot : NSObject
{
@private
    enum SaveType _saveType;
    NSString *_savePath; //保存的文件名，包括后缀名，会根据后缀名获取图片类型，如果文件存在，就替换
    NSWindow *_window;
    NSView *_contentView;
    BOOL _sound;
}


// 截屏开始 initWithGrabType，到 setCaptureFinished, release结束
+ (BOOL)isCapturing; //由于一次只能启动一次截屏，查询是否正在截屏
//+ (void)exit; //退出截屏
+ (NSUInteger)getCurrentWindowLevel; //当前窗口的level
+ (enum SaveType)getCurrentSaveType;



+ (BOOL)startScreenshot:(enum GrabType)grabType saveType:(enum SaveType)saveType savePath:(NSString*)savePath sound:(BOOL)sound windowShadow:(BOOL)windowShadow;

//如果当前已经启动，就返回nil；如果不用保存到本地，savePath可以为nil；如果需要保存到本地，而且savePath为nil，那么会弹出选择文件框让用户选择，并发送QMSavePathChangeNotification
//- (id)initWithGrabType:(enum GrabType)grabType saveType:(enum SaveType)saveType savePath:(NSString*)savePath sound:(BOOL)sound windowShadow:(BOOL)windowShadow;



@end



