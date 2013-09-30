#include <stdio.h>

main(){
    while(1){

        int n = 0, sm = 0;

        while(n != -1){
        printf("insira um numero para somar");
        scanf("%d",&n);

        if(n>0)
        sm += n;
        }

        printf("a soma Ž %d", sm);
    }
}
