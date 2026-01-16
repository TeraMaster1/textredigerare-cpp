cmake_minimum_required(VERSION 4.0)
project(textredigerare_cpp)

set(CMAKE_CXX_STANDARD 26)

add_executable(textredigerare_cpp main.cpp
    EditorBuffer.cpp
    EditorBuffer.h)
