#include <stdio.h>
#include <math.h>

float pi (int precisao){
    int i;
    float sm = 0, parte = 10;

    for(i = 1; fabs(parte) > pow(10, -precisao); i++){
        if (i%2 != 0){
            parte = 1/(float)i*pow(-1,(i/2));
            sm += parte;
        }
    }

    return sm*4;

}

main(){
    while(1){
        int prec;

        printf("\ninsira a precisao:\n");
        scanf("%d", &prec);

        printf("\n%.23f",pi(prec));


    }
}



