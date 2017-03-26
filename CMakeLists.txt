cmake_minimum_required(VERSION 3.6)
project(DataStructuresSDiZO)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Program.cpp Program.h List.cpp List.h ListElement.cpp ListElement.h)
add_executable(DataStructuresSDiZO ${SOURCE_FILES})