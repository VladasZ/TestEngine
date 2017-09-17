//
//  Buffer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Buffer.hpp"
#include "Debug.hpp"

Buffer::Buffer(const BufferData &data) : data(data) {
    
    
    glGenVertexArrays(1, &vertexArrayObject);
    glGenBuffers(1, &vertexBufferObject);
    glGenBuffers(1, &indexBufferObject);
    
    glBindVertexArray(vertexArrayObject);
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, data.vertSize, data.vertData, GL_STATIC_DRAW);
    glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          3 * sizeof(GLfloat),
                          NULL);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.indSize, data.indData, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

Buffer::Buffer(GLfloat *vertData, GLuint vertSize) : Buffer(BufferData(vertData, vertSize)) {
    
}

Buffer::Buffer(GLfloat *vertData, GLuint vertSize,
               GLushort *indData,  GLuint indSize) : Buffer(BufferData(vertData, vertSize, indData, indSize)) {
    
}

Buffer::~Buffer() {
    
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteBuffers(1, &vertexBufferObject);
    if (indexBufferObject != 0) glDeleteBuffers(1, &indexBufferObject);
}

void Buffer::draw() const {
 
    glBindVertexArray(vertexArrayObject);
    
    if (data.indSize == 0) {
        
        glDrawArrays(drawMode, 0, data.vertSize);
    }
    else {
        
        glDrawElements(drawMode, data.indSize, GL_UNSIGNED_SHORT, 0);
    }
    
    glBindVertexArray(0);
}
