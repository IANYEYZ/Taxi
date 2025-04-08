#include "src/taxi.hpp"
#include "src/plugin/node/tnode.hpp"
#include "src/plugin/ui/tui.hpp"
#include <bits/stdc++.h>
using namespace std;
void f(int cnt) {
    writeTo("Hello world!", screen, {0, 0});
}
int main() {
    if (!init() || !initNode()) {
        printf("Error on initializing");
        return 0;
    }
    // closeFastEdit();
    // std::cout << "HERE!" << std::endl;
    screen = makeSurface(20, 20);
    clear();
    hideCursor();
    setFPS(60);
    loopEvent.subscribe(f);
    return mainloop<diffRender>();
}