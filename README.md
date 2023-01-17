# mvector

C/C++ library to work with vectors.

## Code example:

```c
#include <stdio.h>
#include <stdlib.h>
#include "mvector.h"

int main(int argc, char* argv[])
{
	MVECTOR* vect = mvector_init();

	int* number1 = malloc(sizeof(int));
	*number1 = 26;
	mvector_add(vect, (void*)number1);

	int* number2 = malloc(sizeof(int));
	*number2 = 17;
	mvector_add(vect, (void*)number2);

	printf("%d\n", *((int*)mvector_get(vect, 0))); // > 26
	printf("%d\n", *((int*)mvector_get(vect, 1))); // > 17

	mvector_remove(vect, 0);

	printf("%d\n", *((int*)mvector_get(vect, 0))); // > 17

	mvector_free(vect, 1);

	return 0;
}
```
