#include <stdio.h>

main(){
    int n1, n2, i, sm;
    while(1){

        printf ("\ninsira n1 e n2 entre virgulas:");
        scanf("%d,%d",&n1,&n2);


            for (i = n1 , sm = 0;i != n2+1; i++)
                if (i % 2 != 0)
                    sm += i;
            printf("a soma Ž:%d",sm);
    }

}
