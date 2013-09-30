#include <stdio.h>

main(){
    int a, b, temp;
    printf("insira um numero inteiro a:");
    scanf("%d", &a);
    printf("insira um numero inteiro b:");
    scanf("%d", &b);
    temp = a;
    a = b;
    b = temp;
    printf("a=%d b=%d", a, b);
}
