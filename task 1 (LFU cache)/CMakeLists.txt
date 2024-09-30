cmake_minimum_required(VERSION 3.11)

 set(CMAKE_CXX_STANDARD 20)

project(LFU_cache_&_analysis)

set(INC_DIR
    ${CMAKE_SOURCE_DIR} ./include
)

include_directories(${INC_DIR})

add_executable(lfu.x main.cpp)
target_link_libraries(lfu.x LFU)