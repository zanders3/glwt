//
//  Window.mm
//  glwt
//
//  Created by Alex Parker on 07/01/2013.
//  Copyright (c) 2013 Alex Parker. All rights reserved.
//

#include "glwt.h"
#import "GLView.h"
#import "AppDelegate.h"

NSWindow* window = nil;
int gWidth, gHeight;

bool Window::Open(int width, int height, bool fullscreen, const char* windowTitle)
{
    NSRect screenSize = [[NSScreen mainScreen] frame];
    
    NSRect mainDisplayRect = fullscreen ? screenSize : NSMakeRect((screenSize.size.width-width)/2, (screenSize.size.height-height)/2, width, height);
    window = [[NSWindow alloc]
                        initWithContentRect: mainDisplayRect
                        styleMask: fullscreen ?
                            NSBorderlessWindowMask :
                            NSClosableWindowMask|NSResizableWindowMask|NSMiniaturizableWindowMask|NSTitledWindowMask
                        backing:NSBackingStoreBuffered
                        defer:YES];
    [window setTitle:[NSString stringWithUTF8String:windowTitle]];
    [window setOpaque:YES];
    
    if (fullscreen)
    {
        [window setLevel:NSMainMenuWindowLevel+1];
        [window setHidesOnDeactivate:YES];
    }
   
    //create an OpenGL context
    NSOpenGLPixelFormatAttribute attrs[] =
    {
        NSOpenGLPFADoubleBuffer,
        NSOpenGLPFAColorSize, 32,
        NSOpenGLPFAAccelerated,
        NSOpenGLPFADoubleBuffer,
        NSOpenGLPFASingleRenderer,
        0
    };
    NSOpenGLPixelFormat* pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
    
    NSRect viewRect = NSMakeRect(0.0, 0.0, mainDisplayRect.size.width, mainDisplayRect.size.height);
    GLView *fullScreenView = [[GLView alloc] initWithFrame:viewRect pixelFormat: pixelFormat];
    
    // Synchronize buffer swaps with vertical refresh rate
    GLint swapInt = 1;
    [[fullScreenView openGLContext] setValues:&swapInt forParameter:NSOpenGLCPSwapInterval];
    
    //Load Open GL functions
    GL::Init();
    
    //Add the OpenGL view to the window
    [window setContentView: fullScreenView];
    [window makeKeyAndOrderFront:[AppDelegate delegate]];
    
    gWidth = (int)mainDisplayRect.size.width;
    gHeight = (int)mainDisplayRect.size.height;
    
    return true;
}

void Window::Close()
{
    [[NSApplication sharedApplication] terminate:nil];
}

int Window::Width()
{
    return gWidth;
}

int Window::Height()
{
    return gHeight;
}
