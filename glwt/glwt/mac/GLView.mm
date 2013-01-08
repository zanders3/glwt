//
//  GLView.m
//  glwt
//
//  Created by Alex Parker on 07/01/2013.
//  Copyright (c) 2013 Alex Parker. All rights reserved.
//

#include "glwt.h"
#import "GLView.h"
#import "OpenGL/OpenGL.h"

NSTimer* timer;

extern "C" {
extern void glSwapAPPLE(void);
}

@implementation GLView

- (void)renderTimerCallback:(NSTimer*)theTimer
{
    // lets the OS call drawRect for best window system synchronization
    [self display];
}

-(id)initWithFrame:(NSRect)frameRect pixelFormat:(NSOpenGLPixelFormat *)format
{
    self = [super initWithFrame:frameRect pixelFormat:format];
    
    timer = [[NSTimer alloc] initWithFireDate:[NSDate distantFuture]
                                    interval:0.001 // must use with vbsynch on, or you waste lots of CPU!
                                    target:self
                                    selector:@selector(renderTimerCallback:)
                                    userInfo:nil
                                    repeats:YES];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSEventTrackingRunLoopMode];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSModalPanelRunLoopMode];
    [timer release];
    
    return self;
}

-(void)drawRect:(NSRect)dirtyRect
{
    Game::Draw(0.0f);
    glSwapAPPLE();
}

@end
