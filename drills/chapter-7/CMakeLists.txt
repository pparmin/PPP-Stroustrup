cmake_minimum_required(VERSION 3.10)

# set the project name
project(chapter7_drill)

# set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# add the executable
add_executable(drill chapter7_drill.cpp)