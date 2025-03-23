#include <stdio.h>

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
		return 1;
	}

	printf( "Le %d-ième nombre pair est %d\n", x, n_iemeNbPair( x ) );

	return 0;
}

int n_iemeNbPair( int n )
{
	if ( n == 1 )
	{
		return 0;
	}
	else
	{
		return 2 + n_iemeNbPair( n - 1 );
	}
}
