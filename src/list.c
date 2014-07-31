#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list listCreate()
{
    list newList = NULL;

    if (!(newList = malloc(sizeof(list))))
    {
        fprintf(stderr, "Cannot create newList");
    }
    else
    {
        newList->key = NULL;
        newList->value = -1;
        newList->distance = -1;
        newList->next = NULL;
    }

    return newList;
}

list listAppend(list l, const unsigned char* key, int value, const int distance)
{
    list curr = NULL;

    if (!l->key)
    {
        l->key = (unsigned char*) strdup(key);
        l->value = value;
        l->distance = distance;
    }
    else
    {
        curr = l;
        while (curr->next)
            curr = curr->next;

        list newList = listCreate(); 
        if (newList)
        {
            newList->key = (unsigned char*) strdup(key);
            newList->value = value;
            newList->distance = distance;

            curr->next = newList;
        }
    }

    return l;
}

void listDel(list l)
{
    while (l)
    {
        free(l->key);
        free(l);
        l = l->next;
    }

}

void listShow(list l)
{
    printf("[");

    while (l)
    {
        printf("{\"word\":\"%s\",\"freq\":\"%i\",\"distance\":\"%i\"}", l->key, l->value, l->distance);
        l = l->next;

        if (l)
            printf(",");
    }

    printf("]\n");
}
