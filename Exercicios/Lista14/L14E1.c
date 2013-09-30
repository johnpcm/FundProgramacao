#include <joao.h>



main()
{

    int i, n, *v;

    scanf("%d", &n);

    v = (int *) malloc(n*sizeof(int));


    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for(i = 0; i < n; i++)
        printf("%-5d", v[i]);

    free(v);
}

