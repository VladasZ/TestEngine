//
//  BufferConfiguration.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

class Buffer;

class BufferConfiguration {
    
    int configuration[3];
    int size = 1;
    
    int vertexSize = 0;
    
    int strideForIndex(int index) const;
    
    void setPointers() const;

    friend Buffer;

    BufferConfiguration(int firstParam, int secondParam, int thirdParam);
    
public:

    static inline const BufferConfiguration _2   = { 2, 0, 0 };
    static inline const BufferConfiguration _2_2 = { 2, 2, 0 };
};
