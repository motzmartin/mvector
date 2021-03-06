#include "mvector.h"

MVECTOR *mvector_init()
{
    MVECTOR *newvector = malloc(sizeof(MVECTOR));
    if (newvector == NULL)
    {
        return NULL;
    }
    newvector->first = NULL;
    newvector->last = NULL;
    newvector->size = 0;
    return newvector;
}

int mvector_push(MVECTOR *vect, void *data)
{
    MPART *newpart = malloc(sizeof(MPART));
    if (newpart == NULL)
    {
        return 1;
    }
    newpart->data = data;
    newpart->next = NULL;
    if (vect->first == NULL)
    {
        vect->first = newpart;
    }
    else
    {
        vect->last->next = newpart;
    }
    vect->last = newpart;
    vect->size++;
    return 0;
}

void *mvector_get(MVECTOR *vect, int index)
{
    int i = 0;
    MPART *p = vect->first;
    while (p != NULL)
    {
        if (i == index)
        {
            return p->data;
        }
        p = p->next;
        i++;
    }
    return NULL;
}

int mvector_remove(MVECTOR *vect, int index)
{
    MPART *temp;
    if (index == 0)
    {
        temp = vect->first;
        if (temp == NULL)
        {
            return 1;
        }
        vect->first = vect->first->next;
    }
    else
    {
        MPART *p = mvector_get(vect, index - 1);
        if (p == NULL)
        {
            return 1;
        }
        temp = p->next;
        p->next = p->next->next;
    }
    free(temp);
    vect->size--;
    return 0;
}

void mvector_free(MVECTOR *vect)
{
    MPART *p = vect->first;
    free(vect);
    while (p != NULL)
    {
        MPART *temp = p->next;
        free(p->data);
        free(p);
        p = temp;
    }
}