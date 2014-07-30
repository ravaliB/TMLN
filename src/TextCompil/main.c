#include <stdio.h>
#include <stdlib.h>

#include "../trie.h"
#include "../dict.h"

/**Test serialisation et deserialisation**/
void test(char* Path) 
{
    Trie trie;
    Trie trie2;

    trie = loadDict(Path);
   
    int* freq = Trie_get(trie, "unsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettres");
    printf("%p %i\n", freq, *freq);

    freq = Trie_get(trie, "petitecoquinette");
    printf("%p %i\n", freq, *freq);

    FILE* data = fopen("./dict.bin", "w"); 

    if (data)
    {
        Trie_serialize(trie, &dumpTrie, &dumpValue, data);
        fclose(data);
    }
    
    if (trie)
        Trie_del(trie);

    FILE* data2 = fopen("./dict.bin", "r");

    if (data2)
    {
        trie2 = Trie_deserialize(&readTrie, &readValue, data2);
        fclose(data2);
    }

    freq = Trie_get(trie2, "unsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettres");
    printf("%p %i\n", freq, *freq);
    
    freq = Trie_get(trie, "petitecoquinette");
    printf("%p %i\n", freq, *freq);

    if(trie2)
        Trie_del(trie2);
}

int storeWord(char* inPath, char* outPath)
{
    FILE* data = NULL;
    Trie trie;

    trie = loadDict(inPath);

    data = fopen(outPath, "w");

    if (data)
    {
        Trie_serialize(trie, &dumpTrie, &dumpValue, data);
        fclose(data);
    }
    else
        return 1;

    if (trie)
        Trie_del(trie);

    return 0;
}

int main(int argc, char* argv[]) 
{
    if (argc == 3)
    {
        if (argv[1] && argv[2])
        {
            return storeWord(argv[1], argv[2]);
        }
    }
    else if (argc == 2)
    {
        test(argv[1]);
    }
    else
        printf("%s /path/to/word/freq.txt /path/to/output/dict.bin\n", argv[0]);

    return 1;
}
