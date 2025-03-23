#include <stdio.h>
#include <string.h>

#define FILENAME "Exercice12.txt"

int main( void )
{
	int numChar = 0;
	FILE* file = NULL;

	file = fopen( FILENAME, "r" );
	if ( !file )
	{
		printf( "Impossible d'ouvir le fichier %s.\n", FILENAME );

		return 1;
	}

	while ( !feof( file ) )
	{
		fgetc( file );
		++numChar;
	}

	numChar -= 1;

	printf( "Le fichier contient %d caractères", numChar );

	fclose( file );

	return 0;
}
