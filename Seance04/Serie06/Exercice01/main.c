#include <stdio.h>
#include <stdlib.h>

int produit( int, int, int );

int main( void )
{
	int a, b, c;
	int err;

	printf( "Saisir le premier entier a: " );
	err = scanf( "%d", &a );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Saisir le deuxième entier b: " );
	err = scanf( "%d", &b );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Saisir le troisième entier c: " );
	err = scanf( "%d", &c );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Le produit de %d, %d et %d est %d\n", a, b, c, produit( a, b, c ) );

	return EXIT_SUCCESS;
}

int produit( int a, int b, int c )
{
	return a * b * c;
}
