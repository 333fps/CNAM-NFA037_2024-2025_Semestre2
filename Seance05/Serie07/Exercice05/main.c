#include <stdio.h>
#include <stdlib.h>

unsigned long Suite( unsigned long n );

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

	printf( "Suite de %lu: %lu\n", x, Suite( x ) );

	return EXIT_SUCCESS;
}

unsigned long Suite( unsigned long n )
{
	if ( n == 1 )
	{
		return EXIT_FAILURE;
	}
	else
	{
		return 2 * Suite( n - 1 ) + 3;
	}
}
