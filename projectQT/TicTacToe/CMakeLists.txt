cmake_minimum_required(VERSION 3.5)

project(TTT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Anadido para que encuentre todos los archivos solo
file(GLOB_RECURSE
    FOUND_FILES
    LIST_DIRECTORIES true
    ./*.*)

message(STATUS ${FOUND_FILES})

add_executable(TresEnRaya main.cpp ${FOUND_FILES})
