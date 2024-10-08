cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 20)
project(Testing)

set(INC_DIR
    ${CMAKE_SOURCE_DIR} ../include
)

include_directories(${INC_DIR})

set(SOURCE
    ../best_cache/best_cache.cpp
)

add_library(TEST STATIC ${SOURCE})

add_executable(test.x testing.cpp)
target_include_directories(lfu.x PRIVATE ${INC_DIR})