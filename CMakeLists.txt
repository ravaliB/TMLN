cmake_minimum_required (VERSION 2.6)
project (Trie)
 
set (Trie_VERSION_MAJOR  1)
set (Trie_VERSION_MINOR 0)

configure_file(
"${PROJECT_SOURCE_DIR}/src/Trie.h.in"
"${PROJECT_SOURCE_DIR}/src/Trie.h"
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/src")
add_subdirectory(src)

#add_executable(Trie main.c)
