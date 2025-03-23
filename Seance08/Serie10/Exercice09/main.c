#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice09.txt"
#define NUM_INT 5

int main( void )
{
	FILE* file = NULL;
	int T[NUM_INT];
	int i;

	file = fopen( FILENAME, "r" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	for ( i = 0; i < NUM_INT; ++i )
	{
		if ( fscanf( file, "%d", &T[i] ) != 1 )
		{
			printf( "Erreur de lecture\n" );
			fclose( file );
			return EXIT_FAILURE;
		}
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	for ( i = 0; i < NUM_INT; ++i )
	{
		printf( "Entier #%d: %d\n", i, T[i] );
	}

	return EXIT_SUCCESS;
}
