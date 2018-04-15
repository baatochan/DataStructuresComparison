cmake_minimum_required(VERSION 3.5)
project(DataStructuresSDiZO)

set(CMAKE_CXX_STANDARD 11)

if (CMAKE_BUILD_TYPE MATCHES RELEASE)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
endif (CMAKE_BUILD_TYPE MATCHES RELEASE)

set(SOURCE_FILES main.cpp Program.cpp Program.h Structure.cpp Structure.h Array.cpp Array.h List.cpp List.h Counter.cpp Counter.h Heap.cpp Heap.h)
add_executable(DataStructuresSDiZO ${SOURCE_FILES})