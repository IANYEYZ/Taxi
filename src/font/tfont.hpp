#pragma once
#include "../tinclude.hpp"
#include "../surface/tsurface.hpp"

/**
 * Font class
 */
class font {
    map<char, tuple<surface, int, int> > mp; // surface, height, width
    color fg, bg; // foreground color and background color
    public:
    /**
     * Initializer, initialize to empty
     */
    font() {}
    /**
     * Initializer, set the mp, fg, bg manually
     * @param mp mp
     * @param fg fg
     * @param bg bg
     */
    font(map<char, tuple<surface, int, int> > mp, color fg = color(255, 255, 255), color bg = color()): mp(mp), fg(fg), bg(bg) {}
    /**
     * Draw a str to a surface with this font
     * @param str the string that needed to be drawn
     * @param bgChar the background character
     */
    surface toSurface(string str, Char bgChar) {
        int height = 0, width = 0;
        for (auto i:str) {
            height = max(height, get<1>(mp[i]));
            width += get<2>(mp[i]);
        }
        surface res = makeSurface(height, width, bgChar);
        pos p = {0, 0};
        for (auto i:str) {
            drawTo(reskin(get<0>(mp[i]), fg, bg), res, p);
            p.y += get<2>(mp[i]);
        }
        return res;
    }
};

font normal = font(map<char, tuple<surface, int, int> >({
    make_pair<char, tuple<surface, int, int> >('a', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "a")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('b', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "b")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('c', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "c")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('d', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "d")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('e', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "e")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('f', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "f")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('g', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "g")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('h', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "h")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('i', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "i")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('j', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "j")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('k', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "k")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('l', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "l")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('m', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "m")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('n', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "n")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('o', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "o")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('p', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "p")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('q', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "q")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('r', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "r")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('s', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "s")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('t', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "t")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('u', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "u")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('v', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "v")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('w', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "w")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('x', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "x")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('y', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "y")), 1, 1)),
    make_pair<char, tuple<surface, int, int> >('z', make_tuple<surface, int, int>(makeSurface(1, 1, Char(color(), color(), "z")), 1, 1))
}));

void writeTo(string wd, surface &sfc, pos p, font ft = normal) {
    drawTo(ft.toSurface(wd, Char()), sfc, p, Char());
}