# mvector
C/C++ library to work with vectors.

Code example:

```c
#include <stdio.h>
#include <stdlib.h>
#include <mvector.h>

int main(int argc, char *argv[])
{
    MVECTOR *vect = mvector_init();

    int *data1 = malloc(sizeof(int));
    *data1 = 19;
    mvector_push(vect, (void*)data1);

    int *data2 = malloc(sizeof(int));
    *data2 = 72;
    mvector_push(vect, (void*)data2);

    printf("%d\n", *((int*)mvector_get(vect, 0))); // > 19

    mvector_remove(vect, 0);

    printf("%d\n", *((int*)mvector_get(vect, 0))); // > 72

    mvector_free(vect);
    return 0;
}
```
