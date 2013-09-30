#include <stdio.h>

main(){
        int i, mc, du;

        for (i = 1000; i<10000; i++){
            mc = i/100;
            du = i%100;

            if ((mc+du)*(mc+du) == i)
                printf("\n%d",i);
        }
}
