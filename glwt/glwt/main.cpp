//
//  main.cpp
//  glwt
//
//  Created by Alex Parker on 06/01/2013.
//  Copyright (c) 2013 Alex Parker. All rights reserved.
//

#include <iostream>
#include "glwt.h"

int main(int argc, const char * argv[])
{
    Window::Open(800, 600, false, "Hello world!");
    
    GL::ClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    while (Window::IsOpen())
    {
        GL::Clear();
        Window::SwapBuffers();
        
        if (Input::KeyDown(Key::Escape))
            Window::Close();
    }
    
    return 0;
}

