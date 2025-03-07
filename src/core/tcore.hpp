#pragma once
#include "../tinclude.hpp"
#include "tcolor.hpp"
#include "tchar.hpp"
#include "tcursor.hpp"
bool initCore() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) { return false; }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) { return false; }

    dwMode |= 0x0004;
    if (!SetConsoleMode(hOut, dwMode)) { return false; }
    return true;
#else
    // do nothing
#endif
}
void clear() {
    printf("\x1b[0m");
}