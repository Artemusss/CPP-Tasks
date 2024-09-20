# cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

cmake_minimum_required(VERSION 3.11)

 set(CMAKE_CXX_STANDARD 17)

 set(CMake_CXX_Compiler g++)

project(Best_hash_hits)

set(SOURCE
    best_cache.cpp
)

add_library(BEST STATIC ${SOURCE})

add_executable(best.x main_best_cache.cpp)
target_link_libraries(best.x BEST)