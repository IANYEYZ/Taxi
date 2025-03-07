// simple event system
#pragma once
#include "../tinclude.hpp"
template <typename T = void>
class Event {
    private:
    vector<function<void(T)> > v;
    public:
    Event() {}
    void emit(T val) {
        for (auto i:v) {
            i(val);
        }
    }
    void subscribe(function<void(T)> f) {
        v.push_back(f);
    }
};
template <>
class Event<void> {
    private:
    vector<function<void()> > v;
    public:
    Event() {}
    void emit() {
        for (auto i:v) {
            i();
        }
    }
    void subscribe(function<void()> f) {
        v.push_back(f);
    }
};
Event<int> loopEvent;
Event<void> initEvent;