#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice13.txt"
#define SEARCHED_CHAR 5

int main( void )
{
	int numChar = 0;
	FILE* file = NULL;
	int c = EOF;

	file = fopen( FILENAME, "r" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s.\n", FILENAME );

		return EXIT_FAILURE;
	}

	while ( numChar < SEARCHED_CHAR )
	{
		c = fgetc( file );
		if ( c == EOF )
		{
			printf( "Le fichier contient moins de %d caractères\n", SEARCHED_CHAR );
			fclose( file );
			return EXIT_FAILURE;
		}
		++numChar;
	}

	printf( "Le caractère #%d est: %c", SEARCHED_CHAR, (char)c );

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
