//
//  GL.cpp
//  glwt
//
//  Created by Alex Parker on 07/01/2013.
//  Copyright (c) 2013 Alex Parker. All rights reserved.
//

#include "glwt.h"

void GL::ClearColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void GL::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}