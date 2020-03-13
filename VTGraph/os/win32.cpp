#include "win32.h"
#include <stdio.h>
namespace os {

HWND _init_instance(ContainerSize* cs)
{
    // Get console window handle
    HWND wh = GetConsoleWindow();
    // Move window to required position
    //MoveWindow(wh, 0, 0, 1900, 1600, TRUE);

    HANDLE stdh = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE stdinh = GetStdHandle(STD_INPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(stdh, &csbi);
    cs->cs_row = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    cs->cs_col = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    SetConsoleOutputCP(CP_UTF8);
    DWORD fdwMode = ENABLE_EXTENDED_FLAGS, cNumRead;
    if (!SetConsoleMode(stdinh, fdwMode)) {
        fprintf(stderr, "SetConsoleMode", GetLastError);
        return NULL;
    }
    DWORD mode;
    SetConsoleMode(stdinh, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    SetConsoleMode(stdh, 0x0007 | DISABLE_NEWLINE_AUTO_RETURN | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    GetConsoleMode(stdh, &mode);
    INPUT_RECORD irInBuf[128];
    while (1)
    {

        // Wait for the events. 

        if (!ReadConsoleInput(
            stdinh,      // input buffer handle 
            irInBuf,     // buffer to read into 
            128,         // size of read buffer 
            &cNumRead)) // number of records read
        {
            fprintf(stderr, "Error Read %u", GetLastError());
            exit(1);
        }
        // Dispatch the events to the appropriate handler.
        printf("%s", "ACA");
    }
    getchar();
    CONSOLE_FONT_INFOEX info = { 0 };
    info.cbSize = sizeof(info);
    info.dwFontSize.Y = 14; // leave X as zero
    info.FontWeight = FW_NORMAL;
    wcscpy_s(info.FaceName, L"Iosevka");
    SetCurrentConsoleFontEx(stdh, NULL, &info);

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = 0;
    lpCursor.dwSize = 30;
    SetConsoleCursorInfo(stdh, &lpCursor);

    // TODO - return display instance
    return wh;
}

BOOL _change_window_message_filter_es(HWND handle)
{
    return ChangeWindowMessageFilterEx(handle, 255, MSGFLT_ALLOW, NULL);
}

void _init_event_handler(void)
{
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
/*  This function is called by the Windows function DispatchMessage()  */
#include <stdio.h>
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    printf("%s", "ACA");
    switch (message)                  /* handle the messages */
    {
    case WM_DESTROY:
        PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
        break;
    default:                      /* for messages that we don't deal with */
        return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}
/*
DWORD g_main_tid = 0;
DWORD g_win_tid = 0;
HHOOK kb_hook = 0;
HHOOK ms_hook = 0;
static HINSTANCE hinstDLL;
HOOKPROC cbFunction;

BOOL CALLBACK con_handler(DWORD)
{
    PostThreadMessage(g_main_tid, WM_QUIT, 0, 0);
    printf("%s", "ACA");
    return TRUE;
}

LRESULT mouse_hook(int code, WPARAM wparam, LPARAM lparam)
{
    printf("%u", wparam);
    WM_MOUSEMOVE;
    WM_MOUSEWHEEL;
    return CallNextHookEx(ms_hook, code, wparam, lparam);
}

LRESULT func(int code, WPARAM wparam, LPARAM lparam)
{
    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lparam;
    const char* info = NULL;
    if (wparam == WM_KEYDOWN)
        info = "key dn";
    else if (wparam == WM_KEYUP)
        info = "key up";
    else if (wparam == WM_SYSKEYDOWN)
        info = "sys key dn";
    else if (wparam == WM_SYSKEYUP)
        info = "sys key up";
    printf("%s - vkCode [%04x], scanCode [%04x]\n", info, p->vkCode, p->scanCode);

    return CallNextHookEx(kb_hook, code, wparam, lparam);
}

SetConsoleCtrlHandler(&con_handler, TRUE);
*/
/*
hinstDLL = LoadLibrary(TEXT("Dll1.dll"));
if (hinstDLL == NULL)// || ms_hook == NULL)
{
    fprintf(stderr, "LoadLib failed with error %d\n", ::GetLastError());
    return 0;
}

cbFunction = (HOOKPROC)GetProcAddress(hinstDLL, "functionWndProc");
if (cbFunction == NULL)// || ms_hook == NULL)
{
    fprintf(stderr, "cbFunc failed with error %d\n", ::GetLastError());
    return 0;
}*/

//HOOKPROC
/*g_main_tid = GetCurrentThreadId();
DWORD pid = 0;
g_win_tid = ::GetWindowThreadProcessId(w, &pid);

SetConsoleCtrlHandler(&con_handler, TRUE);
kb_hook = SetWindowsHookEx(WH_KEYBOARD, cbFunction, hinstDLL, g_win_tid);
ms_hook = SetWindowsHookEx(WH_MOUSE, cbFunction, hinstDLL, g_win_tid);

if (kb_hook == NULL)// || ms_hook == NULL)
{
    fprintf(stderr, "SetWindowsHookEx failed with error %d\n", ::GetLastError());
    return 0;
}*/
/*
RAWINPUTDEVICE rid[2];

rid[0].usUsagePage = 0x01;
rid[0].usUsage = 0x02;
rid[0].dwFlags = RIDEV_NOLEGACY;   // adds HID mouse and also ignores legacy mouse messages
rid[0].hwndTarget = NULL;

rid[1].usUsagePage = 0x01;
rid[1].usUsage = 0x06;
rid[1].dwFlags = RIDEV_NOLEGACY;   // adds HID keyboard and also ignores legacy keyboard messages
rid[1].hwndTarget = NULL;

if (RegisterRawInputDevices(rid, 2, sizeof(rid[0])) == FALSE) {
    fprintf(stderr, "RegisterRawInputDevices: %u", GetLastError());
    return 0;
    //registration failed. Call GetLastError for the cause of the error
}

MSG msg;
while (GetMessage(&msg, NULL, 0, 0))
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
};
//UnhookWindowsHookEx(kb_hook);
//UnhookWindowsHookEx(ms_hook);
*/
}