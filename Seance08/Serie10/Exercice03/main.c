#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Exercice03.txt"

int main( void )
{
	FILE* file = NULL;

	file = fopen( FILENAME, "w" );
	if ( !file )
	{
		printf( "Impossible de créer le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	fputc( '1', file );
	fputs( "\n", file );
	fputc( '2', file );

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
