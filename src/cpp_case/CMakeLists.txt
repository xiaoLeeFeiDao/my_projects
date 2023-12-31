project(cpp_case)
cmake_minimum_required(VERSION 3.5)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

include_directories(src)
include_directories(include)
aux_source_directory(src OBJ_SRC_LIST)
add_library(${PROJECT_NAME} ${OBJ_SRC_LIST})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
