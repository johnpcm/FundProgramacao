#include "main.h"


void main(){
    /*cabeçalho*/
    printf("  _____________________________________\n");
    printf(" | Lista de alunos organizada por nota |\n");
    printf(" |_____________________________________|\n\n\n");


    /*pré declaração*/

    int nAlunos, nNotas, ordPor;


    /*input de tamanhos*/

    printf("Quantos alunos estarao na lista?");
    scanf("%d", &nAlunos);

    printf("\nQuantas notas serao levadas em conta?");
    scanf("%d", &nNotas);


    /*declaração principal de vetores*/

    int ordenador [nAlunos];
    char listaNomes [nAlunos][16];
    float listaNotas [nAlunos][nNotas+1], listaNotasVolatil [nAlunos];

    /*declaração principal de não vetores*/

    int i, k, pos;
    float menor = 1111, temp;


    /*preencher ordenador*/

    for(i = 0; i <= nAlunos; i++)
        ordenador [i]=i;
    // ordenador { 0,1,2,3,4,5...nAlunos-1}

    /*cabeçalho do input*/

    printf("\nInsira agora os dados de acordo com o modelo:\n\n Nome do Aluno\n ");

    for(i = 1; i <= nNotas; i++)
        printf("N%-3d", i);

    printf("\n");

    /*input*/

    for(i = 0; i < nAlunos; i++){
        scanf("%s", listaNomes[i]);
        for(k = 1; k <= nNotas; k++){
            scanf("%f", &listaNotas[i][k]);
        }
    }


    /*perguntar qual ordenar*/

    printf("\nDeseja ordenar por qual nota (1,2...)? 0 para media de todas");
    scanf("%d", &ordPor);

    printf("\n\n Criando arquivo");

    /*processar a media*/

    for(i = 0; i < nAlunos; i++){
        listaNotas[i][0] = 0;

        for(k = 1; k <= nNotas; k++)
            listaNotas[i][0] += listaNotas[i][k];

        listaNotas[i][0] /= nNotas;
    }
    printf(".");

    /*cria lista de trabalho*/

    for(i = 0; i < nAlunos; i++)
        listaNotasVolatil[i] = listaNotas [i][ordPor];


    /*processar a ordem no vetor*/

    for(i = 0; i < nAlunos; i++){
        menor = listaNotasVolatil[i];

        for(k = i; k < nAlunos; k++)
            if (listaNotasVolatil[k] <= menor){
                menor = listaNotasVolatil[k];
                pos = k;
                printf(".");
            }
        printf(".");


        temp = ordenador[i];
        ordenador[i] = ordenador[pos];
        ordenador[pos] = temp;

        temp = listaNotasVolatil[i];
        listaNotasVolatil[i] = listaNotasVolatil[pos];
        listaNotasVolatil[pos] = temp;
    }



    /*criar o .txt externo*/

    FILE *ofp;
    char nomeSaida[] = "documents/Lista Por Nota";

    ofp = fopen(nomeSaida, "w");

    if (ofp == NULL) {
        fprintf(stderr, "Erro, nao foi possivel abrir/criar arquivo %s!\n", nomeSaida);
        exit(1);
    }
    printf(".");

    /*imprimir tabela no arquivo*/

    fprintf(ofp, "  _____________________________________\n");
    fprintf(ofp, " |       Lista de alunos ordenada      |\n");
    fprintf(ofp, " |_____________________________________|\n\n");

    fprintf(ofp, " Nome do Aluno  Media ");

    for(i = 1; i <= nNotas; i++)
        fprintf(ofp,"N%-5d", i);

    for(i = nAlunos-1; i >= 0;i--){
        fprintf(ofp,"\n %-15s", listaNomes[ordenador[i]]);

        for(k = 0; k <= nNotas; k++)
            fprintf(ofp,"%-6.1f", listaNotas[ordenador[i]][k]);

    }


    /*fechar arquivo*/

    fclose(ofp);

    /*feedback final*/
    printf("\n\nArquivo criado com sucesso na pasta documentos!\n\n");


}

