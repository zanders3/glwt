//
//  AppDelegate.m
//  glwt
//
//  Created by Alex Parker on 07/01/2013.
//  Copyright (c) 2013 Alex Parker. All rights reserved.
//

#include "glwt.h"
#import "AppDelegate.h"
#import "GLView.h"

static AppDelegate* appDelegate = nil;

@implementation AppDelegate

- (void)dealloc
{
    [super dealloc];
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    appDelegate = self;
    
    NSArray* args = [[NSProcessInfo processInfo] arguments];
    NSUInteger itemCount = [args count];
    id* argsArray = (id*)malloc(itemCount * sizeof(id));
    [args getObjects:argsArray range:NSMakeRange(0, itemCount)];
    
    if (Game::Setup((int)args.count, (const char**)argsArray) == false)
        [[NSApplication sharedApplication] terminate:nil];
    
    free(argsArray);
}

+ (AppDelegate*)delegate
{
    return appDelegate;
}

-(BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
    return YES;
}

@end
