#include <windows.h>
#include <GL/GL.h>
#include "glwt.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
HCURSOR gPointerCursor;
HINSTANCE gHInstance;
HWND gHwnd;
const char* gWindowTitle = "GLWT";
int gWindowWidth = 0, gWindowHeight = 0;
bool gRunning = true;
HGLRC openGLContext;
HDC windowHandleDeviceContext;
LONGLONG gLastTime;

#pragma comment (lib, "opengl32.lib")

int __stdcall WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	gHInstance = hInstance;

	const char* argv = (const char*)lpCmdLine;
	if (!Game::Setup(1, &argv))
		return 1;

	LARGE_INTEGER currentTime;
	MSG msg = {0};
	QueryPerformanceCounter(&currentTime);
	gLastTime = currentTime.QuadPart;

	while (gRunning)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			DispatchMessage(&msg);

		if (gRunning)
		{
			//Query the elapsed frame time
			QueryPerformanceCounter(&currentTime);
			float dt = (currentTime.QuadPart - gLastTime) / 1000000.0f;
			gLastTime = currentTime.QuadPart;

			//Begin painting
			PAINTSTRUCT ps;
			BeginPaint(gHwnd, &ps);

			//Update then draw the game
			Game::Update(dt);
			Game::Draw(dt);

			//Swap out buffers and finish painting
			SwapBuffers(windowHandleDeviceContext);

			EndPaint(gHwnd, &ps);
		}
	}

	return 0;
}

bool Window::Open(int width, int height, bool fullscreen, const char* windowTitle)
{
	gWindowTitle = windowTitle;
	gWindowWidth = width;
	gWindowHeight = height;
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

int Window::Width()
{
	return gWindowWidth;
}

int Window::Height()
{
	return gWindowHeight;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CREATE:
		{
			gHwnd = hWnd;

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

	case WM_SIZE:
		{
			RECT winSize;
			GetWindowRect(hWnd, &winSize);
			gWindowWidth = (int)(winSize.right - winSize.left);
			gWindowHeight = (int)(winSize.bottom - winSize.top);
			Game::Resize(gWindowWidth, gWindowHeight);
		}
		break;

	case WM_MOUSEMOVE:
		{
			SetCursor(gPointerCursor);
		}
		break;

	case WM_PAINT:
		
		break;

	case WM_CLOSE:
		wglDeleteContext(openGLContext);
		gRunning = false;
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;

}
