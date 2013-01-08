/**
 * Copyright Alex Parker 2013
 * 
 * OpenGL Window Toolkit Header File
 **/

#include "GL.h"

#ifndef glwt_glwt_h
#define glwt_glwt_h

class Game
{
public:
    static bool Setup(int argc, const char** argv);
    static void Draw(float deltaTime);
};

class Window
{
public:
    static bool Open(int width, int height, bool fullscreen, const char* windowTitle);
    static void Close();
    static int Width();
    static int Height();
    
    static void ShowMessageBox(const char* message);
};

struct Key
{
    enum Enum
    {
        Escape
    };
};

class Input
{
public:
    static bool KeyUp(Key::Enum key);
    static bool KeyDown(Key::Enum key);
};

#endif
