#include <stdio.h>

main(){
    //declaracao

    int inum, onum;

    //entrada
    printf("Insira um numero de 3 digitos para inverter:");
    scanf("%d", &inum);

    //processo

    while (inum>=0){
        onum = onum*10 + inum%10;
        inum /= 10;
    }


    //saida
    printf("O numero invertido eh: %d", onum);
}
