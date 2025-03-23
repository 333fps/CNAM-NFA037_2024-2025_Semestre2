#include <stdio.h>

unsigned sommeChiffres( unsigned int );

int main( void )
{
	unsigned int x;
	int err;

	printf( "Entrez un entier strictement positif: " );
	err = scanf( "%u", &x );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Somme des chiffres de %u: %u\n", x, sommeChiffres( x ) );

	return 0;
}

unsigned sommeChiffres( unsigned n )
{
	if ( n < 10 )
	{
		return n;
	}
	else
	{
		return n % 10 + sommeChiffres( n / 10 );
	}
}
