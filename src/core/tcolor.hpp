#pragma once
#include "../tinclude.hpp"
/**
 * Color class, store a color that can be set as either background color or foreground color
 * @ingroup core
 */
struct color {
    char r, g, b;
    /**
     * Initialize the class with default value(#000000)
     */
    color() { r = 0, g = 0, b = 0; }
    /**
     * Initialize the class with three int value
     * @param r the r value of the color in rgb color model
     * @param g the g value of the color in rgb color model
     * @param b the b value of the color in rgb color model
     */
    color(int r, int g, int b):r(r), g(g), b(b) {}
    /**
     * Initialize the class with three char value
     * @param r the r value of the color in rgb color model
     * @param g the g value of the color in rgb color model
     * @param b the b value of the color in rgb color model
     */
    color(char r, char g, char b):r(r), g(g), b(b) {}
    /**
     * Initialize the class with another color
     * @param c the other color used to initializing this class
     */
    color(const color& c):r(c.r), g(c.g), b(c.b) {}
    /**
     * Initialize the class with a string
     * @param s the HEX representation of the color, can be either three character long or six character long
     */
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
    /**
     * Set the color as background color
     */
    void setAsBG() const {
        printf("\x1b[48;2;%d;%d;%dm", r, g, b);
    }
    /**
     * Set the color as foreground color
     */
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