#include "src/taxi.hpp"
#include "src/plugin/node/tnode.hpp"
#include "src/plugin/ui/tui.hpp"
#include <bits/stdc++.h>
using namespace std;
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
    writeTo("Hello, world!", screen, {0, 0});
    return mainloop<diffRender>();
}