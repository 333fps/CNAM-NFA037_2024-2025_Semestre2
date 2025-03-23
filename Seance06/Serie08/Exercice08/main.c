#include <stdio.h>
#include <stdlib.h>

void maFonction( int* x );

int main( void )
{
	int x = 10;
	int* p = &x;

	printf( "Adresse de x: %p\n", (void*)p );
	printf( "Avant: x = %d\n", x );
	maFonction( p );
	printf( "Après: x = %d\n", x );

	return EXIT_SUCCESS;
}

void maFonction( int* x )
{
	*x = 5;
}
