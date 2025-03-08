#pragma once
#include "../../taxi.hpp"

class node {
    public:
    pos p;
    public:
    node() {}
    virtual void render(surface &sfc) = 0;
    void move(pos dp) {
        p.x += dp.x;
        p.y += dp.y;
    }
    void moveTo(pos np) {
        p = np;
    }
    void bind(function<void()> init, function<void(int)> loop) {
        loopEvent.subscribe(loop);
        initEvent.subscribe(init);
    }
};
class sprite: public node {
    protected:
    surface img;
    public:
    sprite(surface sfc): img(sfc) {}
    void render(surface &sfc) override {
        renderTo(img, sfc, p);
    }
};

vector<node*> nodeList;
void registerNode(node *nd) {
    nodeList.push_back(nd);
}
void renderAll(int cnt) {
    screen = screen.makeSurface(screen.size(), screen[0].size());
    for (auto i:nodeList) {
        // printf("outputed! %d", cnt);
        i -> render(screen);
    }
}
bool initNode() {
    loopEvent.subscribe(renderAll);
    return true;
}