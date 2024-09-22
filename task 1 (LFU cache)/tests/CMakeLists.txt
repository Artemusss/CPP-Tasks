# cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build

cmake_minimum_required(VERSION 3.11)

 set(CMAKE_CXX_STANDARD 17)

project(Testing)

set(INC_DIR
    ${CMAKE_SOURCE_DIR} ../include
)

include_directories(${INC_DIR})

set(SOURCE
    ../best_cache/best_cache.cpp
    ../source/cache.cpp
)

add_library(TEST STATIC ${SOURCE})

add_executable(test.x testing.cpp)
target_link_libraries(test.x TEST)