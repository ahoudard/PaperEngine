#include <windows.h>

#define HInstance() GetModuleHandle(NULL)
#define MAX_NAME_STRING 256
char WindowClass[MAX_NAME_STRING];
char WindowTitle[MAX_NAME_STRING];
INT WindowWidth;
INT WindowHeight;

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {
    // Initialize Global Variables
    strcpy_s(WindowClass, "PaperEngine");
    strcpy_s(WindowTitle, "WindowPaperEngine");

    WindowWidth = 1920;
    WindowHeight = 1080;

    // create windows class 
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;

    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

    wcex.hIcon = LoadIcon(0, IDI_APPLICATION);
    wcex.hIconSm = LoadIcon(0, IDI_APPLICATION);

    wcex.lpszClassName = WindowClass;
    wcex.lpszMenuName = nullptr;
    wcex.hInstance = HInstance();

    wcex.lpfnWndProc = DefWindowProc;

    RegisterClassEx(&wcex);

    // create and display the window

    HWND handleWindow = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

    if (!handleWindow){
        return 0;
    }

    // show window
    ShowWindow(handleWindow, SW_SHOW);

    // message listener
    MSG msg = {0};
    while (msg.message != WM_QUIT){
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}