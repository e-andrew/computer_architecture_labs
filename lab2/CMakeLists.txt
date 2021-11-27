# cmake CMakeLists.txt -B "cmake_output"
# cmake -G "Ninja" CMakeLists.txt -B "ninja_output"

cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_COMPILER "/Users/EpicAndrew/gcc/bin/g++.exe")
project(AK_lab_2 LANGUAGES CXX)

set(SOURCE_DIR src)
set(INCLUDE_DIR include)
set(LIB_NAME libcalculator)
set(EXECUTABLE_NAME main)

include_directories(${INCLUDE_DIR})

add_library(${LIB_NAME} SHARED ${SOURCE_DIR}/calculator.cpp)
add_executable(${EXECUTABLE_NAME} ${SOURCE_DIR}/main.cpp)
target_link_libraries(${EXECUTABLE_NAME} ${LIB_NAME})