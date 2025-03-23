#include <stdio.h>
#include <stdlib.h>

int puissance( int x, int y );

int main( void )
{
	int x;
	int y;
	int err;

	printf( "Entrez un premier entier: " );
	err = scanf( "%d", &x );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Entrez un deuxième entier: " );
	err = scanf( "%d", &y );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "%d à la puissance %d vaut: %d  \n", x, y, puissance( x, y ) );

	return EXIT_SUCCESS;
}

int puissance( int x, int y )
{
	if ( y == 0 )
	{
		return EXIT_FAILURE;
	}
	else
	{
		return ( x * puissance( x, y - 1 ) );
	}
}
