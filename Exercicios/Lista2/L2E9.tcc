#include <stdio.h>

main(){
        //declaracao
    int nCon=0, bkpNCon=0, inv=0, soma=0, bkpSoma=0, tam=0, soma2=0, digVer=0;

        //entrada

        printf("Qual Ž o numero da conta?");
        scanf("%d", &nCon);
        bkpNCon = nCon;

        //processo1: inverso

        while (nCon>0){
            inv = inv*10 + nCon%10;
            nCon /= 10;
        }
        nCon = bkpNCon;

        //processo2: somar

        soma = nCon + inv;
        bkpSoma = soma;

        //processo3: descobrir tamanho do # da soma

        while(soma>0){
                tam++;
                soma /= 10;
        }
        soma = bkpSoma;

        //processo4: multiplicar e somar os digitos

        while(soma>0){
            soma2 += (soma%10)*tam;
            tam--;
            soma /= 10;
        }


        //processo4: achar dig. verificador

        digVer = soma2%10;

        //saida

        printf("O numero da conta com digito verificador Ž:%d-%d", nCon, digVer);


}
