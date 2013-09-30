#include "main.h"

main(){
    while(1){

        int in, ina, t=1, ta;
        scanf("%d", &ina);
        while(in != -1){
            scanf("%d", &in);
            if (in > ina){
                t++;
                if(t > ta)
                    ta = t;
            }
            else
                t=1;
            ina = in;

        }

        printf("tamanho da maior sequencia crescente Ž: %d ", ta );

    }
}


