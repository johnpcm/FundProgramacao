
#include <stdio.h>
#include <math.h>

main(){
    while(1){
        int vp[10],vi[10],vtj[20],i,k;

        printf("\nvetor1\n");
        for (i=0;i<10;i++)
            scanf("%d", &vp[i]);

        printf("\nvetor2\n");
        for (i=0;i<10;i++)
            scanf("%d", &vi[i]);

        for (i=0,k=0;i<20;i++)
            if (i%2==0){
                vtj[i] = vp[k];
            }
            else{
                vtj[i] = vi[k];
                k++;
            }

        for(i=0;i<20;i++)
            printf("\n%d",vtj[i]);



}

}
