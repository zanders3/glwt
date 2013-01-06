OpenGL Window Toolkit
====

What is it?
-----------

The OpenGL Windowing Toolkit is an attempt to drag OpenGL away from it's old fixed pipeline roots and drag it into the 21st century. The windowing toolkit is designed to ease development of graphics applications in OpenGL, and is intended as a complete replacement for the likes of GLFW, GLUT, GLEW and other libraries.

I want to make this OpenGL API as easy to use as the XNA API used for DirectX!

Getting Started
---------------

Here is an example of where I want to get with this API. A lofty goal ;)

    #include "glwt.h"

    void main()
    {
    	//Initialise an OpenGL context and open a window.
    	Window::Open(800,600,false);

    	//We now have an Open GL context!
    	GL::ClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    	//Returns true whilst the user has got the window open.
    	while (Window::IsOpen())
    	{
    		GL::Clear();
	    	Window::SwapBuffers();

	    	if (Input::KeyPressed(Key::Escape))
	    	{
	    		//Closes the window, which causes Window::IsOpen() to return false.
	    		Window::Close();
	    	}
	    }
    }

Current Features
----------------

* Modern C++ API
    * All Core OpenGL functions are under the GL static class.
    * OpenGL errors are checked automatically in debug builds and throw exceptions when they occur.
* Modern OpenGL 3.2+ Support
    * The old APIs no longer exist, making things much cleaner.
* Open a Window in 1 line of code
* You keep full control of the rendering loop
* Mac OSX support (OSX 10.7+)
* No additional library dependencies (e.g. GLEW, etc)

Planned Features
----------------

* Input API (Mouse Input, Keyboard Input)
* Event API (Window Resize, Window Close, etc)
* Extend Support to multiple platforms
    * Mac OSX
    * Windows
    * Linux

Status
------
I've only just started this project so we'll see how it goes! I hope this will allow me to get more projects started up in OpenGL quicker than ever before.