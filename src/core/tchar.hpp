#pragma once
#include "../tinclude.hpp"
#include "tcolor.hpp"
struct Char {
    color bg, fg;
    string ch;
    Char() {
        bg = color("#000000");
        fg = color("#ffffff");
        ch = " ";
    }
    Char(color bg, color fg, string ch):bg(bg), fg(fg), ch(ch) {}
    void print() {
        bg.setAsBG();
        fg.setAsFG();
        printf("%s", ch.c_str());
    }
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