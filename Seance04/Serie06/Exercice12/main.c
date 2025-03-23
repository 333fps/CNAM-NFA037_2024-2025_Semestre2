#include <stdio.h>
#include <stdlib.h>

int EstPremier( int n );

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

	( EstPremier( i ) ) ? printf( "L'entier est premier\n" ) : printf( "L'entier n'est pas premier\n" );

	return EXIT_SUCCESS;
}

int EstPremier( int n )
{
	int i;

	if ( n < 2 )
	{
		return EXIT_SUCCESS;
	}

	for ( i = 2; i < n; ++i )
	{
		if ( n % i == 0 )
		{
			return EXIT_SUCCESS;
		}
	}

	return EXIT_FAILURE;
}
