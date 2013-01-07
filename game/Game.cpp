/**
 * Copyright Alex Parker 2013
 *
 * OpenGL Window Toolkit
 **/

#include "glwt.h"
#include "OpenGL/OpenGL.h"

bool Game::Setup(int argc, const char** argv)
{
    Window::Open(800, 600, false, "Hello World!");
    
    GL::ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    return true;
}

void Game::Draw(float deltaTime)
{
    GL::Clear();
}