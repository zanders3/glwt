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
#include <mach/mach_time.h>

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
    
    openGLReady = false;
    
    //ensure vbsynch is on!
    [[self openGLContext] setValues:(GLint[]){1} forParameter:NSOpenGLCPSwapInterval];
    
    lastFrame = mach_absolute_time();
    mach_timebase_info(&info);
    
    timer = [NSTimer timerWithTimeInterval:0.001
                     target:self
                     selector:@selector(renderTimerCallback:)
                     userInfo:nil
                     repeats:YES];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSEventTrackingRunLoopMode];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSModalPanelRunLoopMode];
    
    return self;
}

-(void)reshape
{
    if (Window::Width() > 0)
        Game::Resize(Window::Width(), Window::Height());
}

-(void)drawRect:(NSRect)dirtyRect
{
    uint64_t latestTime = mach_absolute_time();
    uint64_t elapsed = latestTime - lastFrame;
    lastFrame = latestTime;
    
    elapsed *= info.numer;
    elapsed /= info.denom;
    
    float elapsedSeconds = (float)elapsed * 0.000000001f;
    
    if (openGLReady)
    {
        Game::Update(elapsedSeconds);
        Game::Draw(elapsedSeconds);
    }
    else
    {
        GL::ClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        GL::Clear(GL_COLOR_BUFFER_BIT);
    }
    
    glSwapAPPLE();
}

@end
