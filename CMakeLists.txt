cmake_minimum_required(VERSION 4.0)
project(textredigerare_cpp)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Curses REQUIRED)
add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)

add_executable(textredigerare_cpp src/main.cpp
    src/EditorBuffer.cpp
    src/EditorBuffer.h)
