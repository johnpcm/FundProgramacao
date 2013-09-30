#include <stdio.h>
#include <math.h>

main(){
    while(1){
    int g;
    double lock, i, b;

    printf("\nqual Ž a senha numerica?");
    scanf("%lf", &lock);
    b=lock;
    for( g=0; (int)lock!= 0; g++){

        lock /= 10;
        printf("\n%d", g);
    }

    for( i=-1 + pow(10,g-1) ; i!=b; i++,printf("\n%lf", i)){}

    printf("a senha Ž:%lf", i);
}
}
