#include <stdio.h>

int syracuse( int n );

int main( void )
{
	int n;
	int err;

	printf( "Entrez un entier: " );
	err = scanf( "%d", &n );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Suite de Syracuse pour %d: ", n );
	(void)syracuse( n );

	return 0;
}

int syracuse( int n )
{
	if ( n == 1 )
	{
		printf( "1\n" );
		return 1;
	}
	else
	{
		printf( "%d ", n );
		if ( n % 2 == 0 )
		{
			return syracuse( n / 2 );
		}
		else
		{
			return syracuse( 3 * n + 1 );
		}
	}
}
