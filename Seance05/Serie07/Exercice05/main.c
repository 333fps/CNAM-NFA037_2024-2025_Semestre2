#include <stdio.h>

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
		return 1;
	}

	printf( "Suite de %lu: %lu\n", x, Suite( x ) );

	return 0;
}

unsigned long Suite( unsigned long n )
{
	if ( n == 1 )
	{
		return 1;
	}
	else
	{
		return 2 * Suite( n - 1 ) + 3;
	}
}
