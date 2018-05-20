#include <windows.h>

LRESULT CALLBACK MainWinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_PAINT:
		break;

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	break;
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		ExitProcess(0);
	}
	break;
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);
}


int WINAPI WinMain(
	HINSTANCE	hinstance,
	HINSTANCE	hprevinstance,
	LPSTR		LpCmdLine,
	int			nCmdShow)
{
	WNDCLASSEX	windowsclass;
	HWND		hwnd;
	MSG			msg;

	windowsclass.cbSize			= sizeof(WNDCLASSEX);
	windowsclass.style			= CS_VREDRAW | CS_HREDRAW | CS_OWNDC | CS_DBLCLKS;
	windowsclass.lpfnWndProc	= MainWinProc;
	windowsclass.cbClsExtra		= 0;
	windowsclass.cbWndExtra		= 0;
	windowsclass.hInstance		= hinstance;
	windowsclass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	windowsclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	windowsclass.hbrBackground	= (HBRUSH)GetStockObject(GRAY_BRUSH);
	windowsclass.lpszMenuName	= NULL;
	windowsclass.lpszClassName	= L"WINDOWSCLASS";
	windowsclass.hIconSm		= LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&windowsclass))
		return 0;

	if (!(hwnd = CreateWindowEx(WS_EX_TOPMOST, L"windowsclass", L"BASIC WINDOW FOR DIRECT",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 500, 500, NULL, NULL, hinstance, NULL)))
		return (0);

	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (!PeekMessageA(&msg, hwnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Sleep(10);
	}

	return (msg.wParam);
}


