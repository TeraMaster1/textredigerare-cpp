cmake_minimum_required(VERSION 4.0)
project(textredigerare_cpp)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CURSES_USE_NCURSES TRUE)
find_package(Curses REQUIRED)
add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)

add_executable(textredigerare_cpp src/main.cpp
    src/EditorBuffer.cpp
    src/EditorBuffer.h
    src/Interface.cpp
    src/Interface.h)

target_include_directories(textredigerare_cpp PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(textredigerare_cpp PRIVATE ${CURSES_LIBRARIES})
