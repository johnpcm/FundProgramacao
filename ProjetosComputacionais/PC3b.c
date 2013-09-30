#include <stdio.h>


void digitoCPF(int v[]);

main()
{

    int vec[11]= {2,2,2,3,3,3,6,6,6}, i;

    digitoCPF(vec);

    for(i=0; i<11; i++)
    {
        printf("%d ", vec[i]);
    }

}

void digitoCPF(int v[])
{

    int i, k;

    v[9] = v[10] = 0;

    for (i = 0, k = 10; i < 9; i++, k--)
    {
        v[9] += v[i] * k;
    }

    v[9] %= 11;

    if (v[9] < 2)
        v[9] = 0;

    else
        v[9] = 11 - v[9];

    for (i = 0, k = 11; i < 10; i++, k--)
    {
        v[10] += v[i] * k;
    }

    v[10] %= 11;

    if (v[10] < 2)
        v[10] = 0;

    else
        v[10] = 11 - v[9];

}
