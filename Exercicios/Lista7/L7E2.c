#include <stdio.h>
#include <math.h>
#include <float.h>


float somaa(){
    float sm=0, p = 1;
    for (int i = 1; p > pow(10,-5); i++){
        p = 1/pow(2,i);
        sm += p;
    }
    return sm;
}


float somab(float a,float r){
    float sm=0, p = 1;
    for (int i = 1;p > pow(10,-5); i++){
        p = a*pow(r, i-1);
        sm += p;
    }

    return sm;
}


main(){
            float x,y;
            printf("\ninsira a e r");
            scanf("%f %f", &x, &y);

            if(x != 0 && sqrt(pow(y,2)) < 1 ){
            printf ("\n\n%f", somaa());
            printf ("\n\n%f", somab(x,y));
            }
            else
                printf("erro");
}


