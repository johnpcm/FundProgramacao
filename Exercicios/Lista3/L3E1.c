#include <stdio.h>

main(){

    float c,f;

    printf("insira uma temperatura em celsius:");
    scanf("%f",&c);

    f = (9 * c + 160)/5;

    printf("a temp em farenheit Ž:%6.2f", f);

}
