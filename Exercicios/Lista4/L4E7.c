#include <stdio.h>

main(){
    while(1){
    int in, hv = 0, mv = 0, hn = 10000, mn = 10000;

        printf("\ninsira a idade dos homens(# negativo para sair):\n");
    do{
        scanf("%d",&in);

        if (in > hv)
            hv = in;

        if (in < hn && in > 0)
            hn = in;

    }while (in >= 0);

    printf("\nagora insira a das mulheres:\n");
    do{
        scanf("%d",&in);

        if (in > mv)
            mv = in;

        if (in < mn && in > 0)
            mn = in;
    }while (in >= 0);

//    printf("hv %d, mv %d, hn %d, mn %d",hv,mv,hn,mn);

    printf("a soma das idades do homem mais velho com a mulher mais nova, %d e o produto das idades do homem mais novo com a mulher mais velha  %d. ", hv+mn, hn*mv);

    }
}
