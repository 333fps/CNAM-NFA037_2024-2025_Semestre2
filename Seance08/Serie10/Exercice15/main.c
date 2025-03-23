#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Exercice15.txt"
#define MAX_LENGTH 100

int main( void )
{
	FILE* file = NULL;
	int numLines = 0;
	char buffer[MAX_LENGTH];

	file = fopen( FILENAME, "r" );
	if ( file == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s.\n", FILENAME );
		return EXIT_FAILURE;
	}

	while ( fgets( buffer, MAX_LENGTH, file ) != NULL )
	{
		if ( strcmp( buffer, "\n" ) != 0 )
		{
			++numLines;
		}
	}

	printf( "Le fichier contient %d nombres.\n", numLines );

	{
		int num;
		int err;
		int i = 0;

		printf( "Quel nombre voulez-vous afficher ? " );
		err = scanf( "%d", &num );
		if ( err != 1 || num < 1 || num > numLines )
		{
			printf( "Numéro invalide\n" );
			fclose( file );
			return EXIT_FAILURE;
		}

		rewind( file );

		while ( fgets( buffer, MAX_LENGTH, file ) != NULL )
		{
			if ( strcmp( buffer, "\n" ) != 0 )
			{
				++i;
				if ( i == num )
				{
					break;
				}
			}
		}

		if ( strlen( buffer ) > 0 && buffer[strlen( buffer ) - 1] == '\n' )
			buffer[strlen( buffer ) - 1] = '\0';

		printf( "Le nombre est: %s\n", buffer );
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
