#pragma once
#include "../tinclude.hpp"
struct pos {
    int x, y;
    pos(): x(0), y(0) {}
    pos(int x, int y): x(x), y(y) {}
    pos(pair<int, int> p): x(p.first), y(p.second) {}
};