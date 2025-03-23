#include <stdio.h>

int main( void )
{
	int Alpha = 500;
	int* P = &Alpha;

	int** P1 = &P;

	printf( "Contenu de Alpha en utilisant P: %d\n", *P );
	printf( "Contenu de Alpha en utilisant P1: %d\n", **P1 );

	return 0;
}
