cmake_minimum_required(VERSION 3.11)

 set(CMAKE_CXX_STANDARD 20)

project(Ideal_hash_hits)

set(SOURCE
    ${CMAKE_SOURCE_DIR}/src/ideal_cache.cpp
)

add_library(IDEAL STATIC ${SOURCE})

add_executable(ideal.x ${CMAKE_SOURCE_DIR}/src/main_ideal_cache.cpp)
target_link_libraries(ideal.x IDEAL)