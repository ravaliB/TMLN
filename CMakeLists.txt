cmake_minimum_required (VERSION 2.6)
project (TLMN)

if(CMAKE_COMPILER_IS_GNUCC)
set(CMAKE_C_FLAGS "-Werror -Wall -Wno-pointer-sign")
set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
endif(CMAKE_COMPILER_IS_GNUCC)
set(PROJECT_SOURCE_DIR "src")
set(CMAKE_CURRENT_BINARY_DIR CMAKE_CURRENT_SOURCE_DIR)

message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

file( GLOB
    CompilSrcFiles
    src/*
    src/TextCompil/main.c)

file( GLOB
    AppSrcFiles
    src/*
    src/TextApp/main.c)

add_executable( TextMiningCompiler
    ${CompilSrcFiles})

add_executable( TextMiningApp
    ${AppSrcFiles})
