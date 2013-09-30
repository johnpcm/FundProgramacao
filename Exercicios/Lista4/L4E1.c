#include <stdio.h>

main(){
    while(1){
            int n, sm = 0;

            printf("\ninsira o numero maximo");
            scanf("%d", &n);

            for (int i = 0; i <= n; i++)
                sm += i;

            printf ("\na soma Ž %d", sm);


    }
}


