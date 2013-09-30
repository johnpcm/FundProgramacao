#include <stdio.h>



main(){
        //declaracao

    int conta, bkpconta, inv, soma, bkpSoma, tam, soma2, digVer;

        //limpeza

        inicio:
        conta = bkpconta = inv = soma = bkpSoma = tam = soma2 = digVer = 0;

        //entrada

        printf("Qual eh o numero da conta?");
        scanf("%d", &conta);
        bkpconta = conta;

        //processo1: inverter

        while (conta>0){
            inv = inv*10 + conta%10;
            conta /= 10;
        }
        conta = bkpconta;

        //processo2: somar

        soma = conta + inv;
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

        printf("O numero da conta com digito verificador eh:%d-%d\n", conta, digVer);

        goto inicio;


}
