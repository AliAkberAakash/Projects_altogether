//
// move_window.c - Move a console window to specific
// screen coordinates.
//
// Written by Ted Burke - last modified 17-4-2012
//
// To compile: gcc -o move_window.exe move_window.c
//

#define WINVER 0x0500
#include <windows.h>
#include"pacManHeader.h"

int main (void)
{
    // Get console window handle
    HWND wh = GetConsoleWindow();

    // Move window to required position
    MoveWindow(wh, 300, 300, 300, 300, TRUE);

    pac();
}
