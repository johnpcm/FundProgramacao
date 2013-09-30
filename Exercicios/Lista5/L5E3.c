
#include <stdio.h>

main(){
    while(1){

        int n=0, ina=0, inb=0, s=3, c=0;

        printf("\ninsira o numero de itens:");
        scanf("%d",&n);

        printf("agora insira a sequencia:");
        scanf("%d",&ina);

        do{

            scanf("%d",&inb);

            c++;

            if (s == 3){//padrao
                if (inb <= ina)
                    s = 1;
                else
                    s = 0;
            }


            else if (s == 0)//crescente
                if (inb <= ina)
                    s = 2;
            else if (s == 1)//decrescente
                if (inb >= ina)
                    s = 2;
            else if (s == 2)//desordenada
                    break;


            ina = inb;

        }while (c < n-1);
        if (s == 0)
            printf ("\ncrescente");
        if (s == 1)
            printf ("\ndecrescente");
        if (s == 2)
            printf ("\ndesordenado");
    }
}


