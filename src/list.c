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
        if (l->key)
            printf("{\"word\":\"%s\",\"freq\":\"%i\",\"distance\":\"%i\"}", l->key, l->value, l->distance);
        l = l->next;

        if (l)
            printf(",");
    }

    printf("]\n");
}

list listSort(list l, int (*compare)(list a, list b))
{
    if (!l || !l->next)
        return l;

    list right = l;
    list tmp = l;
    list last = l;
    list result = NULL;
    list next = NULL;
    list tail = NULL;

    //Search for pivot
    while (tmp && tmp->next)
    {
        last = right;
        right = right->next;
        tmp = tmp->next->next;
    }
    
    //Cut from pivot
    last->next = 0;

    l = listSort(l, compare);
    right = listSort(right, compare);

    while (l || right)
    {
        if (!right) 
        {
            next = l;
            l = l->next;
        } 
        else if (!l) 
        {
            next = right;
            right = right->next;
        }
        else if (compare(l, right) < 0)
        {
            next = l;
            l = l->next;
        }
        else
        {
            next = right;
            right = right->next;
        }

        if (!result)
        {
            result = next;
        }
        else
        {
            tail->next = next;
        }

        tail = next;
    }

    return result;

}
