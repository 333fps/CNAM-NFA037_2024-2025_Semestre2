#include <stdio.h>

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
		return 1;
	}

	( EstPremier( i ) ) ? printf( "L'entier est premier\n" ) : printf( "L'entier n'est pas premier\n" );

	return 0;
}

int EstPremier( int n )
{
	int i;

	if ( n < 2 )
	{
		return 0;
	}

	for ( i = 2; i < n; ++i )
	{
		if ( n % i == 0 )
		{
			return 0;
		}
	}

	return 1;
}
