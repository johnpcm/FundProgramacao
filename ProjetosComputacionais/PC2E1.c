#include <stdio.h>
#include <math.h>

#define LIMITE 100000000

//TESTES NO FINAL DO PROGRAMA

double somaSeqDeterminada(int n,float p);

double somaSeqIndeterminada(int nroCasas, float p);


main(){

    printf("%.50lf",somaSeqIndeterminada(15,5));

    printf("\n");

    printf("%.50lf",somaSeqIndeterminada(15,2.5));

    printf("\n");

    printf("%.50lf",somaSeqIndeterminada(15,1));

    printf("\n");

    printf("%.50lf",somaSeqIndeterminada(15,0.5));

}

double somaSeqDeterminada(int n, float p){ //RESPOSTA A

    double out = 0;

    for (; n < LIMITE; n++){

        out += 1.0/pow(n,p);

    }

    return out;
}

double somaSeqIndeterminada(int nroCasas, float p){ //RESPOSTA B

    int i;
    double out=0, part=0;

    for (i = 1; 1.0/pow(i,p) >= pow(10,-nroCasas) && i < LIMITE;i++){

        out += 1.0/pow(i,p);

    }
    printf("%d\n\n",i);
    return out;
}



//TESTES

/*
a)
considerando limite de 100000000 itera›es
determinada   simples 1.64472532272338867187500000000000000000000000000000
determinada   dupla   1.64493405783457502522537652112077921628952026367188

considerando precisao e-15
indeterminada simples 1.64472532272338867187500000000000000000000000000000
indeterminada dupla   1.64493403528893589182757750677410513162612915039062

b)
sim, temos que mudar o tipo da variavel 'p' para float e na sequencia indeterminada criar um limite, pois ela iria se infinita com valores n‹o maiores que 1.

c)
considerando limite de 100000000 iterac›es
p = 5    1.03692775514312218732015935529489070177078247070312   1001
p = 2.5  1.34148725658587553155598470766562968492507934570312   1000001
p = 1    18.9978964038525539592683344380930066108703613281250   100000000
p = 0.5  19998.5395954930390871595591306686401367187500000000   100000000

d)
(pi^2)/6 = 1.64493406685
Ž o mesmo valor, pode usar ent‹o essa fun‹o para achar o valor de pi.
*/
