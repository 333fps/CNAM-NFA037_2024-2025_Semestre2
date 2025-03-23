#include <stdio.h>
#include <stdlib.h>

int padovan( int n );

int main( void )
{
	int n;
	int err;

	printf( "Entrez le nombre de termes à afficher: " );
	err = scanf( "%d", &n );
	if ( err != 1 || n <= 0 )
	{
		printf( "Erreur: nombre invalide\n" );
		return EXIT_FAILURE;
	}

	printf( "Suite de Padovan (%d termes): ", n );

	{
		int i;
		for ( i = 0; i < n; i++ )
		{
			printf( "%d", padovan( i ) );
			if ( i < n - 1 )
			{
				printf( ", " );
			}
		}
	}

	return EXIT_SUCCESS;
}

int padovan( int n )
{
	if ( n == 0 || n == 1 || n == 2 )
	{
		return EXIT_FAILURE;
	}

	return padovan( n - 2 ) + padovan( n - 3 );
}
