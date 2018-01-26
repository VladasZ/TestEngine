//
//  ImageView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "ImageView.hpp"
#include "Buffer.hpp"
#include "Image.hpp"
#include "Shader.hpp"
#include "BufferData.hpp"

ImageView::~ImageView() {
    //if (image != nullptr) delete image;
}

BufferData * ImageView::getBufferData() {
    
    Rect frame = absoluteFrame();
    
    GLfloat vertices[] = {
        frame.origin.x,                    frame.origin.y,                     0.0f, 0.0f,
        frame.origin.x,                    frame.size.height + frame.origin.y, 0.0f, 1.0f,
        frame.size.width + frame.origin.x, frame.size.height + frame.origin.y, 1.0f, 1.0f,
        frame.size.width + frame.origin.x, frame.origin.y,                     1.0f, 0.0f
    };
    
    GLushort indices[] = { 0, 1, 2, 3 };

    return new BufferData(vertices, sizeof(vertices),
                          indices,  sizeof(indices));
}

void ImageView::setupBuffer() {
    delete buffer;
    buffer = new Buffer(getBufferData(), BufferConfiguration(2, 2));
}

void ImageView::draw() {
    
    if (image == nullptr) { View::draw(); return; }
    if (!color.isTransparent()) View::draw();
        
    View::drawSubviews();
    
    image->bind();
    buffer->draw();
    image->unbind();
}

void ImageView::setImage(Image *image) {
    
    this->image = image;
}

