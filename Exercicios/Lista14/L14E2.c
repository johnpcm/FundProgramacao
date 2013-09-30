#include <joao.h>



main()
{

    int i, n, *v;

    scanf("%d", &n);

    v = allocVeti(n);

    inputVeti(v,n);

    printVeti(v,n);

    free(v);
}

