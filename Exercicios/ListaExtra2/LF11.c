#include<stdio.h>

main(){
    int i = 1;
    while (i<=100){
        if (i % 2 == 0)
            printf("\n%d", i);
        i++;
    }
    for (i = 1 ; i<=100 ; i++)
        if (i % 2 == 0)
            printf("\n%d", i);

}
