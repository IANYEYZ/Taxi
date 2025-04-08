#include "src/taxi.hpp"
#include "src/plugin/node/tnode.hpp"
#include "src/plugin/ui/tui.hpp"
#include <bits/stdc++.h>
using namespace std;
tostream tout;
void f(int cnt) {
    // writeTo("Hello world!", screen, {0, 0});
    tout << pos(0, 0) << "Hello world";
    cout << tout.getSurface()[0][0];
    screen = tout.getSurface();
}
int main() {
    if (!init() || !initNode()) {
        printf("Error on initializing");
        return 0;
    }
    // closeFastEdit();
    // std::cout << "HERE!" << std::endl;
    screen = makeSurface(20, 20);
    tout = tostream(screen);
    clear();
    hideCursor();
    setFPS(60);
    loopEvent.subscribe(f);
    return mainloop<diffRender>();
}