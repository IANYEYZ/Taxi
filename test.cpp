#include "src/taxi.hpp"
#include <bits/stdc++.h>
using namespace std;
surface img1 = surface({
    {Char(color("#ffffff"), color("#30C5FF"), "  ")}
}, Char(color("#000000"), color("#ffffff"), "  "));
sprite* s = new sprite(img1);
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
int main() {
    if (!init()) {
        printf("Error on initializing");
        return 0;
    }
    clear();
    screen = makeSurface(100, 100, Char(color("#000000"), color("#ffffff"), "  "));
    s -> bind(spriteInit, f);
    registerNode(s);
    loopEvent.subscribe(f);
    cursorPosPreprocessor = y2;
    setFPS(60);
    return mainloop<diffRender>();
}