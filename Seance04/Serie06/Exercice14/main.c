#include <stdio.h>
#include <stdlib.h>

void Somme( int a, int b );

int main( void )
{
	int a, b;
	printf( "Valeur de a ?\n" );
	(void)scanf( "%d", &a );
	printf( "Valeur de b ?\n" );
	(void)scanf( "%d", &b );
	Somme( a, b );
	printf( "Dans le main : \t" );
	printf( "%d\t", a );
	printf( "%d\n", b );
	return EXIT_SUCCESS;
}

void Somme( int a, int b )
{
	a--;
	b++;
	printf( "Dans la fonction Somme : \t " );
	printf( "%d\t", a );
	printf( "%d\n", b );
}

/*
	9  101
	10 100
*/
