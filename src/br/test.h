#pragma once

#include "RwLock.h"
#include <cstdint>
#include "config.h"

namespace GuideCraft {
    class test 
    {
    public:
        char buf[LIMIT_MESSAGE_SIZE];
        void *ptr;
        RwLock lock;
    public:
        void read(void* shmem, void* usrmem, size_t size);
        void write(void* shmem, void* usrmem, size_t size); 
    };
    
}; 
