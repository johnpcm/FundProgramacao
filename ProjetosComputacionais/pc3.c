#include <stdio.h>

#define AER 100
#define VOO 10000

main()
{

    int i, j, aero[AER+1][AER+1] = {0}, aer, nvoo, voo[2];


    printf("aeroportos:");
    scanf("%d", &aer);
    printf("voos:");
    scanf("%d", &nvoo);


    printf("insira os voos agora, x -> y\n");
    for (; nvoo > 0; nvoo--)
    {
        scanf("%d %d", &voo[0], &voo[1]);
        aero[voo[0]][voo[1]]++;
    }

    for(i = 1; i < AER; i++)
        for(j = 1; j < AER; j++)
        {
            aero[i][0] += aero[i][j];
            aero[0][j] += aero[i][j];
        }

    for(i = 1; i <= aer; i++)
        if(aero[0][i] + aero[i][0] > aero[aero[0][0]][0] + aero[0][aero[0][0]]) /*se a soma de entradas e saidas do aeroporto i for maior que a soma armazenada*/
            aero[0][0] = i;


    printf("o aeroporto mais movimentado Ž: %d", aero[0][0]);
}

