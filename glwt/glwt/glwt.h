/**
 * Copyright Alex Parker 2013
 * 
 * OpenGL Window Toolkit Header File
 **/

#include "GL.h"

#ifndef __glwt__glwt_h
#define __glwt__glwt_h

class Game
{
public:
    static bool Setup(int argc, const char** argv);
    static void Draw(float deltaTime);
	static void Update(float deltaTime);

	static void Resize(int width, int height);
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
