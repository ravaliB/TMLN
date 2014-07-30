#ifndef DICT_H
#define DICT_H

#include "trie.h"

#define MAX_WORD_SZ 180

Trie loadDict(char* path);
int dumpTrie(const void* towrite, const int length, void* data);
int dumpValue(const void* value, void* data); 
int readTrie(void* wasread, const int length, void* data);
void *readValue(void* data);

#endif
