//
//  JTHeader.h
//  Snip
//
//  Created by rui on 2019/5/7.
//  Copyright © 2019 isee15. All rights reserved.
//



@interface JTCaptureManager : NSObject

+ (id)sharedInstance;
//@property(retain, nonatomic) id <JTCaptureRequestDelegate> delegate; // @synthesize delegate=_delegate;
//@property(retain, nonatomic) JTCaptureRequest *request; // @synthesize request=_request;
@property(nonatomic) BOOL isCapturing; // @synthesize isCapturing=_isCapturing;

- (void)handleCaptureCancelNotification:(id)arg1;
- (void)captureDidFinishWithImage:(id)arg1 needSave:(BOOL)arg2 isHighResolution:(BOOL)arg3;
- (BOOL)startCaptureByRequest:(id)arg1;



@end

