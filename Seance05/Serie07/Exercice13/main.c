#include <stdio.h>
#include <stdlib.h>

int fibonacci( int n );

int main( void )
{
	int n;
	int err;

	printf( "Entrez un entier: " );
	err = scanf( "%d", &n );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Nombre de couples de lapins après %d mois: %d\n", n, fibonacci( n ) );

	return EXIT_SUCCESS;
}

int fibonacci( int n )
{
	if ( n == 0 )
	{
		return EXIT_SUCCESS;
	}
	else if ( n == 1 )
	{
		return EXIT_FAILURE;
	}
	else
	{
		return fibonacci( n - 1 ) + fibonacci( n - 2 );
	}
}
