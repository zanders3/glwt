#include "glwt.h"

const char* gWindowTitle = "GLWT";

bool Window::Open(int width, int height, bool fullscreen, const char* windowTitle)
{
	gWindowTitle = windowTitle;

	return false;
}

void Window::ShowMessageBox(const char* message)
{
	MessageBoxA(0,message, gWindowTitle,0);
}