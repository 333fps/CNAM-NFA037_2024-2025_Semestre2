#include <stdio.h>

int main( void )
{
	int entier;
	int i;
	FILE* fichier = NULL;

	fichier = fopen( "Exercice04.txt", "a" );
	if ( fichier != NULL )
	{
		for ( i = 0; i < 5; ++i )
		{
			printf( "Veuillez saisir un entier: " );
			(void)scanf( "%d", &entier );
			fprintf( fichier, "%d ", entier );
		}

		fclose( fichier );
	}
	else
	{
		printf( "Ouverture impossible" );
	}

	return 0;
}
