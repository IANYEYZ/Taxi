#pragma once
#include "../tinclude.hpp"
#include "../surface/tsurface.hpp"

/**
 * Font class
 */
class font {
    map<char, tuple<surface, int, int> > mp; // surface, height, width
    /**
     * Initializer, initialize to empty
     */
    font() {}
    /**
     * Initializer, set the mp manually
     * @param mp mp
     */
    font(map<char, tuple<surface, int, int> > mp): mp(mp) {}
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
            drawTo(get<0>(mp[i]), res, p);
            p.y += get<2>(mp[i]);
        }
        return res;
    }
};