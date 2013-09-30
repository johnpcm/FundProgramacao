 #include <stdio.h>

main(){
    //declaracao

    int inum=0, onum=0;

    //entrada
    printf("Insira um numero de 3 digitos para inverter:");
    scanf("%d",&inum);
    //processo

    while (inum>0){
        onum = onum*10 + inum%10;
        inum /= 10;
        printf("in %d\n out %d\n",inum, onum);
    }


    //saida
    printf("O numero invertido eh: %d", onum);
}
