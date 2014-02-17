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
* Windows support
* No additional library dependencies (e.g. GLUT, GLEW, etc)
* A lightweight graphics library supporting:
    * Matrices
    * 2D and 3D vectors

Planned Features
----------------

* Input API (Mouse Input, Keyboard Input)
* Event API (Window Resize, Window Close, etc)
* Extend Support to Linux (shout if you want it and I'll make it a priority :)

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

    static void Resize(int width, int height);

> Called every time the window is resized

### Window ###
Handles the window and the creation of an OpenGL context.

    static bool Open(int width, int height, bool fullscreen, const char* windowTitle);

> Opens a window with the given width, height and window title. Setting fullscreen to true creates a fullscreen window with that screen resolution.

    static void Close();

> Closes the window, which also closes the whole application.

    static int Width();

> Returns the current window width.

    static int Height();

> Returns the current window height.

    static void ShowMessageBox(const char* message);

> Displays a pop-up dialogue containing the message.

### GL ###
The GL class provides access to all of the OpenGL core functions. This is based off the [gl3w library](https://github.com/skaslev/gl3w).

    static int Init();

> Loads all of the OpenGL functions. This is called automatically by Window::Open(). See http://www.opengl.org/wiki/Load_OpenGL_Functions for more info on why this is needed.

    static bool IsSupported(int major, int minor);

> Returns true if the current context supports the major and minor version number.

    static void* GetProcAddress(const char *proc);

> Returns the function call address for an OpenGL function.

    static const Version& GetVersion();

> Returns a structure representing the OpenGL version.

### Maths.h ###
Maths.h basic header only maths library with matrices, vectors and common transforms. This is meant to be as simple as possible and is not optimised in any way. Feel free to contribute if you feel something is missing.

    struct vec2
    {
        vec2(float x, float y);
    };
> Represents a 2D vector

    struct vec3
    {
        //multiplies the vector by a scalar, returning the result.
        inline vec3 operator *(float scalar) const

        //adds two vectors together, returning the result.
        inline vec3 operator +(const vec3& other) const

        //subtracts two vectors, returning the result.
        inline vec3 operator -(const vec3& other) const

        //calculate the dot product with the other vector, returning the result.
        inline float dot(const vec3& other) const

        //calculates the squared length of the current vector.
        inline float lengthSq() const

        //calculates the length of the vector.
        inline float length() const

        //normalizes the current vector.
        void normalize()

        //calculates the cross product with the other vector, returning the result.
        inline vec3 cross(const vec3& other) const
    };
> Represents a 3D vector with all of the basic 3D vector operations.

    struct mat4
    {
        float rows[16];

        //performs a matrix multiplication and returns the result.
        mat4 operator *(const mat4& other) const

        //produces a axis angle matrix. This will produce a rotation in radians about the normalized axis.
        static mat4 axisangle(const vec3& axis, float angle)

        //produces a translation matrix
        static mat4 translate(float x, float y, float z)

        //returns the identity matrix
        static mat4 identity()

        //calculates a projection matrix from the field of view in radians,
        //the aspect ratio, the near culling plane and far culling plane.
        static mat4 proj(float fov, float aspect, float n, float f)
    };
> Represents a 4x4 matrix with some functions to calculate common matrix transformations.
