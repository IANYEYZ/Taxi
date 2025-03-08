#pragma once
#include "../../taxi.hpp"

class UIElement {
    public:
    virtual void render(surface &sfc) = 0;
};
class button: UIElement {
};
class UISurface: public surface {
    private:
    vector<UIElement*> UIList_;
    public:
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
    }
};