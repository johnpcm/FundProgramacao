#include <stdio.h>

void seq1(int n){
    int i;

    for(i = 1; i <= n; i++)
        printf("a%d = %f\n", i, (float)i/(i+1));
}

void seq2(int n){
    int i;
    float ia = 2, ip;

    printf("a1 = %d\n", ia);

    for (i = 2; i <= n; i++){
        ip = (ia + 6)/2;
        printf("a%d = %f\n", i,ip);

        ia = ip;
    }
}

main(){
    while(1){
            int in;

        printf("insira o numero de termos:");
        scanf("%d", &in);
        seq1(in);
        seq2(in);

    }
}


