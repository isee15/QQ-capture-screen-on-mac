//
//  MQSCCaptureWindowController.h
//  TXScreenShot
//
//  Created by noblechen on 12-4-5.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

extern NSString *kSCShowToolKitNotification;
extern NSString *kSCHideToolKitNotification;
extern NSString *kSCCaptureFinishedNotification;
extern NSString *kSCCaptureSaveNotification;
extern NSString *kSCCaptureCancelNotification;
extern NSString *kSCCaptureGrabAreaChangeNotification;

extern NSString *kSCCaptureImageType;
extern NSString *kSCCaptureIsNeedDecrease;
extern NSString *kSCCaptureCaller;
extern NSString *KSCCaptureFileDir;
extern NSString *kSCCaptureIsSoundClose;

@class MQSCToolKitWindowController;
@interface MQSCCaptureWindowController : NSWindowController<NSWindowDelegate>
{
    MQSCToolKitWindowController *_toolKitWindowController;
    NSRect _grabArea;
    BOOL _isWorking;
    BOOL _isNotTellDelegate;
    id _caller;
    NSUInteger _nameCount;
    NSUInteger _tempNameCount;
    NSUInteger _saveNameCount;
    NSUInteger _tempNameCountResolution;
    NSUInteger _savenameCountResolution;
    NSPoint _tookKitWindowOrigin;
    
    NSString *_saveFileDir;
    NSBitmapImageFileType _saveImageType;
    BOOL _isNeedDecrease;
    BOOL _isSoundClose;
    
    NSScreen *_screen;
    NSRect _screenFrame;
    
    BOOL _isMouseDraggedEnterWindow;
    BOOL _isMouseDragged;
    BOOL _isShowToolKit;
    
    BOOL _isMultiScreen;
    
    NSUInteger screenNumber;
}

@property(nonatomic, retain) NSString *saveFileDir;
@property(nonatomic, assign) NSBitmapImageFileType saveImageType;

@property(nonatomic, retain) MQSCToolKitWindowController *toolkitWindowController;
@property(nonatomic, retain) NSScreen *screen;
@property(nonatomic, assign) BOOL isMouseDragged;
@property(nonatomic, assign) BOOL isMouseDraggedEnterWindow;
@property(nonatomic, assign) BOOL isShowToolKit;
@property(nonatomic, assign) BOOL isMultiScreen;
@property(nonatomic, assign) BOOL isWorking;
@property(nonatomic, assign) NSRect screenFrame;

+ (id)sharedInstance;
- (void)startCapture:(NSDictionary*)attri;
- (void)startCapture:(NSDictionary *)attri withScreen:(NSScreen *)screen;

- (void)showToolKit:(NSNotification*)nc;
- (void)hideToolKit:(NSNotification*)nc;

- (void)captureFinished;
- (void)captureFinished:(NSNotification*)nc;

- (void)captureCancel;
- (void)captureCancel:(NSNotification*)nc;

- (void)captureSave:(NSNotification*)nc; 
- (void)caputreSave;

- (void)grabAreaChange:(NSNotification*)nc;

- (NSString*) fileFullPath:(NSString*)path withType:(NSBitmapImageFileType)type;

- (BOOL)saveImageToFile:(NSDictionary*)dic;

- (BOOL)isScreenCaptureWorking;

- (void)writeToPasteboard:(NSData*)imageData;

- (NSImage*)readGrabAreaImage;
@end

//for Delegate
@interface NSObject (MQSCCaptureWindowController)
- (void)grabDidFinishSaveAs:(NSData*)imageData;
- (void)grabDidFinish;
@end