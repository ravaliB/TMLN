#include "dict.h"

trieNode_t *loadDict(char* path)
{
    char* word = malloc(MAX_WORD_SZ*sizeof(char));
    int freq;
    int count = 0;
    FILE* fd;

    trieNode_t* root;

    TrieCreate(&root);

    if ((fd = fopen(path, "r")) == NULL)
        perror("Can't open dictionnary");
            
    while (!feof(fd))
    {
        if (fscanf(fd, "%s%i", word, &freq))
        {
            //Add key with frequence as data
            TrieAdd(&root, word, freq);
            count++;
        }
    }

    free(word);

    if (fd != NULL)
        fclose(fd);

#ifdef DEBUG
    printf("%i words counted\n", count);
#endif

    return root;
}
