#include <stdio.h>

main(){
    while(1){

        int ano;

        printf("\ninsira um ano");
        scanf("%d", &ano);

        (ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))
         ?
        printf("O ano %d eh bissexto", ano)
         : (ano == 1) ?
        printf("� 1")
         :
        printf("O ano %d nao eh bissexto", ano);
    }

}
