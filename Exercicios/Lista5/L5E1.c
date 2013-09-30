#include <stdio.h>

main(){

    int h;
    float Custo;

    while(h >= 0){
            Custo = 0;

            printf("\ninsira o numero de porquinhos: ");
            scanf("%d",&h);

            if(h>0)
            Custo = (h * 8/10)/2 + 10;

            printf("\n USD %6.2f ", Custo);

    }
}


