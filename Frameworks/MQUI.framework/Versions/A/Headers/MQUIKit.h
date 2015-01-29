//
//  MQUIKit.h
//  MQUI
//
//  Created by Hugoyao  on 12-11-13.
//  Copyright (c) 2012年 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MQCustomMenu.h"
#import "MQNinePartImage.h"
#import "MQSwitchButton.h"
#import "MQSlideView.h"
#import "MQSourceList.h"
#import "MQTitledWindow.h"
#import "MQPopoverController.h"
#import "MQPull2RefreshScrollView.h"
#import "MQToolTips.h"
#import "MQDragManager.h"
#import "MQLayerView.h"
#import "MQScrollView.h"
#import "MQTableView.h"
#import "MQTableViewCell.h"
#import "MQTableViewLayoutMgr.h"
#ifdef __cplusplus
extern "C" {
#endif
//convert the point from screen coordinate system to base coordinate system
extern NSPoint ConvertScreenLocationToBase(NSPoint screenLocation, NSWindow *window);

//convert the point from base coordinate system to screen coordinate system
extern NSPoint ConvertBaseLocationToScreen(NSPoint baseLocation, NSWindow *window);
#ifdef __cplusplus
}
#endif