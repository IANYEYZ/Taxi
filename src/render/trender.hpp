#pragma once
#include "../tinclude.hpp"
#include "../core/tcore.hpp"
#include "../surface/tsurface.hpp"
#include "../event/tevent.hpp"

/**
 * The base class of renderer
 * @ingroup renderer
 */
class render {
    // virtual class as interface
    public:
    /**
     * virtual function
     * @param sfc the surface
     * @param p the position the surface needed to be rendered to
     */
    virtual void loop(surface sfc, pos p) = 0;
};
/**
 * Renders only the "different" part of this and last frame
 * @ingroup renderer
 */
class diffRender: public render {
    // Difference rendering, only render needing part
    surface lst;
    public:
    diffRender() {}
    /**
     * inplemented the `loop` functionn
     * use double buffering, the lst buffer stores the last frame/empty frame
     * @param sfc the surface
     * @param p the position the surface needed to be rendered to
     */
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
/**
 * Renders nothing
 * @ingroup renderer
 */
class nothingRender: public render {
    // A renderer that do nothing
    // For debug purpose
    public:
    nothingRender() {}
    /**
     * Ignore the sfc and p, render nothing
     * @param sfc the surface
     * @param p the position the surface needed to be rendered to
     */
    void loop(surface sfc, pos p) override {}
};

double waiting;
/**
 * Set the FPS
 * @param FPS the number of frames in one second
 * @ingroup renderer
 */
void setFPS(double FPS) {
    waiting = 1000.0 / FPS;
}

bool taxiRunning = true;
/**
 * the mainloop function, implement the mainloop
 * In one loop, the following things happens in order:
 * 1. the loopEvent is emitted
 * 2. the renderer is called
 * 3. the cnt(frame count) is incremented & call the sleep() to maintain the FPS
 * @tparam T the renderer you are going to use(this is a template parameter because then duck typing will be eaiser)
 * @ingroup renderer
 */
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