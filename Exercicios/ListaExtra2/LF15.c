#include <stdio.h>

main(){
    while(1){
        int in, sm = 0;

        do{
            printf("\ninsira um numero para somar (0 para resultado)");
            scanf("%d",&in);
            sm += in;
        }
        while( in!=0 );
        printf("\n\n\na soma Ž:%d\n\n",sm);
    }
}
