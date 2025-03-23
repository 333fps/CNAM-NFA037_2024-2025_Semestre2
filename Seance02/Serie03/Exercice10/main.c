#include <stdio.h>
#include <math.h>

int main( void )
{
	int entier1;
	int entier2;
	int err;

	printf( "Entrez un premier entier : " );
	err = scanf( "%d", &entier1 );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Entrez un second entier : " );
	err = scanf( "%d", &entier2 );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	if ( entier1 > entier2 )
	{
		double carre = pow( entier1, 2 );

		printf( "La carré du premier entier est %d:\n", (int)carre );
	}
	else
	{
		double cube = pow( entier2, 3 );

		printf( "Le cube du deuxième entier est %d:\n", (int)cube );
	}

	return 0;
}
