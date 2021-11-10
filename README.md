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
    //
    int *data1 = malloc(sizeof(int));
    *data1 = 17122607;
    mvector_push(vect, data1);
    //
    printf("%d\n", *((int*)mvector_get(vect, 0))); //-> 17122607
    //
    int *data2 = malloc(sizeof(int));
    *data2 = 42;
    mvector_push(vect, data2);
    //
    printf("%d\n", *((int*)mvector_get(vect, 1))); //-> 42
    //
    mvector_remove(vect, 0);
    //
    printf("%d\n", *((int*)mvector_get(vect, 0))); //-> 42
    //
    mvector_free(vect);
    return 0;
}
```
