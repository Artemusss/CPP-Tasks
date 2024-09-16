# cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

cmake_minimum_required(VERSION 3.11)

 set(CMAKE_CXX_STANDARD 17)

 set(CMake_CXX_Compiler g++)

project(LFU_cache_&_analysis)

set(INC_DIR
    ${CMAKE_SOURCE_DIR} ./include
)

include_directories(${INC_DIR})

set(SOURCE
    ./source/cache.cpp
)

add_library(LFU STATIC ${SOURCE})

add_executable(lfu.x main.cpp)
target_link_libraries(lfu.x LFU)