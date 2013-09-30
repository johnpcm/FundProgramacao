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

/*MATRIZES*/

void printmi(int m[],int l, int c);//IMPRIME A MATRIZ

void multiMatriz(float a[], float b[], float c[], int m, int n, int p);//MULTIPLICA AS DUAS MATRIZES A E B, RETORNANDO NA MATRIZ C, USANDO AS DIMENSOES MxN PARA A E NxP PARA B

void invertMtatriz(float a[],int m);//INVERTE A MATRIZ QUADRADA DE DIMENSOES MxM

void floatxMatriz(float a[], float x, int m, int n);//MULTIPLICA A MATRIZ MxN PELO NUMERO X

float detMatriz(float a[], int m);//CALCULA O DETERMINANTE DA MATRIZ MxM

void transpMatriz(float a[], int m);//CALCULA A TRANSPOSTA DA MATRIZ MxM

void smMatriz(float a[], float b[], int m, int n);//SOMA DUAS MATRIZES aplicando em A

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
void printmi(int m[],int l, int c){

    int i, j;

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++)
            printf("%5d ", m[i * c + j]);
        printf("\n");
    }

}
/*void multiMatriz(float a[],float b[], int m, int n, int p)
{



}

void invertMtatriz(float a[], int m)
{



}

void floatxMatriz(float a[], float x, int m, int n)
{

    int i,k;

    for (i = 0; i < m; i++)
        for (k = 0; k < n; k++)
            a[i][k] *= x;

}

float detMatriz(float a[], int m)
{



}

void transpMatriz(float a[], int m)
{

    int i,k;
    float temp;

    for(i = 0; i < m; i++)
        for(k = 0; k < i; k++)
        {
            temp = a[k][i];
            a[k][i] = a[i][k];
            a[i][k] = temp;
        }
}


}

void smMatriz(float a[], float b[],int m,int n)
{
    int i,k;

    for (i = 0; i < m; i++)
        for (k = 0; k < n; k++)
            a[i][k] += b[i][k];

}
*/
