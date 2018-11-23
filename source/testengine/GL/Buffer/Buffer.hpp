//
//  Buffer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "GL.hpp"
#include "NonCopyable.hpp"
#include "BufferData.hpp"
#include "BufferConfiguration.hpp"

class Buffer : public NonCopyable {
    
    BufferData* data;
    
    GLuint vertexArrayObject = 0;
    GLuint vertexBufferObject = 0;
    GLuint indexBufferObject = 0;
    
    int verticesCount = 0;
    int indicesCount = 0;

public:
    
    GLenum drawMode = GL_TRIANGLE_STRIP;
    
    Buffer(BufferData* data, const BufferConfiguration &configuration);
    
    Buffer(GLfloat* vertData, GLuint vertSize, const BufferConfiguration &configuration);
    
    Buffer(GLfloat* vertData, GLuint vertSize,
           GLushort* indData, GLuint indSize,
           const BufferConfiguration &configuration);

    ~Buffer();
        
    void draw() const;

    static void initialize();

    static void windowSizeChanged();

    static inline Buffer* fullscreen        = nullptr;
    static inline Buffer* fullscreenImage   = nullptr;
    static inline Buffer* fullscreenOutline = nullptr;
    static inline Buffer* rootUIBuffer      = nullptr;
};