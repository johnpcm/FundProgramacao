
#include "joao.h"

#define L 15

main(){

    int i, j, m[L][L] = {{0}};
    m[0][0] = 1;


    for(i = 1; i < L; i++){
        m[i][0] = 1;
        for(j = 1; j < L; j++)
            m[i][j] = m[i-1][j] + m[i-1][j-1];
    }

    for(i = 0; i < L; i++){
        for(j = 0; j <= i; j++)
            printf("%7d ", m[i][j]);
        printf("\n");
    }


}

