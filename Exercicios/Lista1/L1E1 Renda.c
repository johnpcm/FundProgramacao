#include <stdio.h>

float renda;

int main () {
printf ("Insira a renda mensal de Paulo:");
scanf("%f", &renda);
printf("Os valores aplicados s�o:\n Para sa�de: %f \n Para educa��o: %f \n Para alimenta��o: %f \n Para vestu�rio: %f \n Para lazer: %f \n E para os outros gastos: %f \n", renda*0.1, renda*0.25, renda*0.3, renda*0.1, renda*0.05, renda*0.2);
}
