#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long factorielle( unsigned );

int main( void )
{
	unsigned a;
	int err;

	printf( "Entrez un entier: " );
	err = scanf( "%u", &a );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	if ( a > 12 )
	{
		printf( "Erreur: La factorielle de %u dépasse les limites du type\n", a );
		return EXIT_FAILURE;
	}

	printf( "La factorielle de %u est %lu\n", a, factorielle( a ) );

	return EXIT_SUCCESS;
}

unsigned long factorielle( unsigned a )
{
	unsigned long resultat = 1;
	unsigned i;

	for ( i = 1; i <= a; ++i )
	{
		resultat *= i;
	}

	return resultat;
}
