#include <stdio.h>
#include <stdlib.h>

int ** alocaMatriz ( int nlinhas, int ncolunas );
void desalocaMatriz( int ** matriz, int nlinhas );
int ** leImagem( char *entrada, int *nlinhas, int *ncolunas, int *maxCinza );
void gravaImagem( char *nomeArquivo, int **matriz, int nlinhas, int ncolunas, int maxCinza );
void varreduraForward( int **in, int **out, int ncolunas, int nlinhas ,int prim);
void varreduraBackward( int **in, int **out, int ncolunas, int nlinhas ,int prim);
int atribuiRotulos( int **in, int **out, int ncolunas, int nlinhas );


int main ( int argc, char *argv[] ) {


	if ( argc < 3 ) {
		printf( "Uso: %s imagem_de_entrada.pgm imagem_de_saida.pgm", argv[0] );
		exit( 1 );
	}

	int i,j,**in, **out, lableMax, nlinhas, ncolunas;

	in = leImagem( argv[1], &nlinhas, &ncolunas, &lableMax );
	out = alocaMatriz ( nlinhas, ncolunas );

	for (i = 0; i < nlinhas; i++)
	     for (j = 0; j < ncolunas; j++)
               {

                    if(in[i][j]==0)
                         in[i][j] = 256;
                    else
                         in[i][j] = 0;

                    out[i][j] = in[i][j];

               }

	lableMax = atribuiRotulos( in, out, ncolunas, nlinhas );

	gravaImagem( argv[2], out, nlinhas, ncolunas, lableMax );

	desalocaMatriz( out, nlinhas );
	desalocaMatriz( in, nlinhas );
}

int ** alocaMatriz ( int nlinhas, int ncolunas ) {
	int **m, i;

	m = ( int** ) malloc( nlinhas * sizeof( int* ) );

	for ( i = 0; i < nlinhas; i++ )
		m[i] = ( int* ) malloc( ncolunas * sizeof( int ) );

	return m;
}

void desalocaMatriz( int ** matriz, int nlinhas ) {
	int i;

	for ( i = 0; i < nlinhas; i++ )
		free( matriz[i] );

	free( matriz );
}

int ** leImagem( char *entrada, int *nlinhas, int *ncolunas, int *maxCinza ) {
	char type[3], c;
	int **matriz;

	//Abertura do arquivo que contem a imagem de entrada*/
	FILE *arq_imagem_entrada = fopen( entrada, "r" );

	//Leitura o cabecalho da imagem
	//tipo da imagem pgm: P2 ou P5
	fgets( type, 4, arq_imagem_entrada );
	//é preciso ignorar o comentário
	c = fgetc ( arq_imagem_entrada );
	if ( c == '#' ) {
		while ( ( c != '\n' ) && ( c != EOF ) ) {
			c = fgetc ( arq_imagem_entrada );
		}
	}

	//leitura das informações de interesse
	fscanf( arq_imagem_entrada, "%d %d %d", ncolunas, nlinhas, maxCinza );

	//alocacao dinamica de memoria para a matriz que  armazena a imagem
	matriz = alocaMatriz ( *nlinhas, *ncolunas );

	//leitura da imagem na matriz
	int i, j;
	for ( i = 0; i < *nlinhas; i++ ) {
		for ( j = 0; j < *ncolunas; j++ ) {
			fscanf( arq_imagem_entrada, "%d", &matriz[i][j] );
		}
	}

	//"fecha" a referência para arquivo que armazena imagem de entrada
	fclose( arq_imagem_entrada );

	return matriz;
}

void gravaImagem( char *saida, int **matriz, int nlinhas, int ncolunas, int maxCinza ) {
	//Abertura do arquivo que armazena a imagem de saída
	FILE *arq_imagem_saida = fopen( saida, "w" );
	int i, j;

	//Escrita da saída
	fprintf( arq_imagem_saida, "P2\n%d %d\n%d\n", ncolunas, nlinhas, maxCinza );
	for ( i = 0; i < nlinhas; i++ ) {
		for ( j = 0; j < ncolunas; j++ ) {
			fprintf( arq_imagem_saida, "%d ", matriz[i][j] ); /*escrevendo o valor do pixel no arquivo*/
			if ( ( j != 0 ) && ( j % 12 ) == 0 ) /*adicionando quebras a cada 12 linhas no arquivo*/
				fprintf( arq_imagem_saida, "\n" );
		}
	}
	//Fecha o arquivo
	fclose( arq_imagem_saida );
}

void varreduraForward( int **in, int **out, int ncolunas, int nlinhas ,int prim) //atribui ŕotulos fazendo a varredura forward scan na imagem representada pela matriz in. O resultado  ́e armazenado em out
{

	int i, j, label = 1;

	for ( i = 1; i < nlinhas; i++ )
		for ( j = 1; j < ncolunas-1; j++ )
		{
			if ( in[i][j] != 0 ) {
                         if ( in[i][j - 1] == 0 && in[i-1][j-1] == 0 && in[i-1][j] == 0 && in[i-1][j+1] == 0  && prim == 0)
                         {
                              out[i][j] = label;
                              label++;
                         }
                         else{

					if ( in[i][j - 1] != 0 && in[i][j - 1] < out[i][j] )
					{
						out[i][j] = in[i][j - 1];
					}
					if ( in[i - 1][j - 1] != 0 && in[i - 1][j - 1] < out[i][j] )
					{
						out[i][j] = in[i - 1][j - 1];
					}
					if ( in[i - 1][j] != 0 && in[i - 1][j] < out[i][j] )
					{
						out[i][j] = in[i - 1][j];
					}
					if ( in[i - 1][j + 1] != 0 && in[i - 1][j + 1] < out[i][j] )
					{
						out[i][j] = in[i - 1][j + 1];
					}
                         }
			}
			else
				out[i][j] = in[i][j];
		}
}

void varreduraBackward( int **in, int **out, int ncolunas, int nlinhas ,int prim) //atribui ŕotulos fazendo a varredura backward scan na imagem representada pela matriz in. O resultado  ́e armazenado em out
{

	int i, j, label = 1;

	for ( i = nlinhas - 2; i >= 0; i-- )
		for ( j = ncolunas - 1; j >= 1 ; j-- )
		{
			if ( in[i][j] != 0 ) {
                         if ( in[i][j + 1] == 0 && in[i + 1][j - 1] == 0 && in[i + 1][j] == 0 && in[i + 1][j + 1] == 0 && prim == 0)
                         {
                              out[i][j] = label;
                              label++;
                         }
                         else{

					if ( in[i][j + 1] != 0 && in[i][j + 1] < out[i][j] )
					{
						out[i][j] = in[i][j + 1];
					}
					if ( in[i + 1][j - 1] != 0 && in[i + 1][j - 1] < out[i][j] )
					{
						out[i][j] = in[i + 1][j - 1];
					}
					if ( in[i + 1][j] != 0 && in[i + 1][j] < out[i][j] )
					{
						out[i][j] = in[i + 1][j];
					}
					if ( in[i + 1][j + 1] != 0 && in[i + 1][j + 1] < out[i][j] )
					{
						out[i][j] = in[i + 1][j + 1];
					}
                         }
			}
			else
				out[i][j] = in[i][j];
		}
}
int atribuiRotulos( int **in, int **out, int ncolunas, int nlinhas ) //usando as fun ̧c ̃oes apropri- adas, rotula os componentes conexos da imagem representada pela matriz in, armazenando o resultado em out. Al ́em disso, retorna o maior r ́otulo atribu ́ıdo
{

	int i, j, ok = 0,label = 1;

	varreduraForward(in, out, ncolunas, nlinhas, 0);

	while ( !ok ) {
		ok = 1;

          for(i = 0; i < nlinhas; i++)
            for(j = 0; j < ncolunas; j++)
                in[i][j] = out[i][j];

		varreduraBackward(in, out, ncolunas, nlinhas ,1);

          for(i = 0; i < nlinhas; i++)
            for(j = 0; j < ncolunas; j++)
                in[i][j] = out[i][j];

		varreduraForward( in, out, ncolunas, nlinhas ,1);

          for ( i = 1; i < nlinhas-1; i++ )
			for ( j = 1; j < ncolunas-1; j++ )
			{
				if ( in[i][j] != out[i][j] )
					ok = 0;
                    if (out[i][j] > label && out[i][j] != 256)
                         label = out[i][j];
			}
	}

	return label;

}

void  printLabi( int **m, int **m2, int l, int c)//Imprime a matriz  de inteiros como um sistema de caracteres com as indicaçoes de parede (X) e Rato (R)
{
    int i, j;

     system("clear");
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < c; j++)
            printf("%-4d", m[i][j]);
          printf("   ");
     for(j = 0; j < c; j++)
            printf("%-4d", m2[i][j]);

        printf("\n");
    }
}
