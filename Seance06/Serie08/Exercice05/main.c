#include <stdio.h>
#include <stdlib.h>

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
		return EXIT_FAILURE;
	}

	printf( "Entrez un deuxième entier: " );
	err = scanf( "%d", &b );
	if ( err != 1 )
	{
		printf( "Erreur de lecture\n" );
		return EXIT_FAILURE;
	}

	printf( "Somme: %d\n", Somme( &a, &b ) );

	return EXIT_SUCCESS;
}

int Somme( int* a, int* b )
{
	return *a + *b;
}
