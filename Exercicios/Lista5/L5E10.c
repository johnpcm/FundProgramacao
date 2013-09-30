#include <stdio.h>

main(){
    while(1){

        int n=0, i=0, p=3,r=0,k=0;

        printf("insira um numero inicial:");
        scanf("%d",&n);
        printf("insira o numero de primos:");
        scanf("%d",&k);

        for(r = 0 ;r < k; n++)
        {

             if(n % 2 != 0 || n == 2)
             {

                for(i = 2, p = 3; i < n; i++)

                    if (n % i == 0)
                    {
                        p = 1;
                        break;
                    }

                if (p != 1)
                {
                    printf("%d\n",n);
                    r++;
                }

             }
        }
    }
}


