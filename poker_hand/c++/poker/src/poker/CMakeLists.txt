project(libpoker)
file(GLOB SOURCES *.h *.cpp)
add_library(poker STATIC ${SOURCES})
