#pragma once
#include "../tinclude.hpp"
#include "../surface/tsurface.hpp"
#include "../font/tfont.hpp"
struct transparent {
    Char c;
    transparent(Char c = Char(color(), color(), "__taxi__transparent__char__")):c(c) {}
};
class tostream {
    private:
    surface sfc;
    font curFont;
    pos curPos;
    Char transparentChar;
    public:
    tostream() {
        transparentChar = Char(color(), color(), "__taxi__transparent__char__");
        curFont = normal;
    }
    tostream(surface sfc, Char transparentChar = Char(color(), color(), "__taxi__transparent__char__")):sfc(sfc), transparentChar(transparentChar), curFont(normal) {}
    tostream operator<<(string txt) {
        writeTo(txt, this -> sfc, curPos, curFont);
        return *this;
    }
    tostream operator<<(font ft) {
        curFont = ft;
        return *this;
    }
    tostream operator<<(pos p) {
        curPos = p;
        return *this;
    }
    tostream operator<<(transparent t) {
        transparentChar = t.c;
        return *this;
    }
    tostream operator<<(surface s) {
        renderTo(s, sfc, curPos, transparentChar);
        return *this;
    }
    tostream operator<<(Char c) {
        drawTo(makeSurface(1, 1, c), sfc, curPos, transparentChar);
        return *this;
    }
    surface getSurface() {
        return sfc;
    }
};