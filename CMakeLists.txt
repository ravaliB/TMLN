cmake_minimum_required (VERSION 2.6)
project (TLMN)

set(CMAKE_C_FLAGS "-Werror -Wall")
set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(PROJECT_SOURCE_DIR "src")

configure_file(
    "${PROJECT_SOURCE_DIR}/configure.h.in"
    "${PROJECT_SOURCE_DIR}/configure.h")

message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

IF (WIN32)
    set(tplSrc "src/win/*")
ENDIF (WIN32)

file( GLOB
    sourceFiles
    src/*
    ${tlpSrc})

add_executable( Trie
    ${sourceFiles})
