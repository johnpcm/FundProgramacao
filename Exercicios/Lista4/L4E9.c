#include <stdio.h>

main(){
    while(1){

        int n1, n2, sm1, sm2, mt1, mt2, z2, z1;
        n1 = n2 = sm1 = sm2 = mt1 = mt2 = z2 = z1 = 0;

        printf("\nInsira dois numeros para comparar:");
        scanf("%d %d",&n1,&n2);

        printf("\n%d e %d",n1,n2);

        while (n1 > 0){

            if (n1 % 10 == 0)
                z1++;

            sm1 += (n1 % 10);
            mt1 *= (n1 % 10);

            n1 /= 10;
        }

        while (n2 > 0){

            if (n2 % 10 == 0)
                z2++;

            sm2 += (n2 % 10);
            mt2 *= (n2 % 10);

            n2 /= 10;
        }

        if (sm1 == sm2 && mt1 == mt2 && z2 == z1)
            printf (" são permutacoes");
        else
            printf(" não são permutações");

    }
}
