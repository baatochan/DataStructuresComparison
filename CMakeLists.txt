cmake_minimum_required(VERSION 3.6)
project(DataStructuresSDiZO)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(SOURCE_FILES main.cpp Program.cpp Program.h Structure.cpp Structure.h Array.cpp Array.h List.cpp List.h Counter.cpp Counter.h Heap.cpp Heap.h)
add_executable(DataStructuresSDiZO ${SOURCE_FILES})