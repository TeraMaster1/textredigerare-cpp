cmake_minimum_required(VERSION 4.0)
project(textredigerare_cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)


add_executable(textredigerare_cpp src/main.cpp
    src/EditorBuffer.cpp
    src/EditorBuffer.h
    src/Interface.cpp
    src/Interface.h)

target_link_libraries(textredigerare_cpp PRIVATE
        ftxui::component
        ftxui::dom
        ftxui::screen
)

if (NOT WIN32)
    target_compile_options(textredigerare_cpp PRIVATE -fsanitize=address -g)
    target_link_options(textredigerare_cpp PRIVATE -fsanitize=address)
endif ()