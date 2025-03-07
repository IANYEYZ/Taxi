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
}Input;