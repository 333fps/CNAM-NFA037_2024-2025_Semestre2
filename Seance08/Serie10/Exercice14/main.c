#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice14.txt"

int main( void )
{
	FILE* file = NULL;
	int c;
	int wordCount = 0;
	int inWord = 0;

	file = fopen( FILENAME, "r" );
	if ( file == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s.\n", FILENAME );

		return EXIT_FAILURE;
	}

	while ( ( c = fgetc( file ) ) != EOF )
	{
		int separator = 0;
		if ( c == ' ' || c == '\t' || c == '\n' )
		{
			separator = 1;
		}
		else
		{
			switch ( c )
			{
				case '.':
				case ',':
				case ';':
				case ':':
				case '!':
				case '?':
				case '"':
				case '\'':
				case '(':
				case ')':
				case '[':
				case ']':
				case '{':
				case '}':
				case '-':
				case '_':
				case '/':
				case '\\':
					separator = 1;
					break;
				default:
					separator = 0;
					break;
			}
		}

		if ( separator == 1 )
		{
			inWord = 0;
		}
		else if ( inWord == 0 )
		{
			inWord = 1;
			wordCount++;
		}
	}

	printf( "Le fichier %s contient %d mot(s).\n", FILENAME, wordCount );

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
