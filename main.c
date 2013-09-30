#include <joao.h>

#define TAM 100


main(){



}
void printl(char *log)
{

    char nomelog[] = "log.txt"
	FILE *plog = fopen( nomelog, "w" );
	int i, j;

	fprintf( plog,"%s" ,log );
	fprintf( plog, "\n" );

	fclose( plog );

}
