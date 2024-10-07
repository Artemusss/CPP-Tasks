cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 20)

project(LFU_cache_&_analysis)

set(INC_DIR
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(lfu.x ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_include_directories(lfu.x PRIVATE ${INC_DIR}) #+ PRIVATE, PUBLIC, INTERFACE: find out the difference
