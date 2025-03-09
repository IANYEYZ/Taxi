#pragma once
#include "../tinclude.hpp"
#include "../core/tcore.hpp"
#include "../surface/tsurface.hpp"
#include "../event/tevent.hpp"

class render {
    // virtual class as interface
    public:
    virtual void loop(surface sfc, pos p) = 0;
};
class diffRender: public render {
    // Difference rendering, only render needing part
    surface lst;
    public:
    diffRender() {}
    void loop(surface sfc, pos p) override {
        if (lst.size() == 0) {
            lst = sfc.makeSurface(sfc.size(), sfc[0].size());
        }
        if (sfc.size() != lst.size() || sfc[0].size() != lst[0].size()) {
            throw "surface should has same size when using diffRender";
        }
        for (int i = 0; i < sfc.size(); i++) {
            for (int j = 0; j < sfc[0].size(); j++) {
                if (sfc[i][j] != lst[i][j]) {
                    // printf("%d %d", i, j);
                    cursor({p.x + i + 1, p.y + j});
                    sfc[i][j].print();
                }
            }
        }
        lst = sfc;
    }
};
class nothingRender: public render {
    // A renderer that do nothing
    // For debug purpose
    public:
    nothingRender() {}
    void loop(surface sfc, pos p) override {}
};

double waiting;
void setFPS(double FPS) {
    waiting = 1000.0 / FPS;
}

bool taxiRunning = true;
template <typename T>
int mainloop() {
    // Use template to do duck typing
    T renderer;
    int cnt = 0;
    initEvent.emit();
    while (taxiRunning) {
        loopEvent.emit(cnt);
        renderer.loop(screen, pos(0, 0));
        cnt++;
        Sleep((int)waiting);
    }
    return 0;
}