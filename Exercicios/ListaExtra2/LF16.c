#include <stdio.h>

main(){
    while(1){

        int in, i=0;

        do{
            printf("\ninsira um numero (-1 para resultado)");
            scanf("%d",&in);

            if (in % 2 == 0 && in >= 0)
                i++;
        }
        while (in!=-1);
        printf("voce inseriu %d numeros pares",i);
    }

}
