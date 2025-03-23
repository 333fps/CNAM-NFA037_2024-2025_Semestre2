#include <stdio.h>

int produit( int x, int y );

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

	printf( "Produit de %d et %d: %d\n", x, y, produit( x, y ) );

	return 0;
}

int produit( int x, int y )
{
	if ( y == 0 )
	{
		return 0;
	}
	else
	{
		return ( x + produit( x, y - 1 ) );
	}
}
