#define TRIE_VERSION_MAJEUR 
#define TRIE_VERSION_MINEUR 0

#include <stdio.h>
#include <stdlib.h>

typedef struct trieNode trieNode_t;

struct trieNode {
    char key;
    int value;
    trieNode_t* next;
    trieNode_t* prev;
    trieNode_t* children;
    trieNode_t* parent;
};

void TrieCreate(trieNode_t **root);
static trieNode_t* TrieCreateNode(char key, int data);
void TrieAdd(trieNode_t **root, char *key, int data);
trieNode_t* TrieSearch(trieNode_t* root, const char *key);
void TrieRemove(trieNode_t **root, char* key);
void TrieDestroy(trieNode_t* root);
