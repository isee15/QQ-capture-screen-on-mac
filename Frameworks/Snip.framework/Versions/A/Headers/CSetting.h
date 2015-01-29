//
//  CSetting.h
//  snip
//
//  Created by bj l on 12-6-22.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "protocolSettingDelegate.h"

@interface CSetting : NSObject<protocolSettingDelegate>
{
@private
    NSDictionary *_serverInfo;
    
    id<protocolSettingDelegate> _delegate;
}

- (NSString*)getExecutableName;
- (NSString*)getVersion;
- (NSString*)getBuildVersion;
- (BOOL)isFirstRun;
- (BOOL)isAutoStart;
- (long)getLastShowUpdateTimeOffset;

+ (CSetting*)getDefaultInstance;
//+ (void)setDefaultInstance:(CSetting*)setting;

- (id<protocolSettingDelegate>)delegate;
- (void)setDelegate:(id<protocolSettingDelegate>)delegate;


+ (double)getSystemVersion;

@end


@interface CSetting (CSettingSetAction)

- (void)setPlaySound:(BOOL)bPlaySound;
- (void)setAutoStart:(BOOL)bAutoStart;
- (void)setSavePath:(NSString*)savePath;
- (void)setCaptureHotKey:(NSString*)hotkey;
- (void)setSaveType:(enum SaveType)saveType;
- (void)setAutoUpdate:(BOOL)autoUpdate;
- (void)setScrollArea:(BOOL)scrollArea;
//- (void)setInstallPlugin:(BOOL)installPlugin;
- (void)setImageResolution:(long)imageResolution;

@end

extern NSString *QMServerInfomationChangeNotification;

@interface CSetting (CSettingUpdateServerInfomation)

- (NSDictionary*)getServerInfo;
- (void)asyncRequestServerInfo:(BOOL)bForceUpdate;

@end

@interface CSetting (CSettingDefaultSavePath)

//可能为nil，用于第一次打开文件框
+ (NSString*)defaultSaveFile:(NSString*)path;


//判断path是否有权限写入
//如果在非沙盒下，返回TRUE
//如果在沙盒下，如果不是Downloads， Pictures目录，返回NO，否则就是YES，并且给出legacyPath，sandboxPath
//~/Downloads, ~/Pictures legacyPath
//~/Library/Containers/com.tencent.snip/Data/Downloads, ~/Library/Containers/com.tencent.snip/Data/Pictures sanboxPath
+ (BOOL)analysePath:(NSString*)path legacyPath:(NSString**)legacyPath sandboxPath:(NSString**)sandboxPath;

@end



