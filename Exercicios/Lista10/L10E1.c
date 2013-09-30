//1. (*/2) Implemente um programa que preencha uma matriz de 6 linhas e 5 colunas de nu ́meros inteiros
//e adicione um valor num (lido do teclado) a todos os valores divis ́ıveis por 3.

#include "main.h"
#define L 50
#define C 23

main(){

    srand(time(NULL));

    int i, j, m[L][C], boo;

    scanf("%d", &boo);

    for(i = 0; i < L; i++)
        for(j = 0; j < C; j++){
            m[i][j] = rand()%10;
            if (m[i][j] % 3 == 0)
                m[i][j] += boo;
        }

    printmi(m,L,C);



}



