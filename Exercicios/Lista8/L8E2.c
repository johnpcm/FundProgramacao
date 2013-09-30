
#include <stdio.h>
#include <math.h>


main(){
    while(1){
        int v[5], i;

        for (i=0;i<5;i++)
            scanf("%d", &v[i]);

        for (i=0;i<5;i++)
            if(v[i]%2==1)
                printf("%d", v[i]);
    }
}


