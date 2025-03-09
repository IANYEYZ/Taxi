#pragma once
#include "../tinclude.hpp"
#include "tcolor.hpp"
#include "tchar.hpp"
#include "tcursor.hpp"
#include "twindow.hpp"
bool initCore() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) { return false; }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) { return false; }

    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode)) { return false; }
    return initWindows();
#else
    // do nothing
#endif
}
void closeFastEdit() {
    #ifdef _WIN32
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, mode);
    #endif
}
void clear() {
    printf("\x1b[0m");
}