#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Exercice07.txt"

int main( void )
{
	FILE* file = NULL;
	int nbReels;
	int i;

	printf( "Saisir le nombre de réels voulus: " );
	if ( scanf( "%d", &nbReels ) != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	file = fopen( FILENAME, "w" );
	if ( !file )
	{
		printf( "Impossible de créer le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	for ( i = 0; i < nbReels; ++i )
	{
		double r;

		printf( "Saisir un réel: " );
		if ( scanf( "%lf", &r ) != 1 )
		{
			printf( "Erreur de saisie\n" );
			fclose( file );
			return EXIT_FAILURE;
		}

		fprintf( file, "%f ", r );
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
