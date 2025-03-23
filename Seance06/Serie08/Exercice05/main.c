#include <stdio.h>

int Somme( int*, int* );

int main( void )
{
	int a, b;
	int err;

	printf( "Entrez un premier entier: " );
	err = scanf( "%d", &a );
	if ( err != 1 )
	{
		printf( "Erreur de lecture\n" );
		return 1;
	}

	printf( "Entrez un deuxième entier: " );
	err = scanf( "%d", &b );
	if ( err != 1 )
	{
		printf( "Erreur de lecture\n" );
		return 1;
	}

	printf( "Somme: %d\n", Somme( &a, &b ) );

	return 0;
}

int Somme( int* a, int* b )
{
	return *a + *b;
}
