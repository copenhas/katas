project(poker)
cmake_minimum_required(VERSION 2.8)


if(APPLE)
    set (CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
endif()

add_subdirectory(src)
add_subdirectory(tests)
