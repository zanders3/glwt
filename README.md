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

Sample Code
-----------

This will open an 800x600 window and clear the screen to black every frame.

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

Documentation
-------------

### Game ###
This is the main entry point for the application. Your code goes here.

    static bool Setup(int argc, const char** argv);

> Replaces your main function (this is platform specific anyway). You should open a window here and initialize OpenGL objects, load textures, etc.
> Returning false closes the application cleanly.

    static void Draw(float deltaTime);

> Called every frame with the time in seconds since the last frame.

### Window ###
Handles the window and the creation of an OpenGL context.

    static bool Open(int width, int height, bool fullscreen, const char* windowTitle);
> Opens a window with the given width, height and window title. Setting fullscreen to true creates a fullscreen window with that screen resolution.

    static void Close()
> Closes the window, which closes the whole application.

    static int Width()
> Returns the current window width.

    static int Height()
> Returns the current window height.

    static void ShowMessageBox(const char* message)
> Displays a pop-up dialogue containing the message.

### GL ###
The GL class provides access to all of the OpenGL core functions. This is based off the [gl3w library](https://github.com/skaslev/gl3w).

    static int Init();

> Loads all of the OpenGL functions. This is called automatically by Window::Open(). See http://www.opengl.org/wiki/Load_OpenGL_Functions for more info on why this happens.

    static bool IsSupported(int major, int minor)

> Returns true if the current context supports the major and minor version number.

    static void* GetProcAddress(const char *proc)

> Returns the function call address for an OpenGL function.

    static const Version& GetVersion()

> Returns a structure representing the OpenGL version.

