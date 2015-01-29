//
//  MQSwitchButton.h
//  QQ4Mac
//
//  Created by qiaowu on 12-9-20.
//  Copyright (c) 2012年 tencent. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Quartz/Quartz.h>

typedef enum {
    MQSwitchButtonOff = 0,
    MQSwitchButtonOn = 1,
} MQSwitchButtonState;

@protocol MQSwitchButtonDelegate <NSObject>
//状态改变时调
- (void)onChangeState:(MQSwitchButtonState)newState;
//点击按钮后调
- (void)onClickSwitchButton:(id)sender;
@end

@interface MQSwitchButton : NSView
{
    CALayer *_bgLayer;
    CALayer *_iconLayer;
    
    MQSwitchButtonState mState;
    CFTimeInterval _clickTime;
    
    id <MQSwitchButtonDelegate> delegate;
}

- (void)setState:(MQSwitchButtonState)state;
- (MQSwitchButtonState)getState;

@property (assign) id <MQSwitchButtonDelegate> delegate;
@end

