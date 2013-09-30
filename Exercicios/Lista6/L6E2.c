#include "main.h"

main(){
    while(1){
        int x,y;
        char op;

        printf("digte a operação");
        scanf("%d%c%d",&x,&op,&y);

        printf("o resultado é: %d\n",calc(x,op,y));

    }
}



