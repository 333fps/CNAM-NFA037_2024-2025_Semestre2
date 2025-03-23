#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice11bis.txt"

int main( void )
{
	FILE* file = NULL;
	int c;

	file = fopen( FILENAME, "w" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	printf( "Saisissez une phrase: " );
	while ( ( c = getchar() ) != '\n' && c != EOF )
	{
		if ( fputc( c, file ) == EOF )
		{
			printf( "Erreur lors de l'écriture dans le fichier\n" );
			fclose( file );
			return EXIT_FAILURE;
		}
	}
	puts( "" );

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	printf( "Phrase enregistrée avec succès dans %s\n", FILENAME );
	return EXIT_SUCCESS;
}
