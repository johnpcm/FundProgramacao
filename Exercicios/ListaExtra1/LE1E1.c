
#include <stdio.h>
#include <math.h>

main(){
    while(1){

        int x, y, xm, ym;

        printf("\nx:");
        scanf("%d", &xm);

        printf("y:");
        scanf("%d", &ym);

        for(x = 1; x <= xm; x++){
            printf("\n");
            for(y = 1; y <= ym; y++){
                printf("%5d", x*y);
            }
        }
    }
}


