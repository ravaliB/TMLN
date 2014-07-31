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

void testcall(const unsigned char *key, 
				      const void *value,
				      const int mismatches,
				      void *data)
{
    //printf("key %s value %i mismatches %i\n", key, *(int*)value, mismatches);

    list l = (list) data;

    listAppend(l, key, *(int*)value, mismatches);

}

void test2()
{
    int* freq = malloc(sizeof(int));
    int* freq2 = malloc(sizeof(int));
    int* freq3 = malloc(sizeof(int));
    Trie trie = Trie_new();

    *freq = 666;
    *freq2 = 777;
    *freq3 = 888;
    
    Trie_set(trie, "testi", freq2);
    Trie_set(trie, "tqestq", freq3);
    Trie_set(trie, "test", freq);


    list data = listCreate();
    Trie_get_approximate(trie, "test", 2, &testcall, data);
    listShow(data);
    listDel(data);
    
    Trie_del(trie);
}

/**Test serialisation et deserialisation**/
void test(char* Path) 
{
    Trie trie;
    Trie trie2;

    trie = loadDict(Path);

    int* freq = NULL;
    /*void* data = NULL;
    Trie_get_approximate(trie, "test", 1, &testcall, data);*/
    /*int* freq = Trie_get(trie, "unsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettresunsupermotetextremementlongavectropdelettres");
    printf("%p %i\n", freq, *freq);

    freq = Trie_get(trie, "petitecoquinette");
    printf("%p %i\n", freq, *freq);*/

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

    list list = listCreate();
    Trie_get_approximate(trie, "test", 1, &testcall, list);
    list = listSort(list, &_compare);
    listShow(list);
    listDel(list);
    
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
    /*else if (argc == 2)
    {
        test(argv[1]);
        test2();
    }*/
    else
        printf("%s /path/to/word/freq.txt /path/to/output/dict.bin\n", argv[0]);

    return 1;
}
