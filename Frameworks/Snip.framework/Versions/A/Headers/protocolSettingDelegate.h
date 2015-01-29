//
//  protocolSettingDelegate.h
//  snip
//
//  Created by bj l on 12-6-22.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

enum SaveType
{
    SAVE_NONE = 0,
    SAVE_TO_FILE = 0x1,
    SAVE_TO_CLIPBOARD = 0x2,
    SAVE_TO_FILE_AND_CLIPBOARD = 0x3
};

enum EditionType
{
    EDITION_NORMAIL = 0,
EDITION_APPSTORE = 1
};

//Setting
//  默认是从~/Library/Preferences/com.tencent.snip.plist 读取
//  提供委托，让用户自定义

@protocol protocolSettingDelegate <NSObject>

@optional
- (enum SaveType)getSaveType;
- (NSString*)getSavePath;//可能为nil，用于第一次打开文件框
- (NSString*)getCaptureHotKey;
- (BOOL)isPlaySound;
- (BOOL)isAutoUpdate;
- (BOOL)isScrollArea;
- (NSBitmapImageFileType)getSaveImageFileType;
- (BOOL)isSupportOptionToChangeSaveType;
- (long)imageResolution; //0(default) 保存为屏幕相同的大小  或  1(standard)，强制retina保存为1x 或 2(retina)，一般没有2

- (NSInteger)getEdition; //是 appstore版本 代号为1，是 大众版，代号为0，还是自定义版本

#pragma mark 邮箱分享
//如果不支持，继承并在isSupportQQMail返回NO
- (NSString*)getQQMailLoginCGIHost; //用于绑定QQ邮箱，通过手机app的域名
- (NSString*)getQQMailWebCGIHost; //用于发信
- (BOOL)isSupportQQMail; //是否支持QQ邮箱分享



@end
