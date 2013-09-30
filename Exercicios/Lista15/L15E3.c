#include <joao.h>
#define NO 5

typedef struct
{

    char nome[50];
    int dia;
    int mes;

} Registro;


main()
{

    int i, menu, swt = 1;
    Registro niv[NO];

    while (swt)
    {
        system ("clear");
        printf("1 - cadastro, 2 - consulta, 0 - sair");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            for(i = 0; i < NO; i++){
                printf("Nome DD/MM: ");
                scanf("%s %d/%d", &niv[i].nome, &niv[i].dia, &niv[i].mes);
            }
            break;
        case 2:
            printf("Qual mes deseja consultar? 1-12");
            scanf("%d", menu);
            for(i = 0; i < NO; i++)
                if()
        default:
            swt = 0;
            break;
        }

    }



}
