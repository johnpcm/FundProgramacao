#include <stdio.h>

int calc(int x, char op, int y);

main(){
    while(1){
        int x,y;
        char op;

        printf("digte a opera��o");
        scanf("%d%c%d",&x,&op,&y);

        printf("o resultado �: %d\n",calc(x,op,y));

    }
}

int calc(int x, char op, int y){
        switch (op){
            case '+':
                return (x+y);

            case '-':
                return (x-y);

            case '*':
                return (x*y);

            case '/':
                return (x/y);

            default:
                printf("erro\n");
                exit(1);
                }

}


