project(main.out)
cmake_minimum_required(VERSION 3.5)
aux_source_directory(. CURRENT_SRC_LIST)
include(get_module_info.cmake)
GetModules()
add_executable(${PROJECT_NAME} ${CURRENT_SRC_LIST})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
target_link_libraries(${PROJECT_NAME} cpp_case securec)















# message(STATUS ${OBJ_SRC_LIST})
# set(OBJ_BASE_PATH "${CMAKE_SOURCE_DIR}/src")
# set(OBJ_DIR_CPP_CASE "cpp_case")
# include_directories(${OBJ_BASE_PATH}/${OBJ_DIR_CPP_CASE})
# add_definitions(-D CPP_LEARN)
# aux_source_directory(${OBJ_BASE_PATH}/${OBJ_DIR_CPP_CASE} ALL_SRC_LIST)
# set(CURRENT_SRC_LIST "" CACHE INTERNAL "get all src files")
