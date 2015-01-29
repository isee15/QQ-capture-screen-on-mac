//
//  MQNinePartImage.h
//  QQ4Mac
//
//  Created by heyseawang on 11-10-21.
//  Copyright 2011年 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MQNinePartImage : NSImage
{
    NSImage *mTopLeftCornerImage;
    NSImage *mTopEdgeImage;
    NSImage *mTopRightCornerImage;
    NSImage *mLeftEdgeImage;
    NSImage *mCenterImage;
    NSImage *mRightEdgeImage;
    NSImage *mBottomLeftCornerImage;
    NSImage *mBottomEdgeImage;
    NSImage *mBottomRightCornerImage;
    bool mflipped;
}

@property(readonly) NSImage *topLeftCornerImage;
@property(readonly) NSImage *topEdgeImage;
@property(readonly) NSImage *topRightCornerImage;
@property(readonly) NSImage *leftEdgeImage;
@property(readonly) NSImage *centerImage;
@property(readonly) NSImage *rightEdgeImage;
@property(readonly) NSImage *bottomLeftCornerImage;
@property(readonly) NSImage *bottomEdgeImage;
@property(readonly) NSImage *bottomRightCornerImage;

- (id)initWithNSImage:(NSImage *)baseImage leftPartWidth:(CGFloat)leftPartWidth rightPartWidth:(CGFloat)rightPartWidth topPartHeight:(CGFloat)topPartHeight bottomPartHeight:(CGFloat)bottomPartHeight;
- (id)initWithNSImage:(NSImage *)baseImage leftPartWidth:(CGFloat)leftPartWidth rightPartWidth:(CGFloat)rightPartWidth topPartHeight:(CGFloat)topPartHeight bottomPartHeight:(CGFloat)bottomPartHeight flipped:(bool)flipped;
- (void)drawInRect:(NSRect)rect compositingOperation:(NSCompositingOperation)op alphaFraction:(CGFloat)alphaFraction flipped:(BOOL)flipped;
- (void)drawInRect:(NSRect)rect fromRect:(NSRect)fromRect operation:(NSCompositingOperation)op fraction:(CGFloat)delta;

@end
