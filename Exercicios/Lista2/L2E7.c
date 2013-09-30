#include <stdio.h>

main(){
    int acervo;
    float preco;

    printf("Quantos filme h‡ no acervo da locadora?");
    scanf("%d", &acervo);
    printf("Quanto esta custando o aluguel?");
    scanf("%f", &preco);

    printf("A locadora dever‡ faturar, por ano, R$ %6.2f. \nDesse faturamento, R$%6.2f por mes s‹o provenientes de multas por atraso. \nDevido a desgaste dos filmes, existir‹o no final do ano %3.0f filmes no acervo.\n", (acervo/3)*preco*12, (acervo/3/10)*(preco*0.1), acervo*0.98);
}
