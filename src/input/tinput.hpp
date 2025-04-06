#pragma once
#include "../tinclude.hpp"
/**
 * The Input system
 * The class is called _Input, because the actual used will be a object that's typed _Input, named Input
 */
class _Input {
    public:
    _Input() {}
    /**
     * Check if a given key is pressed or not
     * @note now works only on windows system
     * @param key the key value that need to be checked, can be 'a' or virtual key value like VK_UP
     * @return true if the key is pressed, false otherwise
     */
    bool isKeyPressed(int key) {
        #ifndef _WIN32
        #error ONLY_USEABLE_ON_WINDOWS
        #endif
        return GetAsyncKeyState(key) & 0x8000;
    }
    /**
     * Get the mouse postion, in character(for example, (1, 1) means that 1 line break and 1 character will reach the mouse position)
     * @note now works only on windows system
     * @return the mouse position
     */
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