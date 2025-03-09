#include "src/taxi.hpp"
#include "src/plugin/node/tnode.hpp"
#include "src/plugin/ui/tui.hpp"
#include <bits/stdc++.h>
using namespace std;
surface img1 = surface({
    {Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  ")},
    {Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  ")},
    {Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  "), Char(color("#00FFFF"), color("#ffffff"), "  ")}
}, Char(color("#000000"), color("#ffffff"), "  "));
UISurface ui;
button* b = new button(img1, {0, 0});
void f() {
    // printf("Clicked!");
}
void renderUI(int cnt) {
    renderTo(ui, screen, {0, 0});
    // b -> render(screen);
}
int main() {
    if (!init() || !initNode()) {
        printf("Error on initializing");
        return 0;
    }
    closeFastEdit();
    // std::cout << "HERE!" << std::endl;
    screen = makeSurface(30, 30);
    clear();
    hideCursor();
    setFPS(60);
    cursorPosPreprocessor = y2;
    b -> clickEvent.subscribe(f);
    ui = ui.makeSurface(30, 30);
    ui.registerUIElement(b);
    ui.bind();
    loopEvent.subscribe(renderUI);
    return mainloop<diffRender>();
}