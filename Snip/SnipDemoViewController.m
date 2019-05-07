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
@property (weak) IBOutlet NSImageView *imgView;

@end

@implementation SnipDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
    SwizzleSelectorWithBlock_Begin([[MQSCCaptureWindowManager sharedInstance] class], @selector(captureFinished:))
    ^(MQSCCaptureWindowManager *oriSelf, NSNotification *noti) {
        ((void (*)(id, SEL,NSNotification *))_imp)(oriSelf, _cmd, noti);
        NSLog(@"finishedCapture：%@",noti);
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            NSPasteboard *pasteboard = [NSPasteboard generalPasteboard];
            NSArray *classArray = [NSArray arrayWithObject:[NSImage class]];
            NSDictionary *options = [NSDictionary dictionary];
            BOOL ok = [pasteboard canReadObjectForClasses:classArray options:options];
            if (ok) {
                NSArray *objectsToPaste = [pasteboard readObjectsForClasses:classArray options:options];
                NSImage *image = [objectsToPaste objectAtIndex:0];
                NSLog(@"image:%@",image);
                [self.imgView setImage:image];
            }
        });
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
