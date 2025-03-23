#include <stdio.h>
#include <stdlib.h>

static int a, b;

int Somme( void );

int main( void )
{
	printf( "Valeur de a ? \n " );
	(void)scanf( "%d", &a );
	printf( "Valeur de b ? \n " );
	(void)scanf( "%d", &b );
	printf( "La somme : %d\n ", Somme() );
	printf( "Valeur de a : %d\n ", a );
	printf( "Valeur de b : %d\n ", b );

	return EXIT_SUCCESS;
}

int Somme( void )
{
	return ( --a + b-- );
}

/*
	110
	9 100
*/
