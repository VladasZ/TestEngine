//
//  Color.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Array.hpp"
#include "Color.hpp"
#include "System.hpp"

using namespace std;

Color::Color(Color const &obj) {
    r = obj.r;
    g = obj.g;
    b = obj.b;
    a = obj.a;
}

Color& Color::operator=(Color const &obj) {
    r = obj.r;
    g = obj.g;
    b = obj.b;
    a = obj.a;
    return *this;
}

Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) { }

Color Color::random() {

    static const Array<Color> colors = {
        black,
        white,
        red,
        green,
        blue,
        lightBlue,
        yellow,
        orange,
        purple,
        turquoise,
        lightGray
    };

    return colors.random();
}

Color Color::withAlpha(float alpha) const {
    return Color(r, g, b, alpha);
}

String Color::toString() const {
    return "r: "_s + r + " g: " + g + " b: " + b + " a: " + a;
}

bool Color::isTransparent() const {
    return this->a <= 0.02;
}

const Color Color::black     = Color(0,    0,    0);
const Color Color::white     = Color(1,    1,    1);
const Color Color::red       = Color(1,    0,    0);
const Color Color::green     = Color(0,    1,    0);
const Color Color::blue      = Color(0,    0   , 0.8f);
const Color Color::lightBlue = Color(0,    0,    1);
const Color Color::yellow    = Color(1,    1,    0);
const Color Color::orange    = Color(1,    0.5f, 0);
const Color Color::purple    = Color(1,    0,    1);
const Color Color::turquoise = Color(0,    1,    1);
const Color Color::gray      = Color(0.5f, 0.5f, 0.5f);
const Color Color::lightGray = Color(0.8f, 0.8f, 0.8f);
const Color Color::clear     = Color(0,    0,    0, 0);