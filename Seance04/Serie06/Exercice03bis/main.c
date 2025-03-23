#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int modulo( int, int );

int main( void )
{
	int a, b;
	int err;

	printf( "Entrez le premier réel a: " );
	err = scanf( "%d", &a );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Entrez le second réel b: " );
	err = scanf( "%d", &b );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Le modulo de %d/%d est %d\n", a, b, modulo( a, b ) );

	return EXIT_SUCCESS;
}

int modulo( int a, int b )
{
	if ( b == 0 )
	{
		printf( "Erreur: Division par zéro\n" );
		return EXIT_SUCCESS;
	}

	return a - b * ( a / b );
}
