#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	float x;
	float result;
	int err;

	printf( "Entrez un nombre reel\n" );

	err = scanf( "%f", &x );
	if ( err != 1 )
	{
		printf( "Erreur de lecture\n" );
		return EXIT_FAILURE;
	}

	result = 3 * x * x - 1;

	printf( "Le resultat est %f\n", (double)result );

	return EXIT_SUCCESS;
}
