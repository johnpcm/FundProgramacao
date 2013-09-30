#include "joao.h"

#define L 10
#define C 6


main(){

    int i, j, m[L][C];

    for(j = 0; j < C; j++)
        scanf("%d", &m[0][j]);

    for(i = 1; i < L; i++)
        for(j = 0; j < C; j++)
            m[i][j] = m[i-1][j]*2;

    printmi(m, L, C);




}

