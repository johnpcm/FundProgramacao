
#include <stdio.h>
#include <math.h>

main(){
        int con[6]={0},i,in;

        do{
            printf("insira o valor do dado:\n");
            scanf("%d",&in);

            if(in > 6 || in < 1){
                printf("n‹o Ž uma face do dado\n");
                continue;
            }

            for(i=0;i<6;i++)
                if(i == in -1)
                    con[i]++;


        }while(in>0);

        printf("Faces:");

        for(i=0;i<6;i++)
            printf("\n%d == %d",i+1,con[i]);

}


