#pragma once
#include "tpos.hpp"
#include "../tinclude.hpp"
/**
 * Definition for posPreprocessor, which preprocess the position given to cursor(which, idealy, should be the only place need to deal with output position)
 */
using posPreprocessor = function<pos(pos)>;
/**
 * A Id posPreprocessor, which does nothing, it's also the default posPreprocessor
 * @param p the position given to it, as a pos object
 * @return p without any change
 */
pos I(pos p) {
    return p;
}
/**
 * A posPreprocessor, which multiply the y coordinate(in taxi, y coordinate is width) by 2, it is made because the width of 2 space is roughly the height of a line(if you are using default font, then that's exact)
 * @param p the position given to it, as a pos object
 * @return a pos object where x coordinate is the same of p, the y coordinate is the twice of p
 */
pos y2(pos p) {
    // two space is roughly the height of endl, so it's pretty common to use two space as a char
    return pos(p.x, p.y * 2);
}
posPreprocessor cursorPosPreprocessor = I;
/**
 * Set current cursor position, first let the position given to it go through the posPreprocessor, then the cursor position is set to it
 * @param p the position given to it
 * @ingroup core
 */
void cursor(pos p) {
    pos pNew = cursorPosPreprocessor(p);
    printf("\x1b[%d;%dH", pNew.x, pNew.y);
}
/**
 * Hide the cursor
 * NOTE: cursor will still work, just the blinking square/the underline/whatever you set cursor to is not visible
 * NOTE: this is not fully supported by all platform
 */
void hideCursor() {
    printf("\x1b[?25l");
}
/**
 * Show the cursor
 * NOTE: if the cursor is already visible, it'll do nothing
 * NOTE: this is not fully supported by all platform
 */
void showCursor() {
    printf("\x1b[?25h");
}