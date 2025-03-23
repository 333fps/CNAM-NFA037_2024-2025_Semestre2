#include <stdio.h>

int main( void )
{
	int entier;
	float reel;

	entier = 8;
	reel = 10.5f;

	printf( "La valeur de l'entier est %d, la valeur du nombre réel est %f\n", entier, (double)reel );

	return 0;
}
