OpenGL Window Toolkit
====

What is it?
-----------

The OpenGL Window Toolkit is an attempt to drag OpenGL away from it's old fixed pipeline roots and drag it into the 21st century. The windowing toolkit is designed to ease development of graphics applications in OpenGL, and is intended as a complete replacement for the likes of GLFW, GLUT, GLEW and other libraries.

It is meant to use the best available low level windowing APIs on each platform to give the best performance and compatability on every platform. No legacy APIs are used.

Current Features
----------------

* Modern C++ API
    * All Core OpenGL functions are under the GL static class.
    * OpenGL errors are checked automatically in debug builds and throw exceptions when they occur.
* Modern OpenGL 3.2+ Support
    * The old APIs no longer exist, making things much cleaner.
* Open a Window in 1 line of code
* Mac OSX support (OSX 10.7+ only since OpenGL 3.2 support is 10.7+ only)
* No additional library dependencies (e.g. GLUT, GLEW, etc)

Planned Features
----------------

* Input API (Mouse Input, Keyboard Input)
* Event API (Window Resize, Window Close, etc)
* Extend Support to additional platforms
    * Windows
    * Linux

Getting Started
---------------

So long, BOILERPLATE CODE!

    #include "glwt.h"

    bool Game::Setup(int argc, const char** argv)
    {
        //Initialise an OpenGL 3.2 Core context and open a window (set to true for fullscreen)
        if (!Window::Open(800,600,false))
            return false;

        //We now have an Open GL context!
        GL::ClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        //We loaded sucessfully! Woo!
        return true;
    }

    void Game::Update(float dt)
    {
        //Clear the color and depth buffer
        GL::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

Status
------
I've only just started this project so we'll see how it goes! I hope this will allow me to get more projects started up in OpenGL quicker than ever before, once I've finished dealing with all of this boilerplate.