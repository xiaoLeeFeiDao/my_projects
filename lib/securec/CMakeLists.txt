
project(securec)
cmake_minimum_required(VERSION 3.1...3.12 FATAL_ERROR)
include_directories(./include)
aux_source_directory(./src CURRENT_SRC_LIST)
add_library(${PROJECT_NAME} SHARED ${CURRENT_SRC_LIST})
add_library("static_${PROJECT_NAME}" STATIC ${CURRENT_SRC_LIST})
# execute_process(COMMAND sh increment_version.sh WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} OUTPUT_VARIABLE VERSION_INFO)
# message(STATUS "${VERSION_INFO}")
# set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${VERSION_INFO} SOVERSION 1)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION 1.2 SOVERSION 1)
set_target_properties("static_${PROJECT_NAME}" PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
CatCommonUsedVariableValue()

install(
    TARGETS securec static_securec 
    # RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    ARCHIVE DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
)