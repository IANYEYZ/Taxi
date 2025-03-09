#pragma once
#include "../tinclude.hpp"
#include "../core/tcore.hpp"
#include "../core/tpos.hpp"

class surface: public vector<vector<Char> > {
    public:
    Char bg;
    surface() {}
    surface(vector<vector<Char> > sur, Char bg): vector<vector<Char> >(sur), bg(bg) {}
    surface makeSurface(int height, int width) {
        vector<vector<Char> > res = vector<vector<Char> >(height, vector<Char>(width, this -> bg));
        return surface(res, bg);
    }
};
surface screen;

void renderTo(surface &from, surface& to, pos p) {
    // This validate the coordinate
    // If only part can be rendered, only render the renderable part
    // If no part can be rendered, no will be rendered
    // If all can be rendered, all will be rendered
    for (int i = 0; i < from.size(); i++) {
        for (int j = 0; j < from.size(); j++) {
            int x = p.x + i;
            int y = p.y + j;
            if (x >= to.size() || y >= to[0].size()) { continue; }
            to[x][y] = from[i][j];
        }
    }
}
surface makeSurface(int height, int width, Char bgChar = Char()) {
    return surface(vector<vector<Char> >(height, vector<Char>(width, bgChar)), bgChar);
}