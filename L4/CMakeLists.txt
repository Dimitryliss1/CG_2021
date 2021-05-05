cmake_minimum_required(VERSION 3.15)
project(L4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(L4
        line.cpp
        line.h
        main.cpp
        matrix.cpp
        matrix.h
        pyramid.cpp
        pyramid.h
        triangle.cpp
        triangle.h)

include_directories(/usr/local/include/)
include_directories(/usr/local/Cellar/sdl2/2.0.14_1/lib)
target_link_libraries(L4 /usr/local/lib/libSDL_bgi.so /usr/local/Cellar/sdl2/2.0.14_1/lib/libSDL2.a -L.)