//
//  Path.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 09/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"
#include "Rect.hpp"
#include "Drawable.hpp"
#include "Array.hpp"

class Buffer;
class View;

enum PathDrawMode {
    Fill,
    Stroke
};

class Path : public Drawable {
    
    Array<Point> points;
    
//    BufferData* getBufferData() override;
    bool bufferIsSet = false;
    
    static Path* circleWith(const Point &center, float radius, int precision);

public:
    
    float lineWidth = 1;
    PathDrawMode drawMode;
    
    void draw() override;

    Path() = default;
    Path(const Rect &rect);
    static Path* circleWith(const Point &center, float radius);
    
    void addPoint(float x, float y);
};
