
#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 4


main(){

    srand(time(NULL));

    int v[N], menor = v[0], i, k, temp, pos;

    for(k=0; k < N; k++)
        v[k] = rand()%100;

    for(k=0; k < N; k++)
        printf("%d ", v[k]);
        printf("\n ");

    for(k=0; k < N; k++){
        menor = v[k];
        for(i=k; i < N; i++){
            if (v[i] <= menor){
                menor = v[i];
                pos = i;
            }
        }

        temp = v[k];
        v[k] = menor;
        v[pos] = temp;

    }

    for(k=0; k < N; k++)
        printf("%d ", v[k]);

}


