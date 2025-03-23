#include <stdio.h>

int main( void )
{
	FILE* fichier = NULL;

	fichier = fopen( "Exercice03.txt", "a" );
	if ( fichier != NULL )
	{
		fputc( '1', fichier );
		fputs( "\n", fichier );
		fputc( '2', fichier );
		fclose( fichier );
	}
	else
	{
		printf( "Ouverture impossible" );
	}

	return 0;
}
