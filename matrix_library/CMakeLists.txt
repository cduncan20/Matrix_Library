cmake_minimum_required(VERSION 3.14)
project(matrix_library VERSION 1.0)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
add_subdirectory(test)