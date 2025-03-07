#pragma once
#include "../tinclude.hpp"
struct color {
    char r, g, b;
    color() {}
    color(int r, int g, int b):r(r), g(g), b(b) {}
    color(char r, char g, char b):r(r), g(g), b(b) {}
    color(const color& c):r(c.r), g(c.g), b(c.b) {}
    color(string s) {
        s = s.substr(1);
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        if (s.size() == 3) {
            string s1 = "";
            s1 += s[0]; s1 += s[0];
            s1 += s[1]; s1 += s[1];
            s1 += s[2]; s1 += s[2];
            s = s1;
        }
        r = s[0] * 15 + s[1];
        g = s[2] * 15 + s[3];
        b = s[4] * 15 + s[5];
    }
    void setAsBG() const {
        printf("\x1b[48;2;%d;%d;%dm", r, g, b);
    }
    void setAsFG() const {
        printf("\x1b[38;2;%d;%d;%dm", r, g, b);
    }
    color operator=(color rhs) {
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;
        return *this;
    }
    bool operator==(color rhs) {
        return (r == rhs.r && b == rhs.b && g == rhs.g);
    }
    bool operator!=(color rhs) {
        return !(*this == rhs);
    }
};