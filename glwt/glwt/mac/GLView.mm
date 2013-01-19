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

- (void)renderTimerCallback:(NSTimer*)timer
{
    // lets the OS call drawRect for best window system synchronization
    [self display];
}

-(id)initWithFrame:(NSRect)frameRect pixelFormat:(NSOpenGLPixelFormat *)format
{
    self = [super initWithFrame:frameRect pixelFormat:format];
    
    timer = [NSTimer timerWithTimeInterval:0.001 // must use with vbsynch on, or you waste lots of CPU!
                     target:self
                     selector:@selector(renderTimerCallback:)
                     userInfo:nil
                     repeats:YES];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSEventTrackingRunLoopMode];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSModalPanelRunLoopMode];
    
    return self;
}

-(void)drawRect:(NSRect)dirtyRect
{
    if (Window::Width() > 0)
        Game::Draw(0.0f);
    else
    {
        GL::ClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        GL::Clear(GL_COLOR_BUFFER_BIT);
    }
    
    glSwapAPPLE();
}

@end
