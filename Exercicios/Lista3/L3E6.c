#include <stdio.h>


main(){
    while(1){

            float a, b, c;

        printf("\ninsira 3 numeros separados por ponto-e-virgula para formar um triangulo:");
        scanf("%f;%f;%f", &a, &b, &c);

        if ( a > 0 && b > 0 && c > 0){
            printf("eh um triangulo ");
            if ( a == b == c ){
                printf("equilatero");
            }
            else if (a != b && b != c && a != c){
                printf("escaleno");
            }
            else{
                printf("isoceles");
            }
        }
        else {
            printf("nao forma um triangulo");
        }
    }

}
