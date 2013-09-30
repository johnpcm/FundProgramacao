#include <stdio.h>

main(){
    int velMax, velVei;
    printf("Insira a velocidade maxima da avenida:");
    scanf("%d", &velMax);
    printf("Agora, insira a velocidade que o carro estava:");
    scanf("%d", &velVei);
    if (velVei < velMax){
        printf("O condutor estava dentro do limite.\n");
    }
    else{
           printf("A multa para este condutor e de:R$ %6.2f\n", (velVei-velMax)*5.00 );


    }
}
