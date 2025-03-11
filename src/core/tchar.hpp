#pragma once
#include "../tinclude.hpp"
#include "tcolor.hpp"
/**
 * Char class, with a background color, foreground color, and a string
 * When output it either use C++ style(stream operator) or `print` function, background color will be set to bg, foreground color will be set to fg, and the string will be printed out
 * @ingroup core
 */
struct Char {
    color bg, fg;
    string ch;
    /**
     * Initializing the class with default values:
     * - bg is #000000
     * - fg is #ffffff
     * - ch(the string) is a space
     */
    Char() {
        bg = color("#000000");
        fg = color("#ffffff");
        ch = " ";
    }
    /**
     * Initializing the class with custom values
     * 
     * @param bg background color
     * @param fg foreground color
     * @param ch outputed string
     */
    Char(color bg, color fg, string ch):bg(bg), fg(fg), ch(ch) {}
    /**
     * Print out the Char, see the description of the whole class for more detail
     * NOTE: this method completely uses C method, be aware of that
     */
    void print() {
        bg.setAsBG();
        fg.setAsFG();
        printf("%s", ch.c_str());
    }
    /**
     * Print out the Char, see the description of the whole class for more detail
     * NOTE: this method use C++ style(stream operator)
     * @param o the ostream& object
     * @param c the color object itself, need to be wrote like this due to the C++ syntax of friend operator
     * @return the ostream& object o
     */
    friend ostream& operator<<(ostream& o, const Char& c) {
        c.bg.setAsBG();
        c.fg.setAsFG();
        o << c.ch;
        return o;
    }
    Char operator=(Char rhs) {
        bg = rhs.bg;
        fg = rhs.fg;
        ch = rhs.ch;
        return *this;
    }
    bool operator==(Char rhs) {
        return (bg == rhs.bg && fg == rhs.fg && ch == rhs.ch);
    }
    bool operator!=(Char rhs) {
        return (!(*this == rhs));
    }
};