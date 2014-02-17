#include <windows.h>
#include <GL/GL.h>
#include "glwt.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
HCURSOR gPointerCursor;
HINSTANCE gHInstance;
const char* gWindowTitle = "GLWT";

#pragma comment (lib, "opengl32.lib")

int __stdcall WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	gHInstance = hInstance;

	const char* argv = (const char*)lpCmdLine;
	if (!Game::Setup(1, &argv))
		return 1;

	MSG msg = {0};

	while( GetMessage( &msg, NULL, 0, 0 ) > 0 )
		DispatchMessage( &msg );

	return 0;
}

bool Window::Open(int width, int height, bool fullscreen, const char* windowTitle)
{
	gWindowTitle = windowTitle;
	gPointerCursor = LoadCursor(NULL, IDC_ARROW);

	WNDCLASS wc = {0};
	wc.lpfnWndProc   = WndProc;
	wc.hInstance     = gHInstance;
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
	wc.lpszClassName = L"GLWT";
	wc.style = CS_OWNDC;
	if( !RegisterClass(&wc) )
		return false;

	const size_t WCHARBUF = 100;
	wchar_t  wszDest[WCHARBUF];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, windowTitle, -1, wszDest, WCHARBUF);

	CreateWindow(wc.lpszClassName, &wszDest[0], WS_OVERLAPPEDWINDOW|WS_VISIBLE, 0, 0, width, height, 0, 0, gHInstance, 0);

	return true;
}

void Window::ShowMessageBox(const char* message)
{
	MessageBoxA(0,message, gWindowTitle,0);
}

HGLRC openGLContext;
HDC windowHandleDeviceContext;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CREATE:
		{
			PIXELFORMATDESCRIPTOR pfd =
			{
				sizeof(PIXELFORMATDESCRIPTOR),
				1,
				PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
				PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
				32,                        //Colordepth of the framebuffer.
				0, 0, 0, 0, 0, 0,
				0,
				0,
				0,
				0, 0, 0, 0,
				24,                        //Number of bits for the depthbuffer
				8,                        //Number of bits for the stencilbuffer
				0,                        //Number of Aux buffers in the framebuffer.
				PFD_MAIN_PLANE,
				0,
				0, 0, 0
			};

			windowHandleDeviceContext = GetDC(hWnd);

			int  pixelFormat;
			pixelFormat = ChoosePixelFormat(windowHandleDeviceContext, &pfd); 
			SetPixelFormat(windowHandleDeviceContext, pixelFormat, &pfd);

			openGLContext = wglCreateContext(windowHandleDeviceContext);
			wglMakeCurrent(windowHandleDeviceContext, openGLContext);

			GL::Init();
		}
		break;

	case WM_MOUSEMOVE:
		{
			SetCursor(gPointerCursor);
		}
		break;

	case WM_PAINT:
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);

		Game::Draw(0.1f);

		SwapBuffers(windowHandleDeviceContext);

		EndPaint(hWnd, &ps);
		break;

	case WM_CLOSE:
		wglDeleteContext(openGLContext);
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;

}
