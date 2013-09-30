#include <stdio.h>
#include <math.h>
#define TAM 100

void crivo(int v[]);

main()
{
    int v[TAM], i;

    for(i = 2; i < TAM; i++)
        v[i] = i;
    crivo(v);
    printf("2");
    for(i = 0; i < TAM; i++)
        if (v[i] != -1)
            printf("%6d", v[i]);

}

void crivo(int v[])
{
    int i, k;



    for(i = 2; i < sqrt(TAM); i++)
    {
        if (v[i] != -1)
        {
            for(k = i; k < TAM; k++)
            {
                if (v[k] != i)
                    if(v[k]%i == 0)
                        v[k] = -1;
            }
        }
    }

    v[0] = v[1] = v[2] = -1;

}

