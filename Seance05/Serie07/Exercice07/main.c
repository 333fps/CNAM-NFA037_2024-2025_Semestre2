#include <stdio.h>
#include <stdlib.h>

int n_iemeNbPair( int n );

int main( void )
{
	int x;
	int err;

	printf( "Entrez un entier: " );
	err = scanf( "%d", &x );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Le %d-ième nombre pair est %d\n", x, n_iemeNbPair( x ) );

	return EXIT_SUCCESS;
}

int n_iemeNbPair( int n )
{
	if ( n == 1 )
	{
		return EXIT_SUCCESS;
	}
	else
	{
		return 2 + n_iemeNbPair( n - 1 );
	}
}
