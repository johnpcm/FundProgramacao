
#include <stdio.h>
#include <math.h>

main(){
        int v[10] = {1,0,2,3,0,4,0,0,5,0},i,k,e=0,temp;

        for (i=0;i<10;i++){
            printf("%d ", v[i]);
     //       printf("insira o numero %d: ", i);
     //       scanf("%d", &v[i]);

        }
            printf("\n", v[i]);
        for (i=0;i<10;i++){
            if(v[i]==0){
                for(k=i;k<10 ;k++){
                    if(v[k]!=0){
                        temp = v[i];
                        v[i] = v[k];
                        v[k] = temp;
                        break;
                    }
                }
            }
        }
    for(i=0;i<10;i++)
        printf("%d ",v[i]);
}


