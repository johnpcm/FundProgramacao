#include <stdio.h>

main(){

    while(1){

        int h1, h2, m1, m2, hv, hn, mv, mn;

        printf("\ninsira a idade dos homens separadas por virgula:");
        scanf("%d,%d", &h1, &h2);
        printf("agora insira a das mulheres, tambem separadas por virgula:");
        scanf("%d,%d", &m1, &m2);



        if (h1 > h2){
            hv = h1;
            hn = h2;
        }
        else{
            hn = h1;
            hv = h2;
        }
        if (m1 > m2){
            mv = m1;
            mn = m2;
        }
        else{
            mn = m1;
            mv = m2;
        }


        printf("a soma Ž:%d o produto Ž:%d", hv+mn, hn*mv);
    }

}
