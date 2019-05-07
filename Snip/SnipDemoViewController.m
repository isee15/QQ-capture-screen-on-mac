//
//  SnipDemoViewController.m
//  Snip
//
//  Created by isee15 on 15/1/29.
//  Copyright (c) 2015年 isee15. All rights reserved.
//

#import "SnipDemoViewController.h"
#import "Snip/CScreenshot.h"
#import "MQUI/MQSCCaptureWindowManager.h"
#import "HookUtil.h"

@interface SnipDemoViewController ()

@end

@implementation SnipDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
    SwizzleSelectorWithBlock_Begin([[MQSCCaptureWindowManager sharedInstance] class], @selector(captureFinished:))
    ^(MQSCCaptureWindowManager *oriSelf, NSNotification *noti) {
        ((void (*)(id, SEL,NSNotification *))_imp)(oriSelf, _cmd, noti);
        NSLog(@"finishedCapture：%@",noti);
    }
    SwizzleSelectorWithBlock_End;
}
- (IBAction)onStart:(id)sender {
    if (![CScreenshot isCapturing]) {
        //startScreenshot:(enum GrabType)grabType saveType:(enum SaveType)saveType savePath:(NSString*)savePath sound:(BOOL)sound windowShadow:(BOOL)windowShadow;
        //[CScreenshot startScreenshot:GrabWindowAndSelection saveType:SAVE_TO_CLIPBOARD savePath:nil sound:YES windowShadow:NO];
        [[MQSCCaptureWindowManager sharedInstance] startCapture:nil];
    }
}

@end
