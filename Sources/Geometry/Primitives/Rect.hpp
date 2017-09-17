//
//  Rect.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"
#include "Size.hpp"
#include "BufferData.hpp"

class Rect {
    
public:
    
    Point origin;
    Size size;
    
    Rect() = default;
    Rect(Float width, Float height);
    Rect(Float x, Float y, Float width, Float height);
    
    BufferData getData() const;
};
