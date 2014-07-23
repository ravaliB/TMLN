cmake_minimum_required (VERSION 2.6)
project (TLMN)

set(CMAKE_C_FLAGS "-Werror -Wall")
set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")

message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

file( GLOB_RECURSE
    sourceFiles
    src/*)

add_executable( Trie
    ${sourceFiles})
