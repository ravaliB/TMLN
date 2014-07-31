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
  list l = (list) data;

  listAppend(l, key, *(int*)value, mismatches);
}

void test(char *file)
{
  FILE* data2 = fopen(file, "r");
  Trie trie2;
  char *word = malloc(sizeof (char));
  char approx[6];
  int  distance;

  if (data2)
    {
      trie2 = Trie_deserialize(&readTrie, &readValue, data2);
      fclose(data2);
    }

  printf("ok pour le data\n");
  scanf("%6s %d %s", approx, &distance, word);
  
  if (strcmp(approx, "Approx") == 0)
    { 
      list list = listCreate();

      Trie_get_approximate(trie2, word, distance, &testcall, list);
      list = listSort(list, &_compare);
      listShow(list);
      listDel(list);
    }
  else
    printf("commande introuvable \n");
  
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
