//
//  File.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "String.hpp"
#include "TestObject.hpp"


class File MEMORY_MANAGED(File) {
    
    size_t _size;
    std::byte *_data;
    
public:
    
    size_t getSize() const;
    std::byte *getData() const;

    File() = default; //FIX
    File(const std::string &path);
    ~File();
};
