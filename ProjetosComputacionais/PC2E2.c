
#include <stdio.h>
#include <math.h>

float f(int s,float x);


main(){

    int s;
    float x1, x2, y1, y2, out;
    printf("insira o intervalo entre virgulas:\n");
    scanf("%f,%f", &x1, &x2);
    printf("\nqual funcao deseja testar? 1: x^2 − 2^x ou 2: x^3 − 9x + 3");
    scanf("%d", &s);

    if (f(s,x1)*f(s,x2) < 0){
        while(fabs(x1-x2) > pow(10,-6)){

            out = (x2+x1)/2;

            if (f(s,x2) * f(s,out) <= 0)
                x1 = out;
            else
                x2 = out;
        }
        printf("A raiz é %f", out);

    }
    else
        printf("não há uma unica raiz neste intervalo");

}

float f(int s, float x){

    return s == 1 ? pow(x,2) - pow(2,x) : pow(x,3) - 9*x + 3;

}

