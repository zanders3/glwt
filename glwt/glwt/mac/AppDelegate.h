//
//  AppDelegate.h
//  glwt
//
//  Created by Alex Parker on 07/01/2013.
//  Copyright (c) 2013 Alex Parker. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject<NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;

+ (AppDelegate*)delegate;

-(BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender;

@end
