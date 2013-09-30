
#include <stdio.h>
#include <math.h>
#include <time.h>

main(){
    srand(time(NULL));
    int i, num, neg=0, sm=0;
    int v[10];
    for(i=0;i<10;i++){
        v[i] = (rand()*rand())%15;
        printf("\n%d\n",v[i]);
    }
    for(i=0;i<10;i++)
        if(v[i] < 1)
            neg++;
        else
            sm += v[i];

    printf("soma %d, negativos %d", sm, neg);

}


