/**
 Copyright Alex Parker 2013
 
 OpenGL Window Toolkit Header File
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

class Window : NoCopy
{
public:
    static void Open(int width, int height, bool fullscreen, const char* windowTitle);
    static void Close();
    
    static bool IsOpen();
    
    static void SwapBuffers();
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

class GL : NoCopy
{
public:
    static void ClearColor(float r, float g, float b, float a);
    static void Clear();
};

#endif
