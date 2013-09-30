#include <stdio.h>
#include <stdlib.h>

//\
Labirinto\
Programa feito por João Miranda\
\
Este programa gera um labirinto pre-definido de tamanho recebido pelo usuario, recebe do usuario\
a localizacao do rato(origem) e do queijo(destino) e demonstra na tela o caminho mais curto entre\
os dois.

/*observaçoes:

na matriz de inicializacao(antes de processar os custos),

rato = tamanho da matriz(sem as bordas) ao quaadrado(tam*tam)
queijo = 0
paredes = -1
fundo = tamanho da matriz(sem as bordas) ao quadrado menos 1 ((tam*tam)-1)

*/

/*indice de funcoes*/
void inicializaLabirinto( int **m, int tam );
void criaMatrizCusto( int **m, int tam );
void calculaCaminho ( int **m, int tam, int **indicesLinha, int **indicesColuna, int *passos );
void criaCaminho( int *indicesLinha, int *indicesColuna, int passos, int tamLabirinto, int **m );
void mostraCaminho( char **caminho, int tam );
int ** alocaMatriz ( int nlinhas, int ncolunas );
void  printLabi( int **m, int tam );
char ** alocaMatrizChar ( int nlinhas, int ncolunas );
void printFinal();

/*execução*/
main()
{
	int tam=1, xr=0, yr=0, xq=0, yq=0, *indicesLinha, *indicesColuna, passos = 1, **m;//tam do labirinto; pos x do rato; pos y do rato; pos x do queijo; pos y do queijo; vetor de posicoes x por onde o rato passa para chegar no queijo; vetor de posicoes y do trajeto; o numero de passos



	system( "clear" );

     while(tam<6)//exige tamanhos aiores que 6, minimo pela configuracao do labirinto pré-definido
          {
          printf( "Qual o tamanho do labirinto?(min 6)" );
          fflush(stdout);
          scanf( "%d", &tam );//recebe do usuario o tamanho do labirinto
          }

	m = alocaMatriz( tam + 2, tam + 2 ); //aloca a matriz do tamanho que o usuari quer + as bordas

	inicializaLabirinto( m, tam );// Inicializa o labirinto com o tamanho que o usuario pediu e as paredes pre definidas diamicamente

	printLabi( m, tam );// imprime o labirinto para facilitar para o usuario

	printf( "Aonde está o rato? \"y,x\"\n" );
	scanf( "%d,%d", &xr, &yr );// recebe a localizacao do rato em linhas x colunas

	m[xr][yr] = tam * tam; // armazezna essa localização direto na tabela m

	system("clear");

     printLabi( m, tam );// atualiza a tabela com a posição do rato

	printf( "Aonde está o queijo? \"y,x\"\n" );
	scanf( "%d,%d", &xq, &yq );// recebe a localizacao do queijo em linhas x colunas

	m[xq][yq] = 0;// armazena na tabela como o rato

	criaMatrizCusto( m, tam );// Escreve na matriz os valores de distancia entre o queijo e todas as posiçoes do labirinto

	calculaCaminho( m, tam, &indicesLinha, &indicesColuna, &passos );//Escreve as coordenadas x,y do trajeto percorrido entre o rato e o queijo nos vetores indicesLinha e indicesColuna respectivamente

	criaCaminho( indicesLinha, indicesColuna, passos, tam, m );// Através da matriz original, com as informacoes de parede, rato, queijo, e trajeto percorrido, cria a matriz de caracteres


}
void inicializaLabirinto( int **m, int tam ) // Inicializa o Labirinto com o tamanho definido pelo usuario e as paredes seguindo o modelo pré definido
{
	int i, j;
	for ( i = 1; i < tam + 2; i++ )
		for ( j = 1; j < tam + 2; j++ )// sempre considerando bordas
			m[i][j] = ( ( tam * tam ) - 1 ); // completa a matriz com tam ^2, pois esse valor nunca será atingido pelo caminho do rato na matriz custo

	for ( i = 0; i < tam + 2; i++ )
		for ( j = 0; j < tam + 2; j++ )// colocar paredes no labirinto
		{
			if ( j == 0 || i == 0 || j == tam + 1 || i == tam + 1 )//paredes externas
				m[i][j] = -1;
			else if ( j == tam / 2 && i < tam ) //coluna central com 1 espaco para passar
				m[i][j] = -1;
			else if ( j == tam / 4 && i > 2 ) // coluna 1/4 com dois espacos para passar
				m[i][j] = -1;
			else if ( j > ( tam / 2 ) && j < tam && i == tam / 2 ) // linha central depois da coluna central com 1 espaco para passar
				m[i][j] = -1;
		}


}
void criaMatrizCusto( int **m, int tam ) // Escreve na matriz os valores de distancia entre o queijo e todas as posiçoes do labirinto
{

	int i, j, x = 0, y, ok = 1;// contador;contador;coordenada x do queijo;coordenaday do queijo; verificador

	for ( i = 1; i < tam + 1 && x == 0; i++ )// procura pelas coordenadas x e y do queijo
		for ( j = 1; j < tam + 1; j++ ) {
			if ( m[i][j] == 0 )
			{
				x = i - 1;//posição exatamente antes do queijo
				y = j - 1;
				if ( i == 1 )//correcao de erro que impedia o calculo funcionar nas primeiras coordenadas
					x = 1;
				if ( j == 1 )
					y = 1;
				break;
			}
		}


	do// crescimento do calculo de distancias
	{
		if ( y == 1 && x == 1 )//quando chegar na primeira posição, executa uma ultima vez
			ok = 0;



		for ( i = x; i < tam + 1; i++ ) {// inicia logo antes do queijo
			if ( m[1][i] == ( ( tam * tam ) - 1 ) ) {//exige que toda a primeira linha esteja preenchida antes de parar de executar
				ok = 1;
			}
			for ( j = y; j < tam + 1; j++ ) {
				if ( m[i][j] < ( ( tam * tam ) - 1 ) && m[i][j] > -1 ) // quando for menor que o rato e maior que a parede
				{
					if ( m[i - 1][j] == ( ( tam * tam ) - 1 ) )// nestes passos verifica se ao redor do termo verificado é fundo
					{
						m[i - 1][j] = m[i][j] + 1;// aqui ele adiciona 1 numero a mais que o anterior, comecando por 0, onde é o rato
						if ( i - 2 < x )//estes ifs verificam  se o ultimo item verificado é antes da variavel x ou y, que é o limite para cima e para a esquerda, que faz economizar processamento, pois só verifica aonde existe de fato o que verificar
							x = i - 1;
					}

					if ( m[i + 1][j] == ( ( tam * tam ) - 1 ) )
						m[i + 1][j] = m[i][j] + 1;

					if ( m[i][j - 1] == ( ( tam * tam ) - 1 ) )
					{
						m[i][j - 1] = m[i][j] + 1;
						if ( j - 2 < y )
							y = j - 1;
					}

					if ( m[i][j + 1] == ( ( tam * tam ) - 1 ) )
						m[i][j + 1] = m[i][j] + 1;
				}
			}
		}
	}
	while ( ok );

}
void calculaCaminho ( int **m, int tam, int **indicesLinha, int **indicesColuna, int *passos ) //Escreve as coordenadas x,y do trajeto percorrido entre o rato e o queijo nos vetores indicesLinha e indicesColuna respectivamente
{
	int i = 1, j = 1, pi, pj, min = ( ( tam * tam ) - 1 );

	*indicesLinha = ( int* ) malloc( 3 * sizeof( int ) );// aloca um tamanho minimo para esses vetores
	*indicesColuna = ( int* ) malloc( 3 * sizeof( int ) );

	for ( pi = 1; pi < tam + 2; pi++ )
		for ( pj = 1; pj < tam + 2; pj++ )
			if ( m[pi][pj] == tam * tam )// encontra o  rato
			{
				i = ( *indicesLinha )[0] = pi;
				j = ( *indicesColuna )[0] = pj;
			}



	while ( 1 )
	{

		if ( m[i + 1][j] == 0 || m[i - 1][j] == 0 || m[i][j + 1] == 0 || m[i][j - 1] == 0 )// quando encontrar o queijo sai do loop
		{
			*passos += 1;
			break;
		}

		if ( m[i + 1][j] < min && m[i + 1][j] > -1 )//nestes ifs procura o menor item ao redor do item atual
		{
			min = m[i + 1][j];// caso ache o item, armazena no minimo para comparar com os outros
			( *indicesLinha )[*passos] = i + 1;
			( *indicesColuna )[*passos] = j;
		}

		if ( m[i - 1][j] < min && m[i - 1][j] > -1 )
		{
			min = m[i - 1][j];
			( *indicesLinha )[*passos] = i - 1;
			( *indicesColuna )[*passos] = j;
		}

		if ( m[i][j + 1] < min &&  m[i][j + 1] > -1 )
		{
			min = m[i][j + 1];
			( *indicesLinha )[*passos] = i;
			( *indicesColuna )[*passos] = j + 1;
		}

		if ( m[i][j - 1] < min && m[i][j - 1] > -1 )
		{
			min = m[i][j - 1];
			( *indicesLinha )[*passos] = i;
			( *indicesColuna )[*passos] = j - 1;
		}
		i = ( *indicesLinha )[*passos];// transforma o menor item encontrado no item a ser avaliado
		j = ( *indicesColuna )[*passos];

		( *indicesLinha ) = ( int* )realloc( ( *indicesLinha ), ( ( *passos ) + 2 ) * sizeof( int ) );//realoca o vetor para caber mais coordenadas
		( *indicesColuna ) = ( int* )realloc( ( *indicesColuna ), ( ( *passos ) + 2 ) * sizeof( int ) );

		*passos += 1;
	}

}
void criaCaminho( int *indicesLinha, int *indicesColuna, int passos, int tamLabirinto, int **m ) // Através da matriz original, com as informacoes de parede, rato, queijo e trajeto percorrido, cria a matriz de caracteres
{
	char **caminho;
	int i, j, l, c;

	caminho = alocaMatrizChar( tamLabirinto + 2, tamLabirinto + 2 );// aloca a matriz de chars

	for ( i = 0; i < tamLabirinto + 2; i++ )
		for ( j = 0; j < tamLabirinto + 2; j++ )
		{
			if ( m[i][j] == -1 )
				caminho[i][j] = 'X';//caso parede

			else if ( m[i][j] == 0 )
				caminho[i][j] = 'Q';//caso queijo

			else if ( m[i][j] == tamLabirinto * tamLabirinto )
				caminho[i][j] = 'R';// caso rato

			else
				caminho[i][j] = ' ';// no resto
		}

	for ( i = 1; i < passos - 1; i++ )// demonstra o caminho sendo escrito
	{
		caminho[indicesLinha[i]][indicesColuna[i]] = '+';
          system( "clear" );
		mostraCaminho( caminho, tamLabirinto + 2 );
		usleep( 8000 );
	}


	for ( i = 1; i < passos - 1; i++ )// leva o rato até o queijo
	{
          system( "clear" );
		mostraCaminho( caminho, tamLabirinto + 2 );
		caminho[indicesLinha[i]][indicesColuna[i]] = 'R';
		caminho[indicesLinha[i - 1]][indicesColuna[i - 1]] = '-';
		usleep( 80000 );
	}

     printFinal();
     printf("trajeto realizado em %d passos:\n", passos-1);
	mostraCaminho( caminho, tamLabirinto + 2 );// finaliza


}
void mostraCaminho( char **caminho, int tam ) // Imprime o tabuleiro de caracteres com as indicaçoes de parede (X), Rato (R), Queijo (Q), e trajeto (+)(-)
{

	int i, j;

	for ( i = 0; i < tam; i++ )
	{
		for ( j = 0; j < tam; j++ )
			printf( "%-3c", caminho[i][j] );

		printf( "\n" );
	}
	fflush( stdout );

}
int ** alocaMatriz ( int nlinhas, int ncolunas ) //Função para alocar a matriz de inteiros
{
	int **m, i;

	m = ( int** ) malloc( nlinhas * sizeof( int* ) );

	for ( i = 0; i < nlinhas; i++ )
		m[i] = ( int* ) malloc( ncolunas * sizeof( int ) );

	return m;
}
char ** alocaMatrizChar ( int nlinhas, int ncolunas ) //Função para alocar a matriz de chars
{
	char **m;
	int i;

	m = ( char** ) malloc( nlinhas * sizeof( char* ) );

	for ( i = 0; i < nlinhas; i++ )
		m[i] = ( char* ) malloc( ncolunas * sizeof( char ) );

	return m;
}
void  printLabi( int **m, int tam )//Imprime a matriz  de inteiros como um sistema de caracteres com as indicaçoes de parede (X) e Rato (R)
{

	int i, j;

	printf( "   " );
	for ( j = 0; j < tam + 2; j++ )
		printf( "%-3d", j );
	printf( "\n" );

	for ( i = 0; i < tam + 2; i++ )
	{
		printf( "%-3d", i );

		for ( j = 0; j < tam + 2; j++ )
		{
			if ( m[i][j] == -1 )
			{
				printf( "%-3c", 'X' );
			}
			else if ( m[i][j] == ( ( tam * tam ) - 1 ) )
			{
				printf( "%-3c", ' ' );
			}
			else if ( m[i][j] == ( tam * tam ))
			{
				printf( "%-3c", 'R' );
			}
			else
				printf( "%-3d", m[i][j] );

		}

		printf( "\n" );
	}
}

void printFinal(){

     system( "clear" );
     printf("         _--\"-.                                                    \n");
     printf("      .-\"      \"-.                                                 \n");
     printf("     |\"\"--..      '-.                                               \n");
     printf("     |      \"\"--..   '-.                                             \n");
     printf("     |.-. .-\".    \"\"--..\".          ,     .                         \n");
     printf("     |'./  -_'  .-.      |          (\\,;,/)                             \n");
     printf("     |      .-. '.-'   .-'           (o o)\\//,                           \n");
     printf("     '--..  '.'    .-  -.             \\ /     \\,                         \n");
     printf("          \"\"--..   '_'   :            `+'(  (   \\    )                   \n");
     printf("                \"\"--..   |               //  \\   |_./                     \n");
     printf("                      \"\"-'              '~' '~----'                         \n");
}
