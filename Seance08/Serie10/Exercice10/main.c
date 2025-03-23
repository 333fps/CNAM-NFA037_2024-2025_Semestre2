#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice10.txt"

int main( void )
{
	FILE* file = NULL;
	int c;

	file = fopen( FILENAME, "r" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	printf( "%s", "\nVoici le texte du fichier:\n" );
	while ( ( c = fgetc( file ) ) != EOF )
	{
		printf( "%c", c );
	}
	puts( "\n" );

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
