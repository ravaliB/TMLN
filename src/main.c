#include "Trie.h"
#ifdef WIN_32
#include "mman.h"
#endif
#include "tpl.h"


int main(int argc, char **argv)
{
    trieNode_t *root;
        TPL_API tpl_node *tn;
        int id;
        
        /*Create a trie*/
        TrieCreate(&root);
        
        TrieAdd(&root, "andrew", 1);
        TrieAdd(&root, "tina", 2);
        TrieAdd(&root, "argo", 3);
        TrieAdd(&root, "timor", 5);
        TrieRemove(&root, "tim");
        TrieAdd(&root, "tim", 6);
        TrieRemove(&root, "tim");
        TrieAdd(&root, "ti", 6);
        TrieAdd(&root, "amy", 7);
        TrieAdd(&root, "aramis", 8);
        
        tn = tpl_map("S(ci$$$$)", &root);
        
        for(id = 1; id < 9; id++) {
            tpl_pack(tn,1);
        }
    
        
        tpl_dump(tn, TPL_FILE, "dico.bin");
        tpl_free(tn);
        /*Destroy the trie*/
        TrieDestroy(root);
        return 1;
}
