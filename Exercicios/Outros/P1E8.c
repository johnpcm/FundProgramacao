#include "main.h"

main(){

    int n, x, sm;


    for(n = 1; n <= 25; n++){

        x = n*(n-1)+1;

        sm = x;
        while(sm < pow(n,3)){
            printf("%4d +", x);
            x += 2;
            sm += x;
        }
        printf("%4d = %d^3 =%d \n", x, n, n*n*n);

    }

}


