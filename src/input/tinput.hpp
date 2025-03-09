#pragma once
#include "../tinclude.hpp"
class _Input {
    public:
    _Input() {}
    bool isKeyPressed(int key) {
        #ifndef _WIN32
        #error ONLY_USEABLE_ON_WINDOWS
        #endif
        return GetAsyncKeyState(key) & 0x8000;
    }
    pos getMousePosition() {
        #ifndef _WIN32
        #error ONLY_USEABLE_ON_WINDOWS
        #endif
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        ScreenToClient(hwnd, &cursorPos);
        return pos(cursorPos.y / 16, cursorPos.x / 8);
    }
}Input;