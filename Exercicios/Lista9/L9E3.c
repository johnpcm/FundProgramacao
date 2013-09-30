#include <stdio.h>
#include <math.h>
#include <time.h>

#define DIM 100

main(){
    while(1){
        srand(time(NULL));

        //pré declaracao
        int n;
        scanf("%d",&n);
        printf("\n\n");

        //declaracao
        int v[n], i=0, sma=0, sm=0, ia=0, ta=0, t=1, k=0;

        //input no vetor
        for(i = 0; i < n; i++)
            v[i] = (DIM-rand()%((2*DIM)+1));

        //demonstracao do vetor

        for(i=0; i < n; i++)
            printf("%d ", v[i]);
        printf("\n\nsub sequencia:\n");


        //processamento do vetor

        for(i = 0; i < n; i++){
            sm = v[i];
            t=1;
            for(k = i+1; k < n; k++){

                sm += v[k];
                t++;

                if(sm > sma){

                    sma = sm;
                    ia = i;
                    ta = t;

                }
            }
        }


        //saida

        for(i = ia; i < ia+ta ; i++)
            printf("%d ", v[i]);
            printf("\na soma dos itens acima é: %d, portanto, a maior soma sequencial com %d itens\n", sma, ta);
    }
}

