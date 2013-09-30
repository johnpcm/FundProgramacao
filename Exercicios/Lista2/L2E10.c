#include <stdio.h>




main(){

    int $, c;

    inicio:
    $ = c = 0;
    printf("\nInsira o valor a ser quebrado (R$x,xx)\nR$");
    scanf("%d,%d", &$, &c);

    if (c > 99){
        goto vinvalido;
    }


    printf("O valor deve ser quebrado em:\n");

    if (($ / 2) > 0){
        printf ("Notas:\n");
    }

    if (($ / 100) > 0){
        printf("%d de R$100,00\n", $/100);
    }
    if (($ % 100 / 50) > 0){
        printf("%d de R$50,00\n", $ % 100/50);
    }
    if (($ % 100 % 50 / 20) > 0){
        printf("%d de R$20,00\n",$ % 100%50/20);
    }
    if (($ % 100 % 50 % 20 / 10) > 0){
        printf("%d de R$10,00\n",$ % 100%50%20/10);
    }
    if (($ % 100 % 50 % 20 % 10 / 5) > 0){
        printf("%d de R$5,00\n",$ % 100%50%20%10/5);
    }
    if (($ % 100 % 50 % 20 % 10 % 5 / 2) > 0){
        printf("%d de R$2,00\n",$ % 100%50%20%10%5/2);
    }

    if ((c % 5 || c / 5 || $ % 100 % 50 % 20 % 10 % 5 % 2) > 0){
        printf ("Moedas:\n");
    }


    if (($ % 100 % 50 % 20 % 10 % 5 % 2) > 0){
        printf("%d de R$1,00\n",((((($ % 100)%50)%20)%10)%5)%2);
    }
    if ((c / 50) > 0){
        printf("%d de R$0,50\n",c / 50);
    }
    if ((c % 50 / 25) > 0){
        printf("%d de R$0,25\n",(c % 50)/25);
    }
    if ((c % 50 % 25 / 10) > 0){
        printf("%d de R$0,10\n", ((c % 50)%25)/10);
    }
    if ((c % 50 % 25 % 10 / 5) > 0){
        printf("%d de R$0,05\n", (((c % 50)%25)%10)/5);
    }
    if ((c % 50 % 25 % 10 % 5) > 0){
        printf("%d de R$0,01\n", (((c % 50)%25)%10)%5);
    }

    goto inicio;

    vinvalido:

        printf("Valor invalido, insira da maneira correta: R$x,xx");

    goto inicio;

}
