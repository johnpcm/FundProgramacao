#include <stdio.h>

main(){

    int a,b,c;
    float med;

    while(1){

        printf("insira as notas dos alunos separadas por virgulas:");
        scanf("%d,%d,%d", &a, &b, &c);

        med = (a*2 + b*3 + c*5)/10;

        if (med >= 6 && med <= 10){
            printf("Aprovado!\n");
        }
        else if (med >= 0 && med < 6){
            printf("Reprovado!\n");
        }
        else{
            printf("As notas digitadas s‹o invalidas\n");
        }
    }

}
