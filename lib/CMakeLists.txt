cmake_minimum_required(VERSION 3.1...3.12 FATAL_ERROR)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}) # 设置动态库路径的变量
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}) # 设置静态库路径的变量
add_subdirectory(securec)