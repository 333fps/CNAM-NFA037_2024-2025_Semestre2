#include <stdio.h>

int main( void )
{
	int T[5];
	int i;
	FILE* fichier = NULL;
	float moyenne;

	for ( i = 0; i < 5; ++i )
	{
		printf( "Veuillez saisir un entier: " );
		(void)scanf( "%d", &T[i] );
	}

	fichier = fopen( "Exercice06.txt", "a" );
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

	moyenne = 0.f;
	for ( i = 0; i < 5; ++i )
	{
		moyenne += (float)T[i];
	}
	moyenne /= 5;

	fichier = fopen( "Exercice06.txt", "a" );
	if ( fichier != NULL )
	{
		fprintf( fichier, "Moyenne: %f\n", (double)moyenne );
		fclose( fichier );
	}
	else
	{
		printf( "Ouverture impossible" );
	}

	return 0;
}
