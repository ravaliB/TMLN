# first we add the executable that generates the table
add_executable(MakeTable main.c)
# add the command to generate the source code

# add the binary tree directory to the search path 
# for include files
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )
 
# add the main library
#add_library(MathFunctions mysqrt.c ${CMAKE_CURRENT_BINARY_DIR}/Table.h)
 
#install (TARGETS src DESTINATION bin)
install (FILES Trie.h DESTINATION include)