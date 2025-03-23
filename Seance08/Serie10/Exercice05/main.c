#include <stdio.h>

int main( void )
{
	int T[5];
	int i;
	FILE* fichier = NULL;

	for ( i = 0; i < 5; ++i )
	{
		printf( "Veuillez saisir un entier: " );
		(void)scanf( "%d", &T[i] );
	}

	fichier = fopen( "Exercice05.txt", "a" );
	if ( fichier != NULL )
	{
		for ( i = 0; i < 5; ++i )
		{
			fprintf( fichier, "%d\n", T[i] );
		}

		fclose( fichier );
	}
	else
	{
		printf( "Ouverture impossible" );
	}

	return 0;
}
