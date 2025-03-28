#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice17.txt"

int main( void )
{
	FILE* file = NULL;
	char word[100];
	int numWords = 0;

	file = fopen( FILENAME, "r" );
	if ( file == NULL )
	{
		printf( "Error while opening the file %s\n", FILENAME );
		return EXIT_FAILURE;
	}

	while ( fscanf( file, "%s", word ) != EOF )
	{
		++numWords;

		if ( numWords == 3 )
		{
			printf( "%s\n", word );
		}
	}

	return EXIT_SUCCESS;
}
