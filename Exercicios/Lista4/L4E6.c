
#include <stdio.h>

main(){
    int sm, r = 10000, i, i2;

    for( i=0 ; i < r ; i++){
        for( i2 = 1, sm = 0; i2 < i; i2++){
            if ( i % i2 == 0)
                sm += i2;
        }
        if (sm == i)
            printf("\n%d\n", i);
    }
}
