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
#include "FrameBuffer.hpp"
#include "Debug.hpp"

ImageView::~ImageView() { }

void ImageView::draw() {
    
    if (_image == nullptr) { View::draw(); return; }
    if (!color.isTransparent()) View::draw();
           
    _getFrameBuffer()->draw([&] {
        _image->bind();
        if (_image->isMonochrome()) Shader::uiMonochrome.use();
        else                        Shader::uiTexture.use();
        _frameBufferFrame.setViewport();
        Buffer::fullscreenImage->draw();
        _image->unbind();
    });

    View::drawSubviews();
}

Image * ImageView::getImage() const {
    return _image;
}

ImageView * ImageView::setImage(Image *image) {
    this->_image = image;
    return this;
}
