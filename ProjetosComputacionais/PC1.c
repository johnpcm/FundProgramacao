#include <stdio.h>

main(){
    while(1){

        //declaração
        int n=0, in=0;


        //entrada
        printf("\ninsira o número de partida: ");
        scanf("%d",&in);

        //processamento da sequencia
        while (in != 1){

            printf("%5d",in); //saida parcial

            if (in % 2 == 0) //se for par
                in /= 2;

            else    //se for impar
                in = 3 * in + 1;

            n++;

            if(n % 5 == 0)
                printf("\n"); //pular linha a cada 5

        }

        //saida final
        printf("%5d",in);
        printf("\nforam %d numeros", n+1 );
    }
}

