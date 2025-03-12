#pragma once
#include "../tinclude.hpp"
/**
 * Class of position, which is the same as pair<int, int> just with a more reasonable naming in this specific case
 */
struct pos {
    int x, y;
    /**
     * Initializing the class with default value(x = 0, y = 0)
     */
    pos(): x(0), y(0) {}
    /**
     * Initializing the class with custom value
     * @param x the x coordinate of this pos object
     * @param y the y coordinate of this pos object
     */
    pos(int x, int y): x(x), y(y) {}
    /**
     * Initializing the class with a pair<int, int>
     * @param p the coordinate of this pos object where x is set to p.first, y is set to p.second
     */
    pos(pair<int, int> p): x(p.first), y(p.second) {}
};