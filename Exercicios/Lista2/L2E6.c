#include <stdio.h>


main(){
    float n1, n2, n3, Max, Min, Mid;
    inicio:

    printf("Insira 3 numeros quaisquer:\nA:");
    scanf("%f", &n1);
    printf("B:");
    scanf("%f", &n2);
    printf("C:");
    scanf("%f", &n3);

    if (n1 > n2){

        if(n1 > n3){

            if(n2 > n3){
                goto opc6;

            } //n1 > n3 > n2
            else {
                goto opc4;
            }
        } //n3 > n1 > n2
        else {
            goto opc3;
        }
    }// n2 > n1
    else if (n1 < n3){

            if (n2 < n3){
                goto opc1;

            }//n2 > n3 > n1
            else{
                goto opc2;
            }

    }// n2 > n1 > n3
    else{
        goto opc5;
    }
opc1:
    Min=n1;
    Mid=n2;
    Max=n3;
    goto print;
opc2:
    Min=n1;
    Mid=n3;
    Max=n2;
    goto print;
opc3:
    Min=n2;
    Mid=n1;
    Max=n3;
    goto print;
opc4:
    Min=n2;
    Mid=n3;
    Max=n1;
    goto print;
opc5:
    Min=n3;
    Mid=n1;
    Max=n2;
    goto print;
opc6:
    Min=n3;
    Mid=n2;
    Max=n1;
    goto print;

print:
    printf("De menor para maior os numeros s‹o:\n%6.2f\n%6.2f\n%6.2f\n", Min, Mid, Max);

goto inicio;

}
