//
//  GLView.h
//  glwt
//
//  Created by Alex Parker on 07/01/2013.
//  Copyright (c) 2013 Alex Parker. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#include <mach/mach_time.h>

@interface GLView : NSOpenGLView<NSWindowDelegate>
{
    uint64_t lastFrame;
    mach_timebase_info_data_t info;
    
    @public
    bool openGLReady;
}
@end
