cmake_minimum_required(VERSION 3.10)

project(MyProject)
set(EXECUTABLE_NAME nesda)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(${EXECUTABLE_NAME} PRIVATE src/include/)

add_executable(${EXECUTABLE_NAME}
                src/main.cpp
                src/load_rom.cpp
                src/instruction_disassemble.cpp
                src/disassemble_init.cpp
                src/util.cpp
                src/instruction_map.cpp
                src/instruction_bus.cpp
                src/instructions.cpp
                src/cli.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/..)
