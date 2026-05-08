cmake_minimum_required(VERSION 3.10)
project(robustal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Para que clangd pueda leer el compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(robustal ${SOURCES})