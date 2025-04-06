#include "src/taxi.hpp"
#include "src/plugin/node/tnode.hpp"
#include "src/plugin/ui/tui.hpp"
#include <bits/stdc++.h>
using namespace std;
surface surf = makeSurface(1, 1, Char(color("#111111"), color("#00ff00"), "a"));
void f(int cnt) {
    // drawTo(makeSurface(1, 1, Char(color("#111111"), color("#00ff00"), "a")), screen, {0, 0});
    writeTo("hello world", screen, {0, 0});
    // screen[0][0] = Char(color("#111111"), color("#00ff00"), "a");
    // screen[0][0].print();
}
int main() {
    if (!init() || !initNode()) {
        printf("Error on initializing");
        return 0;
    }
    // closeFastEdit();
    // std::cout << "HERE!" << std::endl;
    screen = makeSurface(10, 10);
    clear();
    hideCursor();
    setFPS(60);
    // cout << surf[0].size() << "\n";
    renderTo(surf, screen, {0, 0});
    // cout << screen[0][0] << "\n";
    writeTo("hello world", screen, {0, 0});
    // while (true) {}
    // writeTo("Hello, world!", screen, {0, 0});
    loopEvent.subscribe(f);
    return mainloop<diffRender>();
}