//
//  MQSCCaptureWindowManager.h
//  MQUI
//
//  Created by Strong on 13-11-13.
//
//

#import <Foundation/Foundation.h>
#import "MQSCCaptureWindowController.h"

@interface MQSCCaptureWindowManager : NSObject
{
    NSMutableArray *_windowControllerArray;
}

+(id)sharedInstance;

- (void)cleanController;

- (void)startCapture:(NSDictionary *)attri;

- (void)showToolKit:(NSNotification*)nc;
- (void)hideToolKit:(NSNotification*)nc;

- (void)captureFinished:(NSNotification*)nc;

- (void)captureSave:(NSNotification*)nc;

- (void)grabAreaChange:(NSNotification*)nc;

- (void)captureCrossScreen:(NSNotification *)nc;

@end
