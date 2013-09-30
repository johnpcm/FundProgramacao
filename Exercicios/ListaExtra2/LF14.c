#include <stdio.h>

main(){
    int n1, n2, i, sm, c;
    while(1){

        printf ("\ninsira n1 e n2 entre virgulas:");
        scanf("%d,%d",&n1,&n2);


            for (i = n1 , sm = 0, c = 0;i != n2+1; i++)
                if (i % 2 != 0){
                    sm += i;
                    c++;
                }
            printf("a media Ž:%f",(float)sm/c);
    }
}
