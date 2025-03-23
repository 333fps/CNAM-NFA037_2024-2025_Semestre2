#include <stdio.h>

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
		return 1;
	}

	printf( "Entrez un deuxième entier: " );
	err = scanf( "%d", &y );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "%d à la puissance %d vaut: %d  \n", x, y, puissance( x, y ) );

	return 0;
}

int puissance( int x, int y )
{
	if ( y == 0 )
	{
		return 1;
	}
	else
	{
		return ( x * puissance( x, y - 1 ) );
	}
}
