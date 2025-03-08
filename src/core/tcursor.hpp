#pragma once
#include "tpos.hpp"
#include "../tinclude.hpp"
using posPreprocessor = function<pos(pos)>;
pos I(pos p) {
    return p;
}
pos y2(pos p) {
    // two space is roughly the height of endl, so it's pretty common to use two space as a char
    return pos(p.x, p.y * 2);
}
posPreprocessor cursorPosPreprocessor = I;
void cursor(pos p) {
    pos pNew = cursorPosPreprocessor(p);
    printf("\x1b[%d;%dH", pNew.x, pNew.y);
}
void hideCursor() {
    printf("\x1b[?25l");
}
void showCursor() {
    printf("\x1b[?25h");
}