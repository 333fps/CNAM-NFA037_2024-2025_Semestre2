#include <stdio.h>

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
		return 1;
	}

	printf( "Nombre de chiffres de %u: %d\n", x, nbChiffres( x ) );

	return 0;
}

int nbChiffres( unsigned int n )
{
	if ( n < 10 )
	{
		return 1;
	}
	else
	{
		return 1 + nbChiffres( n / 10 );
	}
}
