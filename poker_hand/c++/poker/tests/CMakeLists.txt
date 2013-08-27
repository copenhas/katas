project(poker_tests)
cmake_minimum_required(VERSION 2.8)

if(APPLE)
    set (CMAKE_CXX_FLAGS "-g -std=c++11 -stdlib=libc++")
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
endif()

add_subdirectory(gmock)
include_directories(${libpoker_SOURCE_DIR})

include_directories(
    SYSTEM
    ${gtest_SOURCE_DIR}
    ${gtest_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}
    ${gmock_SOURCE_DIR}/include
    )

file(GLOB SOURCES *.h *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES}
                               ${gtest_SOURCE_DIR}/src/gtest_main.cc)

target_link_libraries(${PROJECT_NAME}
    poker
    gmock_main )
