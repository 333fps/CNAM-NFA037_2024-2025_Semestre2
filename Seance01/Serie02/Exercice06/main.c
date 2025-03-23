#include <stdio.h>

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
		return 1;
	}

	result = 3 * x * x - 1;

	printf( "Le resultat est %f\n", (double)result );

	return 0;
}
