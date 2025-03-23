#include <stdio.h>
#include <stdlib.h>

void Affiche( float T[], int n );

int main( void )
{
	int i;
	int err;
	float T[5];

	for ( i = 0; i < 5; ++i )
	{
		printf( "Entrez un réel: " );
		err = scanf( "%f", &T[i] );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}
	}

	Affiche( T, 5 );

	return EXIT_SUCCESS;
}

void Affiche( float T[], int n )
{
	int i;
	for ( i = 0; i < n; ++i )
	{
		printf( "%f\n", (double)T[i] );
	}
}
