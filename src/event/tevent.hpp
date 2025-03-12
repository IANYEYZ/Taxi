// simple event system
#pragma once
#include "../tinclude.hpp"
/**
 * The event object, functions can subscribed to it to listen to this event
 * @tparam T the type of value that's passed to functions that subscribe to the event, if it's given empty or void, then no value will be passed to functions
 */
template <typename T = void>
class Event {
    private:
    vector<function<void(T)> > v;
    public:
    /**
     * Initialize the Event object
     */
    Event() {}
    /**
     * Emit(trigger) the event, calling all the functions that subscribes to it
     */
    void emit(T val) {
        for (auto i:v) {
            i(val);
        }
    }
    /**
     * Let a function subscribe to this Event object
     * @param f the function that'll subscribe to the Event object
     */
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