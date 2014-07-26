#include "Trie.h"
#include "dict.h"
#ifdef WIN_32
#include "mman.h"
#endif
#include "tpl.h"
#include <stdio.h>


int main(int argc, char **argv)
{
    trieNode_t* root;

    if (argc == 2)
    {
        if (argv[1] != NULL)
        {
            root = loadDict(argv[1]);
        }
    }
    else
        printf("Please mention dictionnary\n");

    TrieSearch(root, "taxi");

    TrieDestroy(root);
    
    return 1;
}
