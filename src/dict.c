#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dict.h"

Trie loadDict(char* path)
{
    char* word = malloc(MAX_WORD_SZ*sizeof(char));
    int* freq = NULL;
    int count = 0;
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

            count++;
        }
    }

   free(word);

    if (fd != NULL)
        fclose(fd);

    printf("%i words counted\n", count);

    return root;
}
