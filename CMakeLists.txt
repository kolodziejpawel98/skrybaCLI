# CMakeLists.txt

# Wymagana wersja CMake
cmake_minimum_required(VERSION 3.10)

# Ustawienie nazwy projektu
project(skrybaCLI)

# Wymagamy C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodanie katalogu z plikami źródłowymi
add_executable(skrybaCLI src/main.cpp)

# Wyszukiwanie pakietu ncurses
find_package(Curses REQUIRED)

# Dodanie flagi do linkowania z biblioteką ncurses
target_link_libraries(skrybaCLI PRIVATE ${CURSES_LIBRARIES})
include_directories(${CURSES_INCLUDE_DIRS})

