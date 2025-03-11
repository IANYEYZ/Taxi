#pragma once
#include "../tinclude.hpp"
#include "../core/tcore.hpp"
#include "../core/tpos.hpp"

/**
 * The surface, anything drawn to the console with the renderer, in theory, all first be drawn on to a surface
 * This is the most "trivial" surface, which is basically just a `vector<vector<Char> >` and another `Char`(as the background)
 * @ingroup surface
 */
class surface: public vector<vector<Char> > {
    public:
    Char bg;
    /**
     * Initializer, initialize it with empty bg and vector
     */
    surface() {}
    /**
     * Initializer, initialize with a vector and a background Char
     * @param sur the surface that's initialized to
     * @param bg the Char that the background is set to
     */
    surface(vector<vector<Char> > sur, Char bg): vector<vector<Char> >(sur), bg(bg) {}
    /**
     * make another surface with the given height and width, filled with the background Char
     * @param height the height of the new surface
     * @param width the width of the new surface
     */
    surface makeSurface(int height, int width) {
        vector<vector<Char> > res = vector<vector<Char> >(height, vector<Char>(width, this -> bg));
        return surface(res, bg);
    }
};
surface screen;

/**
 * Render `from` to `to` at position p, `from` and `to` are both passed by refrence because that make polymorphism eaiser
 * @param from the surface that need to be rendered to `to`
 * @param to the final surface
 * @param p the position that `from` need to be drawn to
 * @ingroup surface
 */
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
/**
 * Make a surface with the given height, width, and background Char
 * @param height the height of the new surface
 * @param width the width of the new surface
 * @param bgChar the background Char
 * @ingroup surface
 */
surface makeSurface(int height, int width, Char bgChar = Char()) {
    return surface(vector<vector<Char> >(height, vector<Char>(width, bgChar)), bgChar);
}