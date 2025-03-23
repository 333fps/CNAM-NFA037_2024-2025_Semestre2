#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Exercice06.txt"
#define NUM_INT 6

double average( int* tab );

int main( void )
{
	FILE* file = NULL;
	int T[NUM_INT];
	int i;

	for ( i = 0; i < NUM_INT; ++i )
	{
		printf( "Saisir un entier: " );

		if ( scanf( "%d", &T[i] ) != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}
	}

	file = fopen( FILENAME, "w" );
	if ( !file )
	{
		printf( "Impossible de créer le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	for ( i = 0; i < NUM_INT; ++i )
	{
		fprintf( file, "%d\n", T[i] );
	}
	fprintf( file, "%f\n", average( T ) );

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

double average( int* tab )
{
	int i;
	double sum = 0;
	for ( i = 0; i < NUM_INT; ++i )
	{
		sum += (double)tab[i];
	}

	return sum / (double)NUM_INT;
}
