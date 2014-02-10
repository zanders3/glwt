#include <windows.h>
#include <GL/GL.h>
#include "glwt.h"

#pragma comment (lib, "opengl32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
HCURSOR gPointerCursor;

int WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	gPointerCursor = LoadCursor(NULL, IDC_ARROW);

	MSG msg          = {0};
	WNDCLASS wc      = {0}; 
	wc.lpfnWndProc   = WndProc;
	wc.hInstance     = hInstance;
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
	wc.lpszClassName = L"glwt";
	wc.style = CS_OWNDC;
	if( !RegisterClass(&wc) )
		return 1;
	CreateWindowW(wc.lpszClassName,L"Hello, world!",WS_OVERLAPPEDWINDOW|WS_VISIBLE,0,0,640,480,0,0,hInstance,0);

	while( GetMessage( &msg, NULL, 0, 0 ) > 0 )
		DispatchMessage( &msg );

	return 0;
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

		GL::ClearColor(0.0f, .0f, 0.0f, 1.0f);
		GL::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
