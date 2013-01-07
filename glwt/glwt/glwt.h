/**
 * Copyright Alex Parker 2013
 * 
 * OpenGL Window Toolkit Header File
 **/

#ifndef glwt_glwt_h
#define glwt_glwt_h

class NoCopy
{
private:
    NoCopy();
    ~NoCopy();
    NoCopy(const NoCopy& other){}
};

class Game : NoCopy
{
public:
    static bool Setup(int argc, const char** argv);
    static void Draw(float deltaTime);
};

class Window : NoCopy
{
public:
    static bool Open(int width, int height, bool fullscreen, const char* windowTitle);
    static void Close();
    static int Width();
    static int Height();
};

class GL : NoCopy
{
public:
    static void ClearColor(float r, float g, float b, float a);
    static void Clear();
};

struct Key
{
    enum Enum
    {
        Escape
    };
};

class Input : NoCopy
{
public:
    static bool KeyUp(Key::Enum key);
    static bool KeyDown(Key::Enum key);
};

#endif
