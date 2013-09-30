#include <stdio.h>

main(){

    int a,b,c;

    while(1) {

        printf("\nescreva tres numeros inteiros distintos separados por virgula:");
        scanf("%d,%d,%d",&a,&b,&c);

        if ( a > b && a > c){ // a>
            if (b > c){
                printf("em ordem: %d %d %d", c, b, a);
            }
            else{
                printf("em ordem: %d %d %d", b, c, a);
            }
        }
        else if (b > c){ // b>
            if (c > a){
                printf("em ordem: %d %d %d", a, c, b);
            }
            else{
                printf("em ordem: %d %d %d", c, a, b);
            }
        }
        else{ // c>
            if (b > a){
                printf("em ordem: %d %d %d", a, b, c);
            }
            else{
                printf("em ordem: %d %d %d", b, a, c);
            }
        }




    }

}
