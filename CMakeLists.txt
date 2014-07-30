cmake_minimum_required (VERSION 2.6)
project (TLMN)

set(CMAKE_C_FLAGS "-Werror -Wall -Wno-pointer-sign")
set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(PROJECT_SOURCE_DIR "src")

message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

file( GLOB
    CompilSrcFiles
    src/*
    src/TextCompil/main.c)

add_executable( TextMiningCompiler
    ${CompilSrcFiles})
