#include "mvector.h"

MVECTOR* mvector_init()
{
	MVECTOR* newvector = calloc(1, sizeof(MVECTOR));
	if (newvector == NULL)
	{
		return NULL;
	}
	return newvector;
}

int mvector_add(MVECTOR* vect, void* data)
{
	MPART* newpart = calloc(1, sizeof(MPART));
	if (newpart == NULL)
	{
		return 1;
	}
	newpart->data = data;
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

void* mvector_get(MVECTOR* vect, unsigned int index)
{
	if (index > vect->size - 1)
	{
		return NULL;
	}
	MPART* p = vect->first;
	while (index > 0)
	{
		p = p->next;
		index--;
	}
	return p->data;
}

int mvector_remove(MVECTOR* vect, unsigned int index)
{
	MPART* temp;
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
		MPART* p = mvector_get(vect, index - 1);
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

void mvector_free(MVECTOR* vect, char free_data)
{
	MPART* p = vect->first;
	free(vect);
	while (p != NULL)
	{
		MPART* temp = p->next;
		if (free_data)
		{
			free(p->data);
		}
		free(p);
		p = temp;
	}
}
