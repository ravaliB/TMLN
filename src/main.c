#include <stdio.h>

#include "trie.h"
#include "dict.h"

void test(char* Path) 
{
    Trie trie;

    trie = loadDict(Path);

    int* freq = Trie_get(trie, "unsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettres");
    printf("%p %i\n", freq, *freq);

    if (!trie)
        Trie_del(trie);
}


int main(int argc, char* argv[]) 
{
    if (argc == 2)
    {
        if (argv[1] != NULL)
        {
            test(argv[1]);
        }
    }
    else
        printf("Please mention dictionnary\n");

    return 1;
}
