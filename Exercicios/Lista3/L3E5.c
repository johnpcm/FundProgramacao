#include <stdio.h>


main(){
    while(1){

        float x;

        printf("\ninsira um numero:");
        scanf("%f", &x);

        if (x > 80){
            printf("Maior que 80");
        }
        else if (x < 25){
            printf ("menor que 25");
        }
        else if (x == 40){
            printf ("Igual a 40");
        }
        else{
            printf ("nao Ž parte do programa");
        }

    }

}
