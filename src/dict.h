#ifndef DICT_H
#define DICT_H

#include <string.h>
#include <stdio.h>
#include "Trie.h"

#define MAX_WORD_SZ 180

trieNode_t *loadDict(char* path);

#endif
