//
//  Color.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "STL.hpp"
#include "GL.hpp"
#include "Types.h"

class Color {
    
public:
    
    vec4 data;
    
    Float &r;
    Float &g;
    Float &b;
    Float &a;
    
    Float *dataBuffer;
    
    Color(Color const &obj);
    Color& operator=(Color const &obj);
    
    Color();
    Color(Float r, Float g, Float b, Float a = 1);
    
    static Color random();
    
    string toString() const;
    
    static const Color black;
    static const Color white;
    static const Color red;
    static const Color green;
    static const Color blue;
    static const Color yellow;
    static const Color orange;
    static const Color purple;
    static const Color turquoise;
    static const Color gray;
};