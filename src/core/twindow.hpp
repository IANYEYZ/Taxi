#pragma once
#include "../tinclude.hpp"
#ifdef _WIN32
HWND hwnd;
bool initWindows() {
    hwnd = GetForegroundWindow();
    return (hwnd != NULL);
}
#else
bool initWindows() {
    return true;
}
#endif