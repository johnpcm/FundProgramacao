
#include <stdio.h>

main(){
    while(1){

        int n=0, n1=0, n2=1, fb=0, i=0;

        printf("\nqual termo voce quer?");
        scanf("%d",&n);

        for(i = 3; i <= n; i++){
            fb = n1 + n2;
            n1 = n2;
            n2 = fb;
        }

        printf("\n%d",fb);
    }
}


