#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Exercice18.txt"

int main( void )
{
	FILE* file;
	char word[30] = { 0 };
	char buffer[200];
	int numWord = 0;
	int c;
	long cursor = 0;

	printf( "Saisir un mot : " );
	if ( fgets( word, sizeof( word ), stdin ) != NULL )
	{
		size_t len = strlen( word );
		if ( len > 0 && word[len - 1] == '\n' )
			word[len - 1] = '\0';
	}

	file = fopen( FILENAME, "r+" );
	if ( file == NULL )
	{
		printf( "Ouverture du fichier impossible\n" );
		return EXIT_FAILURE;
	}

	while ( ( c = fgetc( file ) ) != EOF )
	{
		putchar( c );
		if ( c == ' ' )
		{
			numWord++;
			if ( numWord == 3 )
			{
				cursor = ftell( file );
				fgets( buffer, sizeof( buffer ), file );
				break;
			}
		}
	}

	fseek( file, cursor, SEEK_SET );
	fprintf( file, "%s %s", word, buffer );

	fclose( file );

	printf( "\nContenu mis à jour:\n" );
	file = fopen( FILENAME, "r" );
	if ( file == NULL )
	{
		printf( "Erreur: Impossible de rouvrir le fichier\n" );
		return EXIT_FAILURE;
	}

	while ( ( c = fgetc( file ) ) != EOF )
	{
		putchar( c );
	}

	fclose( file );

	return EXIT_SUCCESS;
}
