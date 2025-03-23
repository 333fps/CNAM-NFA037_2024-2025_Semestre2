#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Exercice02.txt"
#define MAX_WORD 30

int main( void )
{
	char word[MAX_WORD] = { 0 };
	FILE* file = NULL;

	printf( "Saisir un mot: " );

	if ( scanf( "%29s", word ) != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	file = fopen( FILENAME, "a" );
	if ( !file )
	{
		printf( "Impossible de créer le fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	if ( fputs( word, file ) == EOF )
	{
		printf( "Erreur lors de l'écriture dans le fichier %s\n", FILENAME );
		fclose( file );
		return EXIT_FAILURE;
	}

	if ( fputc( '\n', file ) == EOF )
	{
		printf( "Erreur lors de l'écriture du saut de ligne\n" );
		fclose( file );
		return EXIT_FAILURE;
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	printf( "Mot \"%s\" écrit dans le fichier %s\n", word, FILENAME );

	return EXIT_SUCCESS;
}
