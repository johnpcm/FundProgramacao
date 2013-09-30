#include "main.h"


main(){
    while(1){
            int ano;

        printf("insira um ano:");
        scanf("%d", &ano);

        if (bi6 (ano) == 1)
            printf("Ž bissexto\n");
        else
            printf("nao Ž bissexto\n");

    }
}


