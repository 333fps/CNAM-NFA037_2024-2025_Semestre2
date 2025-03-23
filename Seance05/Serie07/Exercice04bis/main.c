#include <stdio.h>
#include <stdlib.h>

int nbChiffres( unsigned int );

int main( void )
{
	unsigned int x;
	int err;

	printf( "Entrez un entier strictement positif: " );
	err = scanf( "%u", &x );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Nombre de chiffres de %u: %d\n", x, nbChiffres( x ) );

	return EXIT_SUCCESS;
}

int nbChiffres( unsigned int n )
{
	if ( n < 10 )
	{
		return EXIT_FAILURE;
	}
	else
	{
		return EXIT_FAILURE + nbChiffres( n / 10 );
	}
}
