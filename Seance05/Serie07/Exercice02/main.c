#include <stdio.h>
#include <stdlib.h>

unsigned long Facto( int );

int main( void )
{
	int i;
	int err;

	printf( "Entrez un entier: " );
	err = scanf( "%d", &i );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Factorielle de %d: %lu\n", i, Facto( i ) );

	return EXIT_SUCCESS;
}

unsigned long Facto( int n )
{
	return n > 1 ? (unsigned long)n * Facto( n - 1 ) : 1;
}
