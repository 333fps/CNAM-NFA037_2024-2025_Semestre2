#include <stdio.h>
#include <string.h>

#define FILENAME "Exercice13.txt"

int main( void )
{
	int numChar = 0;
	FILE* file = NULL;
	int c = EOF;

	file = fopen( FILENAME, "r" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s.\n", FILENAME );

		return 1;
	}

	while ( !feof( file ) && numChar < 5 )
	{
		c = fgetc( file );
		++numChar;
	}
	printf( "Le cinquième caractère est %c", (char)c );

	fclose( file );

	return 0;
}
