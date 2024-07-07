cmake_minimum_required(VERSION 3.10)

project(skrybaCLI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(skrybaCLI src/main.cpp src/button.cpp src/definitions.cpp src/decorations.cpp)

find_package(Curses REQUIRED)

target_link_libraries(skrybaCLI PRIVATE ${CURSES_LIBRARIES})
include_directories(${CURSES_INCLUDE_DIRS})
include_directories(src)
