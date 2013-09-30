#include <stdio.h>
#include <math.h>
#include <time.h>

main(){
    srand(time(NULL));
    int i, num;
    int v[10];
    for(i=0;i<10;i++){
        v[i] = rand()%15;
    }
    printf("insira valor");
    scanf("%d",&num);
    for(i=0;i<10;i++)
        if(num == v[i])
            printf("\n\nACHEI\n\n");
        else
            printf("\nNÌO ACHEI");
}


