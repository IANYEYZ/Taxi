#include "src/taxi.hpp"
#include "src/plugin/node/tnode.hpp"
#include <bits/stdc++.h>
using namespace std;
surface img1 = surface({
    {Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  ")},
    {Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  ")},
    {Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  ")}
}, Char(color("#000000"), color("#ffffff"), "  "));
surface img2 = surface({
    {Char(color("#FF00FF"), color("#ffffff"), "  "), Char(color("#FF00FF"), color("#ffffff"), "  "), Char(color("#FF00FF"), color("#ffffff"), "  ")},
    {Char(color("#FF00FF"), color("#ffffff"), "  "), Char(color("#FF00FF"), color("#ffffff"), "  "), Char(color("#FF00FF"), color("#ffffff"), "  ")},
    {Char(color("#FF00FF"), color("#ffffff"), "  "), Char(color("#FF00FF"), color("#ffffff"), "  "), Char(color("#FF00FF"), color("#ffffff"), "  ")}
}, Char(color("#000000"), color("#ffffff"), "  "));
surface img3 = surface({
    {Char(color("#FFFF00"), color("#ffffff"), "  "), Char(color("#FFFF00"), color("#ffffff"), "  "), Char(color("#FFFF00"), color("#ffffff"), "  ")},
    {Char(color("#FFFF00"), color("#ffffff"), "  "), Char(color("#FFFF00"), color("#ffffff"), "  "), Char(color("#FFFF00"), color("#ffffff"), "  ")},
    {Char(color("#FFFF00"), color("#ffffff"), "  "), Char(color("#FFFF00"), color("#ffffff"), "  "), Char(color("#FFFF00"), color("#ffffff"), "  ")}
}, Char(color("#000000"), color("#ffffff"), "  "));
animatedSprite* s = new animatedSprite({img1, img1, img1, img1, img1, img2, img2, img2, img2, img2});
animatedSprite* s1 = new animatedSprite({img2, img2, img2, img2, img2, img3, img3, img3, img3, img3});
void spriteInit() {
}
void f(int cnt) {
    if (Input.isKeyPressed('A')) {
        s -> move({0, -1});
    } else if (Input.isKeyPressed('D')) {
        s -> move({0, 1});
    } else if (Input.isKeyPressed('W')) {
        s -> move({-1, 0});
    } else if (Input.isKeyPressed('S')) {
        s -> move({1, 0});
    }
}
void g(int cnt) {
    if (Input.isKeyPressed(VK_LEFT)) {
        s1 -> move({0, -1});
    } else if (Input.isKeyPressed(VK_RIGHT)) {
        s1 -> move({0, 1});
    } else if (Input.isKeyPressed(VK_UP)) {
        s1 -> move({-1, 0});
    } else if (Input.isKeyPressed(VK_DOWN)) {
        s1 -> move({1, 0});
    }
}
int main() {
    if (!init() || !initNode()) {
        printf("Error on initializing");
        return 0;
    }
    clear();
    hideCursor();
    screen = makeSurface(100, 100, Char(color("#000000"), color("#ffffff"), "  "));
    s -> bind(spriteInit, f);
    s1 -> bind(spriteInit, g);
    registerNode(s);
    registerNode(s1);
    // loopEvent.subscribe(f);
    cursorPosPreprocessor = y2;
    setFPS(60);
    return mainloop<diffRender>();
}