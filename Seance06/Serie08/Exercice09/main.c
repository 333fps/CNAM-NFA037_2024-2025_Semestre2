#include <stdio.h>

void Affiche( double* tableau, int taille );

int main( void )
{
	double tableau[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

	Affiche( tableau, 5 );

	return 0;
}

void Affiche( double* tableau, int taille )
{
	int i;
	for ( i = 0; i < taille; ++i )
	{
		printf( "%f\n", *( tableau + i ) );
	}
}
