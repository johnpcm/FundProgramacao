#include <stdio.h>
#include <stdlib.h>

//Protótipos
int ** alocaMatriz (int nlinhas, int ncolunas);
void desalocaMatriz(int ** matriz, int nlinhas);
int ** leImagem(char *entrada, int *nlinhas, int *ncolunas, int *maxCinza);
void gravaImagem(char *saida, int **matriz, int nlinhas, int ncolunas);
void negativoImagem (int **imagem, int ** resultado, int ncolunas, int nlinhas);
void binarizaImagem (int **imagem, int **resultado, int ncolunas, int nlinhas);
void ruidoMedia (int **imagem, int **resultado, int ncolunas, int nlinhas);
void ruidoMediana (int **imagem, int **resultado, int ncolunas, int nlinhas);
void organizarVet(int v[], int n);

//Função principal

int main (int argc, char *argv[])//argc é o numero de argumentos, argv é um vetor de ponteiros para os argumentos dados em forma de string
{

    if (argc < 3)//testa se possui 3 argumentos, a chamada do programa, o arquivo de entrada e o arquivo de saida
    {
        printf("Uso: %s image_de_entrada.pbm imagem_de_saida.pgm\n", argv[0]);
        exit(1);
    }
    //Declaração de variáveis
    int ncolunas, nlinhas, maxCinza, op;
    int **imagemEntrada,
        **imagemProcessada;

    //menu
    system("clear");
    printf("\nO que deseja fazer?\n");
    printf("1 - negativo\n");
    printf("2 - binarizacao\n");
    printf("3 - filtro da media\n");
    printf("4 - filtro da mediana\n");
    scanf("%d", &op);

    //leitura da imagem de entrada, cujo nome foi passado como argumento para a main()
    imagemEntrada = leImagem(argv[1], &nlinhas, &ncolunas, &maxCinza);
    // aloca espaço na memória para guardar o resultado do processamento
    imagemProcessada = alocaMatriz(nlinhas, ncolunas);

    switch(op)
    {

    case 1:
        //calcula o negativo da imagem
        negativoImagem (imagemEntrada, imagemProcessada, ncolunas, nlinhas);
        //grava a imagem processada em um arquivo pgm
        gravaImagem(argv[2], imagemProcessada, nlinhas, ncolunas);
        break;
    case 2:
        //deixa a imagem apenas com um contraste binário, seguindo o pedido do usuario
        binarizaImagem (imagemEntrada, imagemProcessada, ncolunas, nlinhas);
        //grava a imagem processada em um arquivo pgm
        gravaImagem(argv[2], imagemProcessada, nlinhas, ncolunas);
        break;
    case 3:
        //Retira o ruido pelo método da média
        ruidoMedia (imagemEntrada, imagemProcessada, ncolunas, nlinhas);
        //grava a imagem processada em um arquivo pgm
        gravaImagem(argv[2], imagemProcessada, nlinhas, ncolunas);
        break;
    case 4:
        //retira o ruido pelo método da mediana
        ruidoMediana (imagemEntrada, imagemProcessada, ncolunas, nlinhas);
        //grava a imagem processada em um arquivo pgm
        gravaImagem(argv[2], imagemProcessada, nlinhas, ncolunas);
        break;
    default:
        printf("Opcao invalida!");
    }

    desalocaMatriz(imagemEntrada, nlinhas);
    desalocaMatriz(imagemProcessada, nlinhas);

    return 0;
}

int ** alocaMatriz (int nlinhas, int ncolunas)//Função para alocar a matriz
{
    int **m, i;

    m = (int**) malloc(nlinhas*sizeof(int*));

    for (i = 0; i < nlinhas; i++)
        m[i] = (int*) malloc(ncolunas*sizeof(int));

    return m;
}

void desalocaMatriz(int **matriz, int nlinhas)// Função para desalocar a matriz
{
    int i;

    for(i = 0; i < nlinhas; i++)
        free(matriz[i]);

    free(matriz);
}


int ** leImagem(char *entrada, int *nlinhas, int *ncolunas, int *maxCinza)// Le a imagem passada por argumento para main
{
    char type[3], c;
    int **matriz;

    //Abertura do arquivo que contem a imagem de entrada*/
    FILE *arq_imagem_entrada = fopen(entrada, "r");

    //Leitura o cabecalho da imagem
    //tipo da imagem pgm: P2 ou P5
    fgets(type, 4, arq_imagem_entrada);
    //é preciso ignorar o comentário
    c = fgetc (arq_imagem_entrada);
    if (c == '#')
    {
        while ((c != '\n') && (c != EOF))
        {
            c = fgetc (arq_imagem_entrada);
        }
    }

    //leitura das informações de interesse
    fscanf(arq_imagem_entrada, "%d %d %d", ncolunas, nlinhas, maxCinza);

    //alocacao dinamica de memoria para a matriz que  armazena a imagem
    matriz = alocaMatriz (*nlinhas, *ncolunas);

    //leitura da imagem na matriz
    int i, j;
    for (i = 0; i < *nlinhas; i++)
    {
        for (j = 0; j < *ncolunas; j++)
        {
            fscanf(arq_imagem_entrada, "%d", &matriz[i][j]);
        }
    }

    //"fecha" a referência para arquivo que armazena imagem de entrada
    fclose(arq_imagem_entrada);

    return matriz;
}

void gravaImagem(char *saida, int **matriz, int nlinhas, int ncolunas)// grava uma imagem de saida
{
    //Abertura do arquivo que armazena a imagem de saída
    FILE *arq_imagem_saida = fopen(saida, "w");
    int i,j;

    //Escrita da saída
    fprintf(arq_imagem_saida, "P2\n%d %d\n255\n", ncolunas, nlinhas);
    for (i = 0; i < nlinhas; i++)
    {
        for (j = 0; j < ncolunas; j++)
        {
            fprintf(arq_imagem_saida, "%d ", matriz[i][j]); /*escrevendo o valor do pixel no arquivo*/
            if ((j != 0) && (j % 12) == 0) /*adicionando quebras a cada 12 linhas no arquivo*/
                fprintf(arq_imagem_saida, "\n");
        }
    }
    //Fecha o arquivo
    fclose(arq_imagem_saida);
}

void negativoImagem (int **imagem, int **resultado, int ncolunas, int nlinhas)//Calcula o negativo da imagem
{
    int i, j;
    for (i = 1; i < nlinhas - 1; i++)
    {
        for (j = 1; j < ncolunas - 1; j++)
        {
            //calcula o negativo da imagem
            resultado[i][j] = 255 - imagem[i][j];
        }
    }
}

void binarizaImagem (int **imagem, int **resultado, int ncolunas, int nlinhas)
{

    int i, j, limi;
    printf("insira o limiar:");
    scanf("%d", &limi);
    for (i = 0; i < nlinhas; i++)
        for (j = 0; j < ncolunas; j++)
            if (imagem[i][j] >= limi)
                resultado[i][j] = 255;// caso seja mais claro que o termo recebido pelo usuario, branco
            else
                resultado[i][j] = 0;//caso contrario preto
}

void ruidoMedia (int **imagem, int **resultado, int ncolunas, int nlinhas)
{

    int i, j, k, c, sm;
    for (i = 1; i < nlinhas-1; i++)
        for (j = 1; j < ncolunas-1; j++)
        {
            sm = 0;
            for (k = i-1; k <= i+1; k++)
                for (c = j-1; c <= j+1; c++)
                    sm += imagem[k][c];

            resultado[i][j] = ((sm-imagem[i][j])/ 8);//Faz a media dos pixels em torno do pixel analisado

        }


}

void ruidoMediana (int **imagem, int **resultado, int ncolunas, int nlinhas)
{

    int i, j, k, c, n, org[8];

    for (i = 1; i < nlinhas-1; i++)
        for (j = 1; j < ncolunas-1; j++)
        {

            n = 0;
            for (k = 0; k < 8; k++)// zera o vetor
                org[k] = 0;

            for (k = i-1; k <= i+1; k++)
                for (c = j-1; c <= j+1; c++, n++)
                    org[n] = imagem[k][c];//posiciona todos os pixels em volta do pixel central em um vetor

            organizarVet(org,8);// organiza esse vetor
            resultado[i][j] = (org[3]+org[4])/2;// faz a media entre os termos centrais(mediana)
        }
}

void organizarVet(int v[], int n)//Organiza o vetor de menor a maior
{

    int i, j, temp;

    for(i = 0; i < n; i++)
        for(j = i; j > 0 && v[j] < v[j-1]; j--)
        {
            temp = v[j];
            v[j] = v[j-1];
            v[j-1] = temp;
        }

}
