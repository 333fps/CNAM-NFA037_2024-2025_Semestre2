#include <stdio.h>
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
		return 1;
	}

	if ( a > 12 )
	{
		printf( "Erreur: La factorielle de %u dépasse les limites du type\n", a );
		return 1;
	}

	printf( "La factorielle de %u est %lu\n", a, factorielle( a ) );

	return 0;
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
