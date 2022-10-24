#ifndef MVECTOR_H
#define MVECTOR_H

#include <stdlib.h>

struct mpart
{
	void* data;
	struct mpart* next;
};

typedef struct mpart MPART;

struct mvector
{
	struct mpart* first;
	struct mpart* last;
	unsigned int size;
};

typedef struct mvector MVECTOR;

/* Initialize the vector. */
MVECTOR* mvector_init();

/* Add a data pointer in the specified vector. */
int mvector_add(MVECTOR* vect, void* data);

/* Get a data pointer of its vector at the specified index. */
void* mvector_get(MVECTOR* vect, unsigned int index);

/* Remove a part of its vector at the specified index. */
int mvector_remove(MVECTOR* vect, unsigned int index);

/* Free the specified vector and all parts associated to it if "free_data" is set to 1. */
void mvector_free(MVECTOR* vect, int free_data);

#endif