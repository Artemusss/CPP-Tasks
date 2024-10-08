cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 20)
project(Testing)

set(INC_DIR
    ${CMAKE_SOURCE_DIR} ../include
)

include_directories(${INC_DIR})

set(SOURCE
    ../ideal_cache/src/ideal_cache.cpp
)

add_library(TEST STATIC ${SOURCE})

add_executable(test.x ${CMAKE_SOURCE_DIR}/src/testing.cpp)
target_include_directories(test.x PRIVATE ${INC_DIR})