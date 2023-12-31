#-----------------------------new config--------------------------------------
cmake_minimum_required(VERSION 3.5)
set(OBJECT_NAME "my_project" CACHE INTERNAL "default project name include all modules")
project(${OBJECT_NAME})
include(select_platform_property.cmake)
SelectPlatform("Debug")
add_subdirectory(src)
add_subdirectory(lib)














































































































#-----------------------------------------------------------------old config-----------
#cmake_minimum_required(VERSION 3.5)
#
#set(PROJECT_NAME my_projects)
#project(${PROJECT_NAME})
#
#set(CMAKE_BUILD_TYPE "Debug")
#message(STATUS "operation system is ${CMAKE_SYSTEM}")
#if(WIN32)
#    message(STATUS "platform is ${CMAKE_SYSTEM_NAME}")
#elseif(APPLE)
#    message(STATUS "platform is ${CMAKE_SYSTEM_NAME}")
#elseif(UNIX)
#    message(STATUS "platform is ${CMAKE_SYSTEM_NAME}")
#    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 -O2 -ggdb -Wall -Wunused-function -pthread")
#        set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -std=c99 -O2 -ggdb -Wall -pthread")
#        set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#        set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#        message(STATUS ${CXXFLAGS})
#        message("UNIX - Debug mode")
#    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
#        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -O2 -Wunused-function -pthread")
#        set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=c99 -O2 -pthread")
#        message("UNIX - Release mode")
#    endif()
#elseif(MINGW)
#    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 -g -Wall -Wunused-function -pthread")
#        set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -std=c99 -g -Wall -pthread")
#        message("MINGW - Debug mode")
#    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
#        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -O2 -Wunused-function -pthread")
#        set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=c99 -O2 -pthread")
#        message("MINGW - Release mode")
#    endif()
#    if(PROJECT_ARCHITECTURE STREQUAL "x64")
#        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -m64")
#        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -m64")
#    elseif(PROJECT_ARCHITECTURE STREQUAL "x86")
#        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -m32")
#        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -m32")
#    endif()
#    #set(CMKAE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
#elseif(MSVC)
#    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ")
#    elseif(CMKAE_BUILD_TYPE STREQUAL "Release")
#        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ")
#    endif()
#    if(CMAKE_CL_64)
#        set(PROJECT_ARCHITECTURE "x64")
#    else(CMAKE_CL_64)
#        set(PROJECT_ARCHITECTURE "x86")
#    endif(CMAKE_CL_64)
#endif()
## ------------cancel -Wmissing-declarations ---------
#add_definitions(-fstack-protector-all -fPIC -D_FORTIFY_SOURCE=2 -O2 -Wunused-variable -D_GNU_SOURCE -D__USE_XOPEN)
#add_subdirectory(src)
## option(MYLIB "cpp examples" OFF)
## option(STONE_SOCK "cpp examples" OFF)
##option(STRING_PROCESS_CENTER_DEF "strings examples" OFF)
##option(TEST_DEF "cpp examples" ON)
##
##set(SRC_DIR ${HOME_NAME}/src)
##set(TEST_DIR ${SRC_DIR}/test)
##set(STRING_PROCESS_CENTER_DIR ${SRC_DIR}/string_process_center)
##
##include_directories(
##    ${TEST_DIR}
##    ${STRING_PROCESS_CENTER_DIR}
##)
##
##aux_source_directory(${SRC_DIR} SRC)
##if(TEST_DEF)
##    message("hello test")
##    add_definitions(-DCPP_LEARN)
##    aux_source_directory(${TEST_DIR} TEST)
##endif()
##if(STRING_PROCESS_CENTER_DEF)
##    message("hello stone")
##    add_definitions(-DSTR_PROCESS)
##    aux_source_directory(${STRING_PROCESS_CENTER_DIR} STRING_PROCESS_CENTER)
##endif()
##set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
##
##list(
##    APPEND ALL_CODE_LIST
##    ${SRC}
##    ${TEST}
##    ${STRING_PROCESS_CENTER}
##)
##add_executable(${PROJECT_NAME} ${ALL_CODE_LIST})
##set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
