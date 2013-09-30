

#include <stdio.h>
#include <math.h>

#define N 500

main(){

    //declaracao
    int v[N] = {0}, i=0, k=1, t=0, m[2]={0}, e=0;

    //input no vetor
    for(i=0, e=0; v[i-1] >= 0; i++, e++)
        scanf("%d", &v[i]);

    //demonstracao do vetor
    for(i=0; i < e-1; i++)
        printf("%d ", v[i]);
    printf("\n");


    //processamento do vetor
    for(i=1; i < e;){
           // printf("k %d, i %d, t %d",k,i,t);
        if(v[i] < v[i-1]){
            for(k=i+1, t=1; v[k] >= v[k-1] && k < e; k++, t++){}//printf("k %d, i %d, t %d",k,i,t);}
            i=k;
        }                  //
        else
            i++;
        if (t > m[0]){
            m[0] = t;
            m[1] = i-3;
        }

    }
    //saida
    for(i=0; i<=m[0]; i++)
        printf("%d ",v[m[1]+i-1]);
}


