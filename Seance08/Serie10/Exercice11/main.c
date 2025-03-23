#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define FILENAME "Exercice11.txt"

int main( void )
{
	FILE* file = NULL;
	char s[BUFFER_SIZE];

	printf( "Saisir une phrase: " );
	if ( fgets( s, BUFFER_SIZE, stdin ) == NULL )
	{
		printf( "Erreur de lecture\n" );
		return EXIT_FAILURE;
	}

	file = fopen( FILENAME, "w" );
	if ( file == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	if ( fprintf( file, "%s", s ) < 0 )
	{
		printf( "Erreur lors de l'écriture dans le fichier\n" );
		fclose( file );
		return EXIT_FAILURE;
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	printf( "Phrase enregistrée avec succès dans %s\n", FILENAME );

	return EXIT_SUCCESS;
}
