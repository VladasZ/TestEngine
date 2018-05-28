//
//  MemoryManaged.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "MemoryManager.hpp"

#if MEMORY_TRACKING

#include "Log.hpp"
#include "ClassMemoryInfo.hpp"

#define  MEMORY_MANAGED(class) : public MemoryManaged<class>
#define _MEMORY_MANAGED(class) , public MemoryManaged<class>

#else

#define  MEMORY_MANAGED(class)
#define _MEMORY_MANAGED(class)

#endif

#if MEMORY_TRACKING

template <class T>
class MemoryManaged {
    
    static std::string className;
    static int *allocated;
    static int *deleted;
    
    
public:
    
    int _memoryID;
    
    static int leaked() {
        return allocated - deleted;
    }
    
    MemoryManaged() {
        if (!MemoryManager::isTracking) return;
        if (allocated == nullptr) {
            Error("31 Initialized class: " << MemoryManaged<T>::className);
            return;
        }
        
#if FULL_MEMORY_OUTPUT
        _memoryID = *allocated;
        Log(MemoryManaged<T>::className << " allocated: " << _memoryID);
#endif
        
        (*allocated)++;
        MemoryManager::totalObjectsAllocated++;
    }
    
    virtual ~MemoryManaged() {
        if (!MemoryManager::isTracking) return;
        if (deleted == nullptr) return;
#if FULL_MEMORY_OUTPUT
        Log(MemoryManaged<T>::className << " deleted:" << _memoryID);
#endif
        (*deleted)++;
        MemoryManager::totalObjectsDeleted++;
    }
};

template <class T>
std::string MemoryManaged<T>::className = []() {
    auto info = new ClassMemoryInfo(typeid(T).name());
    //Log("48 Initialized class: " << info->className);
    allocated = &info->allocated;
    deleted = &info->deleted;
    MemoryManager::info.push_back(info);
    return info->className;
}();

template <class T>
int * MemoryManaged<T>::allocated;

template <class T>
int * MemoryManaged<T>::deleted;

#endif