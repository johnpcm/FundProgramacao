
#include <stdio.h>
#include <math.h>

#define N 500

main(){

    //declaracao
    int v[N] = {0}, i = 0/*posiao no vetor*/, t = 1/*tamanho temporario*/, ta = 0/*tam armaz*/, in = 0/*ponto inicial temporario*/, ia = 0/*p. ini. armaz.*/;

    //input no vetor
    for(i=0; v[i-1] >= 0; i++)
        scanf("%d", &v[i]);

    //demonstracao do vetor
    for(i=0; v[i] >= 0; i++)
        printf("%d ", v[i]);
    printf("\n");

    //processamento do vetor
    for (i=1; v[i] >= 0; i++){

        if (v[i] < v[i-1]){

            if(t > ta){
                ta = t;
                ia = in;
            }
            t = 1;
            in = i;

        }
        else{

            t++;

        }
    }


    //saida

    for(i = ia; i < ia+ta ; i++)
        printf("%d ", v[i]);
}


