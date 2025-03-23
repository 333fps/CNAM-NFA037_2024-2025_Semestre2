#include <stdio.h>

void Swap( int*, int* );

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

	printf( "Avant: a = %d, b = %d\n", a, b );
	Swap( &a, &b );
	printf( "Après: a = %d, b = %d\n", a, b );

	return 0;
}

void Swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
