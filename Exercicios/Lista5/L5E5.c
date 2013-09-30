
#include <stdio.h>

main(){
    while(1){

        int n=0, ina=0, inb=0, p=1, c=0;

        printf("\ninsira o numero de itens:");
        scanf("%d",&n);

        printf("agora insira a sequencia:");
        scanf("%d",&ina);

        do{

            scanf("%d",&inb);

            if (inb != ina)
                p++;



            ina = inb;
            c++;

        }while (c < n-1);


        printf("foram inseridos %d segmentos",p);

    }
}


