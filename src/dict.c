#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dict.h"

Trie loadDict(char* path)
{
    char* word = malloc(MAX_WORD_SZ*sizeof(char));
    int* freq = NULL;
    FILE* fd;

    Trie root;

    if (!(root = Trie_new()))
        return NULL;

    if ((fd = fopen(path, "r")) == NULL)
        perror("Can't open dictionnary");

    while (!feof(fd))
    {
        freq = malloc(sizeof(int));

        if (fscanf(fd, "%s%i", word, freq))
        {
            //Add key with frequence as data
            Trie_set(root, word, freq);
        }
    }

    free(word);

    if (fd)
        fclose(fd);

    return root;
}

int dumpTrie(const void* towrite, const int length, void* data)
{
    FILE* fd = (FILE*) data;

    fwrite(towrite, 1, length, fd);

    return 1;
}

int dumpValue(const void* value, void* data)
{
    FILE* fd = (FILE*) fd;

    if (!fwrite(value, 1, sizeof(int), fd))
        printf("Cannot write value");

    return 1;
}

int readTrie(void* wasread, const int length, void* data)
{
    FILE* fd = (FILE*) data;

    fread(wasread, length, 1, fd);

    return 1;
}

void *readValue(void* data)
{
    FILE* fd = (FILE*) data;
    int* value = malloc(sizeof(int));

    fread(value, sizeof(int), 1, fd);

    return value;
}
