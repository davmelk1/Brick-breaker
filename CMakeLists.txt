cmake_minimum_required(VERSION 3.16)
project(Learn-Modern-Advanced-Cpp)

set(CMAKE_CXX_STANDARD 17)

# Add the path to SFMLConfig.cmake to CMake's module path
set(SFML_DIR "/usr/share/SFML/cmake/Modules/")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Find the SFML components you want to use
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE src "src/*")

# Add the subdirectories containing the header files
include_directories(include)

# Add the source files to a library target
add_library(myLibrary ${src})

add_executable(main main.cpp)
add_executable(random_walker_graphics random_walker_graphics.cpp)

target_link_libraries(main myLibrary sfml-graphics sfml-window sfml-system)
target_link_libraries(random_walker_graphics myLibrary sfml-graphics sfml-window sfml-system)
