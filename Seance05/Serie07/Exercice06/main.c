#include <stdio.h>
#include <stdlib.h>

unsigned long Somme( unsigned long n );

int main( void )
{
	unsigned long x;
	int err;

	printf( "Entrez un entier: " );
	err = scanf( "%lu", &x );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Somme des %lu premiers entiers: %lu\n", x, Somme( x ) );

	return EXIT_SUCCESS;
}

unsigned long Somme( unsigned long n )
{
	if ( n == 0 )
		return EXIT_SUCCESS;
	else
		return ( n - 1 ) + Somme( n - 1 );
}
