//INCLUDES

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>


//CONSTANTES

#define PI 3.14159265359

//INDICE DE FUNCOES

int calc(int x, char op, int y);// CALCULA A CONTA DE ACORDO COM O MODELO (X+Y) COM QUALQUER OPERADOR BASICO + / - *

float precPi(int precisao);//CALCULA O PI COM DETERMINADA PRECISAO

float pi();//RETORNA O VALOR DE PI COM PRECISAO MAXIMA (8)

float smedia();//PEDE UMA SEQUENCIA DE NUMEROS PARA O USUARIO E RETORNA A MEDIA DELES

int bi6(int ano);// RETORNA 1 SE O ANO FOR BISSEXTO 0 SE NAO FOR

int primo(int in);//RETORNA 1 SE NUMERO FOR PRIMO E 0 SE NAO FOR

double fib(int n);//RETORNA O NESIMO TERMO DA SEQ DE FIBONACCI

/*VETORES*/

void printVeti(int v[], int tam); //IMPRIME VETOR

void inputVeti(int v[], int tam); //LE UM VETOR DO TECLADO

int * allocVeti(int tam); // RETORNA O ENDERECO ALOCADO

void randVet(int v[], int tam, int lim); //PREENCHE O VETOR ALEATORIAMENTE

/*MATRIZES*/

void printMICab(int m[],int l, int c);//IMPRIME A MATRIZ COM CABECALHO

void printMI(int m[],int l, int c);//IMPRIME A MATRIZ

void multiMatriz(int a[], int b[], int c[], int m, int n, int p);//MULTIPLICA AS DUAS MATRIZES A E B, RETORNANDO NA MATRIZ C, USANDO AS DIMENSOES MxN PARA A E NxP PARA B

void randMatriz(int matriz[], int l, int c, int lim);//PREENCHE A MATRIZ COM ALEATORIOS

void invertMtatriz(float a[],int m);//INVERTE A MATRIZ QUADRADA DE DIMENSOES MxM

void floatxMatriz(float a[], float x, int m, int n);//MULTIPLICA A MATRIZ MxN PELO NUMERO X

float detMatriz(float a[], int m);//CALCULA O DETERMINANTE DA MATRIZ MxM

void transpMatriz(float a[], int m);//CALCULA A TRANSPOSTA DA MATRIZ MxM

void smMatriz(float a[], float b[], int m, int n);//SOMA DUAS MATRIZES aplicando em A

void copyMatriz(int mat[], int mat1[], int i, int j);//COPIA UMA MATRIZ SOBRE A OUTRA
//FUNCOES EXECUCAO

int calc(int x, char op, int y)
{

    switch (op)
    {
    case '+':
        return (x+y);

    case '-':
        return (x-y);

    case '*':
        return (x*y);

    case '/':
        return (x/y);

    default:
        printf("erro\n");
        exit(1);
    }

}

float precPi (int precisao)
{

    int i;
    float sm = 0, parte = 10;

    for(i = 1; fabs(parte) > pow(10, -precisao); i++)
    {
        if (i%2 != 0)
        {
            parte = 1/(float)i*pow(-1,(i/2));
            sm += parte;
        }
    }

    return sm*4;

}

float pi ()
{

    int i;
    float sm = 0, parte = 10;

    for(i = 1; fabs(parte) > pow(10, -8); i++)
    {
        if (i%2 != 0)
        {
            parte = 1/(float)i*pow(-1,(i/2));
            sm += parte;
        }
    }
    return sm*4;

}

float smedia()
{

    int sm = 0, i, in;

    for(i = 0; in > -1; i++)
    {
        printf("insira um numero para a media(negativo sai):\n");
        scanf("%d", &in);

        if(in >= 0) sm += in;

    }
    return (sm/i);


}

int bi6(int ano)
{

    return ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0) ? 1 : 0;

}

int primo(int in)
{


    int i, indi = 1;

    for(i = 2; i <= in/2; i++)
        if (in % i == 0)
        {
            indi = 0;
            break;
        }

    return indi;

}

double fib(int n)
{

    if (n > 0)

        if (n <= 1)
            return 1;

        else
            return fib(n-1) + fib(n-2);

    else
        return 0;
}

void printMICab(int m[],int l, int c)
{

    int i, j;

    printf("     ");
    for(j = 0; j < c; j++)
        printf("%-5d", j+1);
    printf("\n");

    for(i = 0; i < l; i++)
    {
        printf("%-5d", i+1);

        for(j = 0; j < c; j++)
            printf("%-5d", m[i * c + j]);

        printf("\n");
    }
}
int senha(int senha)
{
    int a;
    printf("Senha:");
    scanf("%d", &a);
    if(a == senha) return 1;
    system("clear");
    printf("Senha incorreta.\n");
    return 0;
}

/*

    VETORES

*/

void printVeti(int v[], int tam)
{

    int i;
    for(i = 0; i < tam; i++)
        printf("%-5d", v[i]);

}

void inputVeti(int v[],int tam)
{

    int i;
    for(i = 0; i < tam; i++)
        scanf("%d", &v[i]);

}

int * allocVeti(int tam)
{
    return malloc(tam*sizeof(int));
}

void randVet(int v[], int tam, int lim)
{
    int i;

    srand(time(NULL));

    for(i = 0; i < tam; i++)
        v[i] = rand()%lim;
}

/*

    MATRIZES

*/


void printMITabVoo(int m[],int l, int c)
{

    int i, j;

    printf(" ___________________________\n");
    printf("|      Tabela de Voos       |\n");
    printf("|___________________________|\n");
    printf("|  |          PARA          |\n");
    printf("|  |------------------------|\n");

    for(i = 0; i < l; i++)
    {
        if (i == 2)
            printf("|D |");
        else if (i == 3)
            printf("|E |");
        else
            printf("|  |");

        for(j = 0; j < c; j++)
            if (i == 0 || j == 0)
                printf("%-4d", m[i * c + j]);
            else if(m[i * c + j] == 1)
                printf("X   ");
            else
                printf("-   ");

        if(i != 5)
        {
            printf("|\n");
            printf("|  |                        |");
            printf("\n");
        }
    }
    printf("|\n|__|________________________|\n");
}
void printMI(int m[],int l, int c)
{

    int i, j;


    for(i = 0; i < l; i++)
    {
        for(j = 0; j < c; j++)
            printf("%-5d", m[i * c + j]);

        printf("\n");
    }

}
void multiMatriz(int a[], int b[], int c[], int m, int n, int p)
{

    int i, j, k;

    for(i = 0; i < m; i++)
        for(j = 0; j < p; j++)
            c[i * p + j] = 0;

    for(i = 0; i < m; i++)
        for(j = 0; j < p; j++)
            for(k = 0; k < n; k++)
                c[i * p + j] += a[i * n + k]*b[k * p + j];

}
void potMatriz(int entrada[], int saida[], int lado, int grau)
{

    int i, temp[lado][lado];

    if (grau == 1)
    {
        copyMatriz(entrada,saida,lado,lado);
        return;
    }

    copyMatriz(entrada,temp,lado,lado);

    for (i = 1; i < grau; i++)
    {
        multiMatriz(entrada, temp, saida, lado, lado, lado);
        copyMatriz(saida,temp,lado,lado);
    }

}
void randMatriz(int matriz[], int l, int c, int lim)
{
    int i, j;

    srand(time(NULL));

    for(i = 0; i < l; i++)
        for(j = 0; j < c; j++)
            matriz[i*c + j] = rand()%lim;
}
/*void invertMtatriz(float a[], int m)
{



}
*/
void floatxMatriz(float a[], float x, int m, int n)
{

    int i,k;

    for (i = 0; i < m; i++)
        for (k = 0; k < n; k++)
            a[i*n + k] *= x;

}
/*
float detMatriz(float a[], int m)
{



}
*/
void copyMatriz(int mat[], int mat1[], int i, int j)
{
    int k, l;

    for (k = 0; k < i; k++)
        for (l = 0; l < j; l++)
            mat1[k*j + l] = mat[k*j + l];
}
void transpMatriz(float a[], int m)
{

    int i,k;
    float temp;

    for(i = 0; i < m; i++)
        for(k = 0; k < i; k++)
        {
            temp = a[k*m + i];
            a[k*m + i] = a[i*i + k];
            a[i*i + k] = temp;
        }
}



void smMatriz(float a[], float b[],int m,int n)
{
    int i,k;

    for (i = 0; i < m; i++)
        for (k = 0; k < n; k++)
            a[i*n + k] += b[i*n + k];

}

int ** allocMatriz(int l, int c)
{
    int **m, i;

    m = malloc(l*sizeof(int*));

    for(i = 0; i < l; i++)
        m[i] = allocVeti(c);

    return m;
}


