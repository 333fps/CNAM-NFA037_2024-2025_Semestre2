#include <stdio.h>

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
		return 1;
	}

	printf( "Somme des %lu premiers entiers: %lu\n", x, Somme( x ) );

	return 0;
}

unsigned long Somme( unsigned long n )
{
	if ( n == 0 )
		return 0;
	else
		return ( n - 1 ) + Somme( n - 1 );
}
