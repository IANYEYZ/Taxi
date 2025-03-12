#pragma once
#include "../tinclude.hpp"
#ifdef _WIN32
HWND hwnd;
/**
 * Get the handle of this console, useful for getting the cursor position
 * NOTE: will do nothing in platform other then windows
 * @return true if the handle is not null, if the platform is not windows then always return true
 */
bool initWindows() {
    hwnd = GetForegroundWindow();
    return (hwnd != NULL);
}
#else
bool initWindows() {
    return true;
}
#endif