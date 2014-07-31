#ifndef LIST_H
#define LIST_H

typedef struct _list *list;

struct _list {
    unsigned char* key;
    int value;
    int distance;
    list next;
};

list listCreate();
list listAppend(list l, const unsigned char* key, int value, const int distance);
//list listSort(list l);
void listDel(list l);
void listShow(list l);

#endif 
