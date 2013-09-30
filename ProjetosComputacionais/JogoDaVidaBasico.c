/*
    Programa Jogo da Vida
    Código modificado por João Miranda

    Atraves da entrada do usuario com o tamanho do
    tabuleiro o programa implementa e demonstra o
    jogo da vida, onde a partir de uma configuracao
    inicial as casas do tabuleiro sao consideradas
    "vivas" ou "mortas" seguindo as regras do jogo.
    O usuario insere o nro de iteraçoes que serão
    executadas e ocorre a demonstracao.
*/

#include<stdlib.h>
#include<stdio.h>

/*Funçoes no final do programa para melhor organizaçao e clareza*/

int numeroVizinhas(int **m, int i, int j); // Conta o numero de vizinhos da peça

int ** alocaMatriz(int l, int c); // Função para alocar memoria para a matriz

void preencheMatrizBlinker(int **m, int l, int c); // Preenche a tabela com valores 1 para vivo e 0 para morto

void imprimeMatriz(int **m, int l, int c); // Imprime a matriz ignorando as linhas e colunas extras

void copiaMatriz(int **fonte, int **dest, int l, int c); //realiza a copia da matriz fonte para dest ambas com dimensoes lxc



main()
{
    int **matriz, **aux, l, c, i, j, k, iter, vizinhas;
    printf("Quantidade de linhas e colunas: ");// Recebe do usuario o tamanho do tabuleiro
    scanf("%d", &l);
    scanf("%d", &c);

    printf("Quantas iterações? ");//Quantas iteraçoes serão realizadas
    scanf("%d", &iter);

    l += 2;//cria duas linhas extras
    c += 2;//cria duas colunas extras

    matriz = alocaMatriz(l, c);// Aloca memoria para a matriz, com duas colunas e linhas extras para a borda do tabuleiro
    aux = alocaMatriz(l, c);// Aloca a matriz auxiliar identica a original

    preencheMatrizBlinker(matriz, l, c);// Preenche a matriz com o padrão pré fornecido pela professora

    system("clear"); //no Mac
    imprimeMatriz(matriz, l, c);// Imprime a matriz antes de processa-la
    sleep(1); //no Mac

    copiaMatriz(matriz, aux, l, c);// Cria uma copia para comparação

    for(k = 0; k < iter; k++)
    {
        for(i = 1; i < l-1; i++) //ignora a borda
            for(j = 1; j < c-1; j++) //ignora a borda
            {
                vizinhas = numeroVizinhas(matriz,i,j); // verifica quantos vizinhos tem a peça

                if(matriz[i][j] == 1 && vizinhas < 2) // morre de solidao
                    aux[i][j] = 0;

                else if(matriz[i][j] == 1 && vizinhas > 3)// morre de superpopulacao
                    aux[i][j] = 0;

                else if(matriz[i][j] == 0 && vizinhas == 3) //vive por ter 3 vizinhos
                    aux[i][j] = 1;

            }

        copiaMatriz(aux, matriz, l, c);// Copia a matriz alterada para a matriz original

        system("clear"); //no Mac
        imprimeMatriz(matriz, l, c);
        sleep(1); //no Mac

    }
}


int numeroVizinhas(int **m, int i, int j) // Verifica a eistencia de vizinhos de determinada peça no tabuleiro, retorna o # de vizinhos vivos
{
    int auxi,auxj;
    int contador = 0;

    for(auxi = i-1; auxi <= i+1; auxi++)//percorre as linhas de cima, baixo e a propria linha da peça
    {
        for(auxj = j-1; auxj <= j+1; auxj++)// Percorre as colunas da esquerda, direita e a propria coluna da peça
        {
            if(auxi != i || auxj != j)// Testa se nao está trabalhando com a peça, para ver *apenas* os vizinhos
                if(m[auxi][auxj] == 1)// Testa se o vizinho em questão está vivo ou morto
                    contador++;
        }
    }

    return contador;//Retorna o # de vizinhos vivos
}


int ** alocaMatriz(int l, int c)  // Função para alocar memoria para a matriz, retorna um ponteiro duplo para int
{
    int i, **matriz;

    matriz = malloc(l*sizeof(int*));// Aloca o vetor de ponteiros que apontam para as linhas
    for ( i = 0; i < l; i++ )
        matriz[i] = malloc(c*sizeof(int));// Aloca as linhas da matriz

    return matriz;
}


void preencheMatrizBlinker(int **m, int l, int c)//Preenche a tabela com valores 1 para vivo e 0 para morto
{


    int i,j;

    for(i=0; i<l; i++)
        for(j=0; j<c; j++)
            m[i][j] = 0; //neste caso, está zerando também a borda adicional!

    for(j=c/2-1; j<=c/2+1; j++)
        m[l/2][j] = 1;
}


void imprimeMatriz(int **m, int l, int c) // Imprime a matriz ignorando as linhas e colunas extras
{
    int i, j;


    for(i = 1; i < l-1; i++) // Ignora a primeira e ultima linhas
    {
        for(j = 1; j < c-1; j++) // Ignora a primeira e ultima colunas
            printf("%-4d", m[i][j]);

        printf("\n\n");
    }
    fflush(stdout);
}


void copiaMatriz(int **fonte, int **dest, int l, int c) //realiza a copia da matriz fonte para dest ambas com dimensoes lxc
{
    int i, j;
    for(i=0; i<l; i++)
        for(j=0; j<c; j++)
            dest[i][j] = fonte[i][j]; //A matriz dest recebe o valor da matriz fonte
}
