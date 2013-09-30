/*
    Programa Jogo da Vida
    C�digo modificado por Jo�o Miranda

    Atraves da entrada do usuario com o tamanho do
    tabuleiro o programa implementa e demonstra o
    jogo da vida, onde a partir de uma configuracao
    inicial as casas do tabuleiro sao consideradas
    "vivas" ou "mortas" seguindo as regras do jogo.
    O usuario insere o nro de itera�oes que ser�o
    executadas, qual padrao inicial ele deseja que
    seja executado, podendo ele criar um novo padrao
    e ocorre a demonstracao.
*/

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

/*Fun�oes no final do programa para melhor organiza�ao e clareza*/

int numeroVizinhas(int **m, int i, int j); // Conta o numero de vizinhos da pe�a

int ** alocaMatriz(int l, int c); // Fun��o para alocar memoria para a matriz

void preencheMatrizPadrao(int **m, int l, int c, int padrao); // Preenche a tabela com valores 1 para vivo e 0 para morto

void imprimeMatriz(int **m, int l, int c); // Imprime a matriz ignorando as linhas e colunas extras

void copiaMatriz(int **fonte, int **dest, int l, int c); //realiza a copia da matriz fonte para dest ambas com dimensoes lxc

void randMatriz(int **m, int l, int c, int lim);//Preenche a matriz com numeros aleatorios de limite lim

void preencheMatrizLivre(int **m,int l,int c);//Preenche a matriz com o input do usuario


main()
{

    int **matriz, **aux, l, c, i, j, k, iter, vizinhas, menu = 0, padrao;

    while(menu == 0)//La�o de repeti��o do menu
    {
        system("clear");
        printf("Quantidade de linhas e colunas: ");// Recebe do usuario o tamanho do tabuleiro
        scanf("%d", &l);
        scanf("%d", &c);

        l += 2;//adiciona as linhas de borda permanentemente
        c += 2;//adiciona as colunas de borda permanentemente

        matriz = alocaMatriz(l, c);// Aloca memoria para a matriz, com duas colunas e linhas extras para a borda do tabuleiro
        aux = alocaMatriz(l, c);// Aloca a matriz auxiliar identica a original



        system("clear");
        printf("Deseja usar algum padr�o inicial ou uma forma livre?\n\n1.Formas Geometricas\n2.Aleatorio\n3.Desenho livre\n0.Come�ar de novo\n");//Menu para padr�o inicial
        scanf("%d", &menu);

        switch(menu)
        {
        case 1:
            printf("Escolha um modelo:\n\n1.Linha\n2.X\n3.Quadrado\n");
            scanf("%d", &menu);
            switch(menu)
            {
            case 1:
                preencheMatrizPadrao(matriz,l,c,1);//Linha de lado a lado no tabuleiro

                break;
            case 2:
                preencheMatrizPadrao(matriz,l,c,2);//Diagonais do tabuleiro

                break;
            case 3:
                preencheMatrizPadrao(matriz,l,c,3);//Quadrado nas linhas e colunas mais externas do tabuleiro

                break;
            default:
                menu = 0;

                break;
            }

            break;
        case 2:
            randMatriz(matriz,l,c,2); // Preenche aleatoriamente com vivos e mortos

            break;
        case 3:
            preencheMatrizLivre(matriz,l,c); // Usuario insere os valores do tabuleiro

            break;
        default:
            menu = 0;

            break;
        }
    }
    printf("Quantas itera��es? ");//Quantas itera�oes ser�o realizadas
    scanf("%d", &iter);

    system("clear"); //no Mac
    imprimeMatriz(matriz, l, c);// Imprime a matriz antes de processa-la
    sleep(1); //no Mac

    copiaMatriz(matriz, aux, l, c);// Cria uma copia para compara��o

    for(k = 0; k < iter; k++)
    {
        for(i = 1; i < l-1; i++) //ignora a borda
            for(j = 1; j < c-1; j++) //ignora a borda
            {
                vizinhas = numeroVizinhas(matriz,i,j); // verifica quantos vizinhos tem a pe�a

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


int numeroVizinhas(int **m, int i, int j) // Verifica a eistencia de vizinhos de determinada pe�a no tabuleiro, retorna o # de vizinhos vivos
{
    int auxi,auxj;
    int contador = 0;

    for(auxi = i-1; auxi <= i+1; auxi++)//percorre as linhas de cima, baixo e a propria linha da pe�a
    {
        for(auxj = j-1; auxj <= j+1; auxj++)// Percorre as colunas da esquerda, direita e a propria coluna da pe�a
        {
            if(auxi != i || auxj != j)// Testa se nao est� trabalhando com a pe�a, para ver *apenas* os vizinhos
                if(m[auxi][auxj] == 1)// Testa se o vizinho em quest�o est� vivo ou morto
                    contador++;
        }
    }

    return contador;//Retorna o # de vizinhos vivos
}

int ** alocaMatriz(int l, int c)  // Fun��o para alocar memoria para a matriz, retorna um ponteiro duplo para int
{
    int i, **matriz;

    matriz = malloc(l*sizeof(int*));// Aloca o vetor de ponteiros que apontam para as linhas
    for ( i = 0; i < l; i++ )
        matriz[i] = malloc(c*sizeof(int));// Aloca as linhas da matriz

    return matriz;
}


void preencheMatrizPadrao(int **m, int l, int c, int padrao)//Preenche a tabela com valores 1 para vivo e 0 para morto seguindo um padrao informado
{

    int i,j;

    for(i=0; i<l; i++)//Zera a tabela inteira
        for(j=0; j<c; j++)
            m[i][j] = 0; //neste caso, est� zerando tamb�m a borda adicional

    switch(padrao)
    {
    case 1:// cria o padr�o linha
        for(j = 1; j < c-1; j++)
            m[l/2][j] = 1;

        break;
    case 2:// cria o padrao X
        for(i = 1; i < l-1; i++)
            for(j = 1; j < c-1; j++)
                if(i == j || i+j == c)
                    m[i][j] = 1;

        break;
    case 3:// cria o padr�o quadrado
        for(i = 1; i < l-1; i++)
            for(j = 1; j < c-1; j++)
                if(i == 1 || j == 1 || i == l-2 || j == c-2)
                    m[i][j] = 1;
        break;

    }
}


void imprimeMatriz(int **m, int l, int c) // Imprime a matriz ignorando as linhas e colunas extras
{
    int i, j;


    for(i = 1; i < l-1; i++) // Ignora a primeira e ultima linhas
    {
        for(j = 1; j < c-1; j++)
            if(m[i][j] == 1)// Ignora a primeira e ultima colunas
                printf("%-4d", m[i][j]);
            else
                printf("-   ");

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


void randMatriz(int **m, int l, int c, int lim)// Preenche a matriz com valores aleatorios ignorando as bordas
{
    int i, j;

    srand(time(NULL));

    for(i = 1; i < l-1; i++)
        for(j = 1; j < c-1; j++)
            m[i][j] = rand()%lim;
}

void preencheMatrizLivre(int **m,int l,int c)//Usuario preenche a tabela como quiser
{
    int i,j;

    for(i=0; i<l; i++)//Zera a tabela inteira
        for(j=0; j<c; j++)
            m[i][j] = 0; //neste caso, est� zerando tamb�m a borda adicional

    l -= 2;//Corre�ao para imprimir e editar apenas o que se pode acessar
    c -= 2;

    system("clear");
    printf("Insira a sua tabela %d por %d",l,c);

    for(i = 0; i < l; i++)
        for(j = 0; j < c; j++)
        {
            scanf("%d", &m[i][j]);// Insere o valor dado diretamente na tabela
            if(m[i][j] != 0)// todos os valores que nao forem 0 serao transformados em 1 para evitar erros
                m[i][j] = 1;
        }
}
