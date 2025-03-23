#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Exercice04.txt"

int main( void )
{
	FILE* file = NULL;
	int i;

	file = fopen( FILENAME, "a" );
	if ( !file )
	{
		printf( "Impossible de créer le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	for ( i = 0; i < 5; ++i )
	{
		int j = 0;
		printf( "Saisir un entier: " );

		if ( scanf( "%d", &j ) != 1 )
		{
			printf( "Erreur de saisie\n" );
			fclose( file );
			return EXIT_FAILURE;
		}

		fprintf( file, "%d ", j );
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
