#include <stdio.h>

main(){
    while(1){

        int in, a, e=0;

        printf("\n\ninsira um numero:");
        scanf("%d", &in);

        for (a=0; a*(a+1)*(a+2) <= in; a++)
            if (a*(a+1)*(a+2) == in){
                printf("\neh triangular");
                e = 1;
            }

        if (e==0)
            printf("\nnao eh triangular");

    }
}


