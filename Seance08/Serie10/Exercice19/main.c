#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Exercice19.txt"

int main( void )
{
	FILE* fichier = NULL;
	int c;
	int nombrePhrases = 0;
	int ponctuation = 0;

	fichier = fopen( FILENAME, "r" );
	if ( fichier == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s.\n", FILENAME );
		return EXIT_FAILURE;
	}

	while ( ( c = fgetc( fichier ) ) != EOF )
	{
		putchar( c );

		if ( c == '.' || c == '!' || c == '?' )
		{
			if ( !ponctuation )
			{
				nombrePhrases++;
				ponctuation = 1;
			}
		}
		else
		{
			ponctuation = 0;
		}
	}

	fclose( fichier );

	printf( "\n\nLe fichier contient %d phrase(s).\n", nombrePhrases );

	return EXIT_SUCCESS;
}
