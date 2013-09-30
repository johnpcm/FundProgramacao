#include <stdio.h>
#include <math.h>

//(a)an= n/n+1 , n³1
//(-1)ön/n , n³1

void seqa(int n);

void seqb(int n);

main(){
    while(1){
        int n;

        printf("insira um inteiro n");
        scanf("%d",&n);

        if (n<0)
        exit(0);

        seqa(n);
        printf ("\n\n b");
        seqb(n);

    }
}

void seqa(int n){
    int i;

    for (i = 1; i < n; i++)
        printf("\n%f", i/(float)(i+1));
}

void seqb(int n){
    int i;

    for (i = 1; i < n; i++)
        printf("\n%f", pow(-1,i)/(float)i);
}
