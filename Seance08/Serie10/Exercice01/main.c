#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice01.txt"

int main( void )
{
	char c;
	FILE* file = NULL;

	printf( "Saisissez un caractère au clavier: " );

	if ( scanf( "%c", &c ) != 1 )
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

	if ( fputc( c, file ) == EOF )
	{
		printf( "Erreur lors de l'écriture dans le fichier %s\n", FILENAME );
		fclose( file );
		return EXIT_FAILURE;
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	printf( "Le caractère '%c' a été écrit dans le fichier.\n", c );

	return EXIT_SUCCESS;
}
