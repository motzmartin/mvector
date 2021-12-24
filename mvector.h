#ifndef MVECTOR_H
#define MVECTOR_H

#include <stdlib.h>

struct mpart
{
    void *data;
    struct mpart *next;
};

typedef struct mpart MPART;

struct mvector
{
    struct mpart *first;
    struct mpart *last;
    int size;
};

typedef struct mvector MVECTOR;

/**
 * initialize the vector
 *
 * \returns the created vector on success or NULL on failure
 */
MVECTOR *mvector_init();

/**
 * push a data pointer in the specified vector
 *
 * \returns 0 on success or 1 on failure
 */
int mvector_push(MVECTOR *vect, void *data);

/**
 * get a data pointer of its vector at the specified index
 *
 * \returns the data pointer on success or NULL on failure
 */
void *mvector_get(MVECTOR *vect, int index);

/**
 * remove a part of its vector at the specified index
 *
 * \returns 0 on success or 1 on failure
 */
int mvector_remove(MVECTOR *vect, int index);

/**
 * free the specified vector and all parts associated to it
 */
void mvector_free(MVECTOR *vect);

#endif