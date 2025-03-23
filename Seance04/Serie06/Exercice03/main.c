#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

float puissance( int, int );

int main( void )
{
	int a, b;
	int err;

	printf( "Saisir le premier entier a: " );
	err = scanf( "%d", &a );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Saisir le deuxième entier b: " );
	err = scanf( "%d", &b );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Le résultat de %d puissance %d est %f\n", a, b, (double)puissance( a, b ) );

	return EXIT_SUCCESS;
}

float puissance( int a, int b )
{
	float resultat = 1.0f;
	int i;
	int abs_b;

	if ( a == 0 && b < 0 )
	{
		printf( "Erreur: Division par zéro (0^%d)\n", b );
		return .0f;
	}

	if ( a == 0 && b == 0 )
	{
		printf( "Erreur: 0^0 n'est pas défini\n" );
		return .0f;
	}

	abs_b = ( b < 0 ) ? -b : b;
	for ( i = 0; i < abs_b; ++i )
	{
		resultat *= (float)a;
	}

	if ( b < 0 )
	{
		if ( resultat == 0.0f )
		{
			printf( "Erreur: Division par zéro\n" );
			return .0f;
		}
		resultat = 1.0f / resultat;
	}

	return resultat;
}
