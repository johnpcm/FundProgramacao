#include <stdio.h>

main(){
    while(1){

        int a1, a2, a3, s1, s2, s3, p = 0;


        printf("\ninsira as apostas entre virgulas (x,x,x)");
        scanf("%d,%d,%d", &a1, &a2, &a3);
        printf("agora insira os numeros sorteados (x,x,x)");
        scanf("%d,%d,%d", &s1, &s2, &s3);



        p += a1 == s1 || a1 == s2 || a1 == s3 ? 1 : 0;

        if (a2 == s1 || a2 == s2 || a2 == s3)
            p++;
        if (a3 == s1 || a3 == s2 || a3 == s3)
            p++;

        printf("O numero de acertos foi de %d", p);
    }


}
