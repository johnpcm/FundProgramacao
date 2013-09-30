#include <joao.h>
#define AER 5


int main()
{

    int i, j, aero[6][6] = {0}, menu, dep = 1, arr = 1;
    char yn;

    while (!senha(1994));

    system("clear");

    while(1)
    {

        printf("\n1.Cadastrar um voo\n2.Dois ou mais voos\n3.Imprimir tabela de voos\n4.Buscar um voo\n0.Sair do sistema\n");
        scanf("%d", &menu);

        system("clear");

        switch(menu)
        {
        case 1:

            printf("insira o aeroporto de origem seguido do de destino:\n");
            scanf("%d %d", &dep, &arr);
            aero[dep][arr] = 1;
            break;

        case 2:

            printf("insira os aeroportos de origem seguidos dos de destino, use 0 para seguir.\n");

            while(dep > 0 || arr > 0)
            {
                scanf("%d %d",&dep, &arr);
                aero[dep][arr] = 1;
            }

            break;

        case 3:

            for(i = 0; i < AER+1; i++)
            {
                aero[i][0] = i;
                aero[0][i] = i;
            }
            printMITabVoo(aero, AER+1, AER+1);
            break;

        case 4:

        default:
            exit(0);
        }
        return 0;
    }
}
int busca()
{
    int dep, arr, menu;
    char yn;
    printf("\n\nDe qual aeroporto deseja partir?\n");
    scanf("%d", &dep);

    printf("\nQual aeroporto deseja chegar?\n");
    scanf("%d", &arr);

    printf("\n\nVoce deseja procurar voos:\n1.Sem conexoes\n2.Com exatamente um numero de conexoes\n3.Com ate um numero de conexoes\n0.Voltar ao menu anterior\n");
    scanf("%d", &menu);
    system("clear");
    switch(menu)
    {
    case 1:

        if (aero[dep][arr] == 1){
            printf("");
        }
        else
            printf("Não existem voos sem conexao entre estes aeroportos.\n");

        break;
    case 2:

        break;
    case 3:

        break;
    default:

        break;
    }
    printf("\nDeseja realizar outra busca?")
    scanf("%c", &yn);
    switch(yn)
    {
    case y:
        return 1;
    case n:
        return 0;
    }
}
void cabecalho()
