#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Exercice08.txt"

int main( void )
{
	FILE* file = NULL;
	double reel;
	int i;

	file = fopen( FILENAME, "r" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	for ( i = 0; i < 3; ++i )
	{
		if ( fscanf( file, "%lf", &reel ) != 1 )
		{
			printf( "Erreur de lecture\n" );
			fclose( file );
			return EXIT_FAILURE;
		}

		printf( "Nombre #%d: %f\n", i, reel );
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
