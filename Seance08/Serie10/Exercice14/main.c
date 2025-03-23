#include <stdio.h>

#define FILENAME "Exercice14.txt"

int main( void )
{
	FILE* fichier = NULL;
	int c;
	int nombreMots = 0;
	int dansUnMot = 0;

	fichier = fopen( FILENAME, "r" );
	if ( fichier == NULL )
	{
		printf( "Impossible d'ouvrir le fichier %s.\n", FILENAME );

		return 1;
	}

	while ( ( c = fgetc( fichier ) ) != EOF )
	{
		if ( c == ' ' )
		{
			dansUnMot = 0;
		}
		else if ( dansUnMot == 0 )
		{
			dansUnMot = 1;
			nombreMots++;
		}
	}

	printf( "\nLe fichier contient %d mot(s).\n", nombreMots );

	fclose( fichier );

	return 0;
}
