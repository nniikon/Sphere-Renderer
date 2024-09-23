cmake_minimum_required(VERSION 3.10)

project(renderer VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(external/tgp)

add_executable(renderer
    source/main.cpp
    source/sphere_buttons.cpp
    source/sphere_renderer.cpp
    source/sphere_window.cpp
)

include_directories(include)

target_link_libraries(renderer PRIVATE tgp sfml-graphics sfml-window sfml-system)
