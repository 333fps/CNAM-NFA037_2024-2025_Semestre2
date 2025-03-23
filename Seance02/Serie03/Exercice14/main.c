#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( void )
{
	double a, b, c;
	double delta;
	int err;

	printf( "Entrez le nombre a: " );
	err = scanf( "%lf", &a );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Entrez le nombre b: " );
	err = scanf( "%lf", &b );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Entrez le nombre c: " );
	err = scanf( "%lf", &c );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	if ( a == 0. )
	{
		if ( b == 0. )
		{
			if ( c == 0. )
			{
				printf( "L'équation est indeterminée (infinité de solutions)\n" );
			}
			else
			{
				printf( "L'équation est impossible\n" );
			}
		}
		else
		{
			printf( "L'équation est du premier degré (bx + c = 0 )\n" );
			printf( "Solution : x = %f\n", -c / b );
		}
	}
	else
	{
		delta = pow( b, 2 ) - 4 * a * c;
		printf( "Delta = %f\n", delta );

		if ( delta < 0. )
		{
			printf( "Il y a deux solutions complexes\n" );
		}
		else if ( delta == 0. )
		{
			printf( "Il y a une solution double réelle : %f\n", -b / ( 2 * a ) );
		}
		else
		{
			printf( "Il y a deux solutions réelles :\n" );
			printf( "x1 = %f\n", ( -b - sqrt( delta ) ) / ( 2 * a ) );
			printf( "x2 = %f\n", ( -b + sqrt( delta ) ) / ( 2 * a ) );
		}
	}

	return EXIT_SUCCESS;
}
