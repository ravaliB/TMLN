#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../trie.h"
#include "../dict.h"
#include "../list.h"


int _compare(list l1, list l2)
{
    if (l1->distance > l2->distance) //Crescent
        return 1;
    else if (l1->value < l2->value) //Decrescent
        return 1;
    else if (strcmp(l1->key, l2->key) > 0) //Crescent
        return 1;

    return -1;
}

void makeList(const unsigned char *key, 
        const void *value,
        const int mismatches,
        void *data)
{
    list l = (list) data;

    listAppend(l, key, *(int*)value, mismatches);
}

void test(char *file)
{
    FILE* data2 = fopen(file, "r");
    Trie trie2;
    char *line = NULL;
    char *word = malloc(sizeof (char)*MAX_WORD_SZ);
    int  distance;

    if (data2)
    {
        trie2 = Trie_deserialize(&readTrie, &readValue, data2);
        fclose(data2);
    }

    printf("ok pour le data\n");

    if (!(line = malloc(sizeof(char)*(MAX_WORD_SZ+30))))
        goto mem_error; 

    while (fgets(line, MAX_WORD_SZ+30, stdin))
    {
        if (sscanf(line, "approx %d %s", &distance, word) == 2)
        {
            list list = listCreate();

            Trie_get_approximate(trie2, word, distance, &makeList, list);
            list = listSort(list, &_compare);
            listShow(list);
            listDel(list);
        }
    }
    
    if (line)
        free(line);
mem_error:    
    if (word)
        free(word);

    if(trie2)
        Trie_del(trie2);
}

int main(int argc, char **argv)
{
    if (argc > 1)
        test(argv[1]);

    return 0;
}
