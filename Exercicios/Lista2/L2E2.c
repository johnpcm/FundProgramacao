#include <stdio.h>

main(){

    float cdf;

    printf("Insira o custo de fábrica do carro:");
    scanf ("%f", &cdf);

    printf("O preço para o consumidor final será de: R$ %6.2f sendo R$ %6.2f de impostos e R$ %6.2f de lucro da distribuidora. ", cdf*1.57, cdf*0.45, cdf*0.12);
}
