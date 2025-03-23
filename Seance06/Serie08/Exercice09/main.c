#include <stdio.h>
#include <stdlib.h>

void Affiche( double* tableau, int taille );

int main( void )
{
	double tableau[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

	Affiche( tableau, 5 );

	return EXIT_SUCCESS;
}

void Affiche( double* tableau, int taille )
{
	int i;
	for ( i = 0; i < taille; ++i )
	{
		printf( "%f\n", *( tableau + i ) );
	}
}
