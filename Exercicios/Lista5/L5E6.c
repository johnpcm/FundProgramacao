#include <stdio.h>

main(){
    while(1){

    int n=0, m=0, sm=0, i=0;

    printf("insira um numero");
    scanf("%d",&n);

        for( i = 0; i < n; i++){

            if(i % 2 != 0)
                sm += i;

            if(sm == n){
                printf("Ž um quadrado perfeito\n");
                break;
            }

        }
    }
}
