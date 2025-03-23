#include <stdio.h>
#include <stdlib.h>

void Moyenne( int T[], int n );

int main( void )
{
	int i;
	int err;
	int T[5];

	for ( i = 0; i < 5; ++i )
	{
		printf( "Entrez un entier: " );
		err = scanf( "%d", &T[i] );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}
	}

	Moyenne( T, 5 );

	return EXIT_SUCCESS;
}

void Moyenne( int T[], int n )
{
	int i;
	float somme = 0;

	for ( i = 0; i < n; ++i )
	{
		somme += (float)T[i];
	}

	printf( "La moyenne est %f\n", (double)somme / (double)n );
}
