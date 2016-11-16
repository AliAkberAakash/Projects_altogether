#ifndef WINDOWSIZEHEADER_H_INCLUDED
#define WINDOWSIZEHEADER_H_INCLUDED

#define WINVER 0x0500
#include <windows.h>
#include"pacManHeader.h"

int window (void)
{
    // Get console window handle
    HWND wh = GetConsoleWindow();

    // Move window to required position
    MoveWindow(wh, 300, 300, 300, 300, TRUE);

    pac();
}


#endif // WINDOWSIZEHEADER_H_INCLUDED
