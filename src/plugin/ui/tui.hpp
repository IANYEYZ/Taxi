#pragma once
#include "../../taxi.hpp"

class UIElement {
    public:
    virtual void render(surface &sfc) = 0;
    virtual void loop(int cnt) = 0;
};
class button: public UIElement {
    private:
    surface img;
    int height, width;
    pos p;
    public:
    Event<void> clickEvent;
    button(surface &img, pos p): img(img), height(img.size()), width(img[0].size()), p(p) {}
    void render(surface &sfc) override {
        renderTo(img, sfc, p);
    }
    void loop(int cnt) override {
        if (Input.isKeyPressed(VK_LBUTTON)) {
            pos mouseP = Input.getMousePosition();
            if (mouseP.x >= p.x && mouseP.x <= (p.x + height) && mouseP.y >= p.y && mouseP.y <= (p.y + width)) {
                clickEvent.emit();
            }
        }
    }
};
class UISurface: public surface {
    private:
    vector<UIElement*> UIList_;
    public:
    UISurface() {}
    UISurface(vector<vector<Char> > sur, Char bg): surface(sur, bg) {}
    void registerUIElement(UIElement* ui) {
        UIList_.push_back(ui);
    }
    void renderAll(int cnt) {
        for (auto i:UIList_) {
            i -> render(*this);
        }
    }
    void bind() {
        loopEvent.subscribe([this](int cnt){ this -> renderAll(cnt); });
        for (auto i:UIList_) {
            loopEvent.subscribe([i](int cnt){ i -> loop(cnt); });
        }
    }
    UISurface makeSurface(int height, int width) {
        vector<vector<Char> > res = vector<vector<Char> >(height, vector<Char>(width, this -> bg));
        return UISurface(res, bg);
    }
};