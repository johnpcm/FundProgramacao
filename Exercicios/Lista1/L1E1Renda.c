#include <stdio.h>

float renda;

int main () {
printf ("Insira a renda mensal de Paulo:");
scanf("%f", &renda);
printf("Os valores aplicados são:\n Para saúde: %6.2f \n Para educação: %6.2f \n Para alimentação: %6.2f \n Para vestuário: %6.2f \n Para lazer: %6.2f \n E para os outros gastos: %6.2f \n", renda*0.1, renda*0.25, renda*0.3, renda*0.1, renda*0.05, renda*0.2);
}
