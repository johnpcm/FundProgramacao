#include <stdio.h>

float renda;

int main () {
printf ("Insira a renda mensal de Paulo:");
scanf("%f", &renda);
printf("Os valores aplicados s�o:\n Para sa�de: %6.2f \n Para educa��o: %6.2f \n Para alimenta��o: %6.2f \n Para vestu�rio: %6.2f \n Para lazer: %6.2f \n E para os outros gastos: %6.2f \n", renda*0.1, renda*0.25, renda*0.3, renda*0.1, renda*0.05, renda*0.2);
}
