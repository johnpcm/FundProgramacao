#include <stdio.h>

main (){
    while(1){
        int n1, n2, i;

        printf ("\ninsira n1 e n2 entre virgulas:");
        scanf("%d,%d",&n1,&n2);


            for (i = n1;i!=n2; i++)
                if (i % 2 != 0)
                    printf ("\n%d", i);

    }

}
