
#include <stdio.h>

main(){
    while(1){

        int n, i, p = 3;

        printf("insira um numero:");
        scanf("%d",&n);

        for(i = 2; i < n; i++)
            if (n % i == 0){
                p = 1;
                printf("n‹o Ž primo\n");
                break;
            }

        if (p != 1)
            printf("Ž primo\n");
    }

}


