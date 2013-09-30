#include <stdio.h>

main(){
    while(1){

        int A, B, C;


        printf("\ninsira o que cada jogador jogou(x,x,x)");
        scanf("%d,%d,%d", &A, &B, &C);


        if ((A+B+C)%3 == 0)
            printf ("Alice ganhou");
        else if ((A+B+C)%3 == 1)
            printf ("Bob ganhou");
        else if ((A+B+C)%3 == 2)
            printf ("Carol ganhou");
    }
}
