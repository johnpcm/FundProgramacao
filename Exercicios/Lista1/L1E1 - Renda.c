#include <stdio.h>

float renda;

int main () {
printf ("Insira a renda mensal de Paulo:");
scanf("%f", &renda);
printf("Os valores aplicados são:\n Para saúde: %f \n Para educação: %f \n Para alimentação: %f \n Para vestuário: %f \n Para lazer: %f \n E para os outros gastos: %f \n", renda*0.1, renda*0.25, renda*0.3, renda*0.1, renda*0.05, renda*0.2);
}
