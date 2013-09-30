#include <stdio.h>

main(){
    while(1){

    int n, i;

    printf("\ninsira um nœmero:");
    scanf("%d",&n);

    for(i = 1; i <= n; i++)
        if (n % i == 0)
            printf("\n%d",i);

    }
}


