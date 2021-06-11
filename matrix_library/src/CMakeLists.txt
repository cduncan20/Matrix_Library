add_executable(
    matrix_library_demo
    demo.cpp
)

target_link_libraries(matrix_library_demo)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
