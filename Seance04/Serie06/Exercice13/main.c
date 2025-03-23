#include <stdio.h>

static int a, b;

void Somme( void );

int main( void )
{
	printf( "Valeur de a ?\n" );
	(void)scanf( "%d", &a );
	printf( "Valeur de b ?\n" );
	(void)scanf( "%d", &b );
	Somme();
	printf( "Dans le main : \t" );
	printf( "%d\t", a );
	printf( "%d\n", b );
	return 0;
}

void Somme( void )
{
	a--;
	b++;
	printf( "Dans la fonction Somme : \t " );
	printf( "%d\t", a );
	printf( "%d\n", b );
}

/*
	9 101
	9 101
*/
