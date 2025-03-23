#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice12.txt"

int main( void )
{
	FILE* file = NULL;
	int count = 0;
	int c;

	file = fopen( FILENAME, "r" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	while ( ( c = fgetc( file ) ) != '\n' && c != EOF )
	{
		++count;
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	printf( "La phrase contient %d caractères\n", count );

	return EXIT_SUCCESS;
}
