#include "main.h"

main(){
    while(1){
        int x,y;
        char op;

        printf("digte a opera��o");
        scanf("%d%c%d",&x,&op,&y);

        printf("o resultado �: %d\n",calc(x,op,y));

    }
}



