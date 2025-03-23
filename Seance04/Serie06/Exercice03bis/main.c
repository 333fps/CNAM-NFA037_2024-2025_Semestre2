#include <stdio.h>
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
		return 1;
	}

	printf( "Entrez le second réel b: " );
	err = scanf( "%d", &b );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Le modulo de %d/%d est %d\n", a, b, modulo( a, b ) );

	return 0;
}

int modulo( int a, int b )
{
	if ( b == 0 )
	{
		printf( "Erreur: Division par zéro\n" );
		return 0;
	}

	return a - b * ( a / b );
}
